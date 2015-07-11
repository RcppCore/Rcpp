// Copyright (C) 2013 Romain Francois
//
// This file is part of Rcpp.
//
// Rcpp is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// Rcpp is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Rcpp.  If not, see <http://www.gnu.org/licenses/>.

#ifndef Rcpp_api_meat_Rcpp_eval_h
#define Rcpp_api_meat_Rcpp_eval_h

#include <Rcpp/Interrupt.h>

namespace Rcpp {

namespace internal {

#define RCPP_FRAME_LOCK_MASK (1<<14)
#define RCPP_FRAME_IS_LOCKED(e) (ENVFLAGS(e) & RCPP_FRAME_LOCK_MASK)
#define RCPP_LOCK_FRAME(e) SET_ENVFLAGS(e, ENVFLAGS(e) | RCPP_FRAME_LOCK_MASK)
#define RCPP_UNLOCK_FRAME(e) SET_ENVFLAGS(e, ENVFLAGS(e) & (~ RCPP_FRAME_LOCK_MASK))

class UnlockFrameScope {
public:
    
    UnlockFrameScope(const std::string& name) {
        Shield<SEXP> nameSEXP(::Rf_mkString(name.c_str()));
        ns_ = ::R_FindNamespace(nameSEXP);
        if (ns_ && TYPEOF(ns_) == ENVSXP)
            RCPP_UNLOCK_FRAME(ns_);
    }
    
    ~UnlockFrameScope() {
        if (ns_ && TYPEOF(ns_) == ENVSXP) {
            RCPP_LOCK_FRAME(ns_);
        }
    }
    
private:
    
    SEXP ns_;
    
};

inline bool inject(const std::string& functionName,
                   const std::string& namespaceName,
                   const std::string& functionDefn)
{
    UnlockFrameScope rcppScope(namespaceName);
    
    std::string code = std::string() +
        "ns <- asNamespace('" + namespaceName + "')\n" +
        "if (!exists('" + functionName + "', envir = ns)) {\n" +
        "    ..rcpp.temporary.variable.. <- " + functionDefn + "\n" +
        "    environment(..rcpp.temporary.variable..) <- ns\n" +
        "    assign('" + functionName + "', envir = ns, ..rcpp.temporary.variable..)\n" +
        "    rm(..rcpp.temporary.variable..)\n" +
        "}";
    
    Shield<SEXP> codeSEXP(::Rf_mkString(code.c_str()));
    
    ParseStatus ps;
    Shield<SEXP> parsedSEXP(::R_ParseVector(codeSEXP, -1, &ps, R_NilValue));
    if (ps != PARSE_OK)
        return false;
    
    R_xlen_t n = ::Rf_length(parsedSEXP);
    for (R_xlen_t i = 0; i < n; ++i) {
        int status;
        ::R_tryEval(VECTOR_ELT(parsedSEXP, i), R_GlobalEnv, &status);
        if (status != 0)
            return false;
    }
    
    return true;
}

inline bool ensureRecordersInjected() {
    
    // NOTE: It's okay if this crosses module boundaries as the evaluated code 
    // will run only if the recorders have not yet been injected; the static
    // variable just helps avoid running R code more than once per module.
    static bool injected = false;
    if (injected)
        return true;
    
    std::string messageRecorder = std::string() +
        "function(m) {\n" +
        "    .warningsEnv$messages <- append(.warningsEnv$messages, m$message)\n" +
        "    invokeRestart('muffleMessage')\n" +
        "}";
    
    if (!inject(".rcpp_message_recorder", "Rcpp", messageRecorder))
        return false;
    
    std::string messageCollector = std::string() +
        "function() {\n" +
        "    messages <- .warningsEnv$messages\n" +
        "    .warningsEnv$messages <- character()\n" +
        "    as.character(messages)\n" +
        "}";
    
    if (!inject(".rcpp_collect_messages", "Rcpp", messageCollector))
        return false;
    
    injected = true;
    return true;
}

} // namespace internal

    struct EvalCall {
        SEXP expr;
        SEXP env;
        SEXP result;
        std::vector<std::string> warnings;
        std::vector<std::string> messages;
        bool error_occurred;
        std::string error_message;
    };

    inline void Rcpp_eval(void* data) {

        EvalCall* evalCall = (EvalCall*)data;
        SEXP env = evalCall->env;

        Shield<SEXP> expr(evalCall->expr) ;

        Environment RCPP = Environment::Rcpp_namespace();
        SEXP withCallingHandlersSym    = ::Rf_install("withCallingHandlers");
        SEXP tryCatchSym               = ::Rf_install("tryCatch");
        SEXP evalqSym                  = ::Rf_install("evalq");
        SEXP conditionMessageSym       = ::Rf_install("conditionMessage");
        SEXP errorRecorderSym          = ::Rf_install(".rcpp_error_recorder");
        SEXP warningRecorderSym        = ::Rf_install(".rcpp_warning_recorder");
        SEXP collectWarningsSym        = ::Rf_install(".rcpp_collect_warnings");
        SEXP messageRecorderSym        = ::Rf_install(".rcpp_message_recorder");
        SEXP collectMessagesSym        = ::Rf_install(".rcpp_collect_messages");
        SEXP errorSym                  = ::Rf_install("error");
        SEXP warningSym                = ::Rf_install("warning");
        SEXP messageSym                = ::Rf_install("message");

        // define the tryCatchCall
        Shield<SEXP> tryCatchCall( Rf_lang3(
            tryCatchSym,
            Rf_lang3( evalqSym, expr, env ),
            errorRecorderSym
        ) ) ;
        SET_TAG( CDDR(tryCatchCall), errorSym ) ;

        // encose it in withCallingHandlers
        Shield<SEXP> call( Rf_lang4(
            withCallingHandlersSym,
            tryCatchCall,
            warningRecorderSym,
            messageRecorderSym
        ) ) ;
        SET_TAG( CDDR(call), warningSym ) ;
        SET_TAG( CDDDR(call), messageSym ) ;

        // execute the call
        Shield<SEXP> res(::Rf_eval( call, RCPP ) );

        // collect warnings
        Shield<SEXP> collectWarningsCall(Rf_lang1(collectWarningsSym));
        Shield<SEXP> warnings(::Rf_eval(collectWarningsCall, RCPP));
        
        // collect messages
        Shield<SEXP> collectMessagesCall(Rf_lang1(collectMessagesSym));
        Shield<SEXP> messages(::Rf_eval(collectMessagesCall, RCPP));
        
        evalCall->warnings = Rcpp::as<std::vector<std::string> >(warnings);
        evalCall->messages = Rcpp::as<std::vector<std::string> >(messages);

        // check for error
        if( error_occured() ) {
            Shield<SEXP> current_error        ( rcpp_get_current_error() ) ;
            Shield<SEXP> conditionMessageCall (::Rf_lang2(conditionMessageSym, current_error)) ;
            Shield<SEXP> condition_message    (::Rf_eval(conditionMessageCall, R_GlobalEnv)) ;
            evalCall->error_occurred = true;
            evalCall->error_message = std::string(CHAR(::Rf_asChar(condition_message)));
        } else {
            evalCall->error_occurred = false;
            evalCall->result = res;
        }
        
        reset_current_error() ;

    }
    
    inline void message(const std::string& msg) {
        
        Shield<SEXP> msgSEXP(Rf_mkString(msg.c_str()));
        Shield<SEXP> messageCall(Rf_lang2(
            ::Rf_install("message"),
            msgSEXP
        ));
        
        int status;
        ::R_tryEval(messageCall, R_GlobalEnv, &status);
    }

    inline SEXP Rcpp_eval(SEXP expr_, SEXP env) {
        
        internal::ensureRecordersInjected();

        // create the call object
        EvalCall call;
        call.expr = expr_;
        call.env = env;

        // execute it
        Rboolean completed = R_ToplevelExec(Rcpp_eval, (void*)&call);

        // print warnings
        for (size_t i = 0; i<call.warnings.size(); i++)
            Rf_warning(call.warnings[i].c_str());
        
        // print messages
        for (std::size_t i = 0; i < call.messages.size(); i++)
            message(call.messages[i].c_str());

        // handle error or result if it completed, else throw interrupt
        if (completed) {
            if (call.error_occurred)
                throw eval_error(call.error_message);
            else
                return call.result;
        } else {
            throw internal::InterruptedException();
        }
    }
    

}

#endif
