// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
// jedit: :folding=explicit:
//
// Date.cpp: Rcpp R/C++ interface class library -- Date type
//
// Copyright (C) 2010 - 2013  Dirk Eddelbuettel and Romain Francois
//
//    The mktime00() as well as the gmtime_() replacement function are
//    Copyright (C) 2000 - 2010  The R Development Core Team.
// 
//    gmtime_() etc are from the public domain timezone code dated 
//    1996-06-05 by Arthur David Olson.
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

#define COMPILING_RCPP

#include <Rcpp.h>
#include <time.h>		// for gmtime
#include <Rcpp/exceptions.h>

namespace Rcpp {

    // Taken from R's src/main/datetime.c and made a member function called with C++ reference
    /* Substitute for mktime -- no checking, always in GMT */
    
    // [[Rcpp::register]]
    double mktime00(struct tm &tm) {

        static const int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        #define isleap(y) ((((y) % 4) == 0 && ((y) % 100) != 0) || ((y) % 400) == 0)
        #define days_in_year(year) (isleap(year) ? 366 : 365)
        
        int day = 0;
        int i, year, year0;
        double excess = 0.0;
        
        day = tm.tm_mday - 1;
        year0 = Date::baseYear() + tm.tm_year;
        /* safety check for unbounded loops */
        if (year0 > 3000) {
            excess = (int)(year0/2000) - 1;
            year0 -= excess * 2000;
        } else if (year0 < 0) {
            excess = -1 - (int)(-year0/2000);
            year0 -= excess * 2000;
        }
        
        for(i = 0; i < tm.tm_mon; i++) day += days_in_month[i];
        if (tm.tm_mon > 1 && isleap(year0)) day++;
        tm.tm_yday = day;
        
        if (year0 > 1970) {
            for (year = 1970; year < year0; year++)
                day += days_in_year(year);
        } else if (year0 < 1970) {
            for (year = 1969; year >= year0; year--)
                day -= days_in_year(year);
        }
        
        /* weekday: Epoch day was a Thursday */
        if ((tm.tm_wday = (day + 4) % 7) < 0) tm.tm_wday += 7;
        
        return tm.tm_sec + (tm.tm_min * 60) + (tm.tm_hour * 3600)
            + (day + excess * 730485) * 86400.0;
    }
    
    #undef isleap
    #undef days_in_year 

#include "sys/types.h"	/* for time_t */
#include "string.h"
#include "limits.h"	/* for CHAR_BIT et al. */

#define  _NO_OLDNAMES   /* avoid tznames */
#include "time.h"
#undef _NO_OLDNAMES

#include <errno.h>
#ifndef EOVERFLOW
# define EOVERFLOW 79
#endif

#include "stdlib.h"
#include "stdint.h"
#include "stdio.h"
#include "fcntl.h"
#include "float.h"	/* for FLT_MAX and DBL_MAX */

#include <unistd.h>		// solaris needs this for read() and close()


/* merged from private.h */
#define TYPE_BIT(type)	(sizeof (type) * CHAR_BIT)
#define TYPE_SIGNED(type) (((type) -1) < 0)
#define TYPE_INTEGRAL(type) (((type) 0.5) != 0.5)
#define GRANDPARENTED	"Local time zone must be set--see zic manual page"
#define YEARSPERREPEAT	 400	/* years before a Gregorian repeat */
#define AVGSECSPERYEAR	 31556952L
#define SECSPERREPEAT ((int_fast64_t) YEARSPERREPEAT * (int_fast64_t) AVGSECSPERYEAR)
#define SECSPERREPEAT_BITS  34	/* ceil(log2(SECSPERREPEAT)) */
#define is_digit(c) ((unsigned)(c) - '0' <= 9)
#define INITIALIZE(x) (x = 0)

    //#include "tzfile.h"
    // BEGIN ------------------------------------------------------------------------------------------ tzfile.h
#ifndef TZFILE_H

#define TZFILE_H

/*
** This file is in the public domain, so clarified as of
** 1996-06-05 by Arthur David Olson.
*/

/*
** This header is for use ONLY with the time conversion code.
** There is no guarantee that it will remain unchanged,
** or that it will remain at all.
** Do NOT copy it to any system include directory.
** Thank you!
*/

/*
** Information about time zone files.
*/

#ifndef TZDIR
#define TZDIR	"/usr/local/etc/zoneinfo" /* Time zone object file directory */
#endif /* !defined TZDIR */

#ifndef TZDEFAULT
#define TZDEFAULT	"localtime"
#endif /* !defined TZDEFAULT */

#ifndef TZDEFRULES
#define TZDEFRULES	"America/New_York"
#endif /* !defined TZDEFRULES */

/*
** Each file begins with. . .
*/

#define	TZ_MAGIC	"TZif"

struct tzhead {
	char	tzh_magic[4];		/* TZ_MAGIC */
	char	tzh_version[1];		/* '\0' or '2' as of 2005 */
	char	tzh_reserved[15];	/* reserved--must be zero */
	char	tzh_ttisgmtcnt[4];	/* coded number of trans. time flags */
	char	tzh_ttisstdcnt[4];	/* coded number of trans. time flags */
	char	tzh_leapcnt[4];		/* coded number of leap seconds */
	char	tzh_timecnt[4];		/* coded number of transition times */
	char	tzh_typecnt[4];		/* coded number of local time types */
	char	tzh_charcnt[4];		/* coded number of abbr. chars */
};

/*
** . . .followed by. . .
**
**	tzh_timecnt (char [4])s		coded transition times a la time(2)
**	tzh_timecnt (unsigned char)s	types of local time starting at above
**	tzh_typecnt repetitions of
**		one (char [4])		coded UTC offset in seconds
**		one (unsigned char)	used to set tm_isdst
**		one (unsigned char)	that's an abbreviation list index
**	tzh_charcnt (char)s		'\0'-terminated zone abbreviations
**	tzh_leapcnt repetitions of
**		one (char [4])		coded leap second transition times
**		one (char [4])		total correction after above
**	tzh_ttisstdcnt (char)s		indexed by type; if TRUE, transition
**					time is standard time, if FALSE,
**					transition time is wall clock time
**					if absent, transition times are
**					assumed to be wall clock time
**	tzh_ttisgmtcnt (char)s		indexed by type; if TRUE, transition
**					time is UTC, if FALSE,
**					transition time is local time
**					if absent, transition times are
**					assumed to be local time
*/

/*
** If tzh_version is '2' or greater, the above is followed by a second instance
** of tzhead and a second instance of the data in which each coded transition
** time uses 8 rather than 4 chars,
** then a POSIX-TZ-environment-variable-style string for use in handling
** instants after the last transition time stored in the file
** (with nothing between the newlines if there is no POSIX representation for
** such instants).
*/

/*
** In the current implementation, "tzset()" refuses to deal with files that
** exceed any of the limits below.
*/

#ifndef TZ_MAX_TIMES
#define TZ_MAX_TIMES	1200
#endif /* !defined TZ_MAX_TIMES */

#ifndef TZ_MAX_TYPES
#ifndef NOSOLAR
#define TZ_MAX_TYPES	256 /* Limited by what (unsigned char)'s can hold */
#endif /* !defined NOSOLAR */
#ifdef NOSOLAR
/*
** Must be at least 14 for Europe/Riga as of Jan 12 1995,
** as noted by Earl Chew.
*/
#define TZ_MAX_TYPES	20	/* Maximum number of local time types */
#endif /* !defined NOSOLAR */
#endif /* !defined TZ_MAX_TYPES */

#ifndef TZ_MAX_CHARS
#define TZ_MAX_CHARS	50	/* Maximum number of abbreviation characters */
				/* (limited by what unsigned chars can hold) */
#endif /* !defined TZ_MAX_CHARS */

#ifndef TZ_MAX_LEAPS
#define TZ_MAX_LEAPS	50	/* Maximum number of leap second corrections */
#endif /* !defined TZ_MAX_LEAPS */

#define SECSPERMIN	60
#define MINSPERHOUR	60
#define HOURSPERDAY	24
#define DAYSPERWEEK	7
#define DAYSPERNYEAR	365
#define DAYSPERLYEAR	366
#define SECSPERHOUR	(SECSPERMIN * MINSPERHOUR)
#define SECSPERDAY	((long) SECSPERHOUR * HOURSPERDAY)
#define MONSPERYEAR	12

#define TM_SUNDAY	0
#define TM_MONDAY	1
#define TM_TUESDAY	2
#define TM_WEDNESDAY	3
#define TM_THURSDAY	4
#define TM_FRIDAY	5
#define TM_SATURDAY	6

#define TM_JANUARY	0
#define TM_FEBRUARY	1
#define TM_MARCH	2
#define TM_APRIL	3
#define TM_MAY		4
#define TM_JUNE		5
#define TM_JULY		6
#define TM_AUGUST	7
#define TM_SEPTEMBER	8
#define TM_OCTOBER	9
#define TM_NOVEMBER	10
#define TM_DECEMBER	11

#define EPOCH_YEAR	1970
#define EPOCH_WDAY	TM_THURSDAY

#define isleap(y) (((y) % 4) == 0 && (((y) % 100) != 0 || ((y) % 400) == 0))

/*
** Since everything in isleap is modulo 400 (or a factor of 400), we know that
**	isleap(y) == isleap(y % 400)
** and so
**	isleap(a + b) == isleap((a + b) % 400)
** or
**	isleap(a + b) == isleap(a % 400 + b % 400)
** This is true even if % means modulo rather than Fortran remainder
** (which is allowed by C89 but not C99).
** We use this to avoid addition overflow problems.
*/

#define isleap_sum(a, b)	isleap((a) % 400 + (b) % 400)

#endif /* !defined TZFILE_H */

    // -------------------------------------------------------------------------------------- END tzfile.h

#ifdef O_BINARY
#define OPEN_MODE	(O_RDONLY | O_BINARY)
#endif /* defined O_BINARY */
#ifndef O_BINARY
#define OPEN_MODE	O_RDONLY
#endif /* !defined O_BINARY */

    static const char	gmt[] = "GMT";

    /*
    ** The DST rules to use if TZ has no rules and we can't load TZDEFRULES.
    ** We default to US rules as of 1999-08-17.
    ** POSIX 1003.1 section 8.1.1 says that the default DST rules are
    ** implementation dependent; for historical reasons, US rules are a
    ** common default.
    */
#ifndef TZDEFRULESTRING
#define TZDEFRULESTRING ",M4.1.0,M10.5.0"
#endif /* !defined TZDEFDST */

#define BIGGEST(a, b)	(((a) > (b)) ? (a) : (b))

#ifdef TZNAME_MAX
#define MY_TZNAME_MAX	TZNAME_MAX
#endif /* defined TZNAME_MAX */
#ifndef TZNAME_MAX
#define MY_TZNAME_MAX	255
#endif /* !defined TZNAME_MAX */

    struct ttinfo {				/* time type information */
	long		tt_gmtoff;	/* UTC offset in seconds */
	int		tt_isdst;	/* used to set tm_isdst */
	int		tt_abbrind;	/* abbreviation list index */
	int		tt_ttisstd;	/* TRUE if transition is std time */
	int		tt_ttisgmt;	/* TRUE if transition is UTC */
    };

    struct lsinfo {				/* leap second information */
	time_t		ls_trans;	/* transition time */
	long		ls_corr;	/* correction to apply */
    };

    struct state {
	int		leapcnt;
	int		timecnt;
	int		typecnt;
	int		charcnt;
	int		goback;
	int		goahead;
	time_t		ats[TZ_MAX_TIMES];
	unsigned char	types[TZ_MAX_TIMES];
	struct ttinfo	ttis[TZ_MAX_TYPES];
	char		chars[BIGGEST(BIGGEST(TZ_MAX_CHARS + 1, sizeof gmt),
				      (2 * (MY_TZNAME_MAX + 1)))];
	struct lsinfo	lsis[TZ_MAX_LEAPS];
    };

    struct rule {
	int		r_type;		/* type of rule--see below */
	int		r_day;		/* day number of rule */
	int		r_week;		/* week number of rule */
	int		r_mon;		/* month number of rule */
	long		r_time;		/* transition time of rule */
    };

#define JULIAN_DAY		0	/* Jn - Julian day */
#define DAY_OF_YEAR		1	/* n - day of year */
#define MONTH_NTH_DAY_OF_WEEK	2	/* Mm.n.d - month, week, day of week */

    static const int mon_lengths[2][MONSPERYEAR] = {
	{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
    };

    static const int year_lengths[2] = {
	DAYSPERNYEAR, DAYSPERLYEAR
    };

    static int		gmt_is_set;

    //static struct state	lclmem;
    static struct state	gmtmem;
    //#define lclptr		(&lclmem)
#define gmtptr		(&gmtmem)

    static struct tm  tm;

    //extern const char *getTZinfo(void);

    static int		tzparse(const char * name, struct state * sp, int lastditch);
    static int		typesequiv(const struct state * sp, int a, int b);
    static const char *	getsecs(const char * strp, long * secsp);
    static const char * getnum(const char * strp, int * const nump, const int min, const int max);
    static const char * getrule(const char * strp, struct rule * const rulep);
    static time_t transtime(const time_t janfirst, const int year, const struct rule * const rulep, const long offset);
    static struct tm * timesub(const time_t * const timep, const long offset, const struct state * const sp, struct tm * const tmp);
    static int leaps_thru_end_of(const int y);

    static int increment_overflow(int * number, int delta) {
	int	number0;

	number0 = *number;
	*number += delta;
	return (*number < number0) != (delta < 0);
    }

    static long detzcode(const char * const codep) {
	long result;
	int	i;

	result = (codep[0] & 0x80) ? ~0L : 0;
	for (i = 0; i < 4; ++i)
	    result = (result << 8) | (codep[i] & 0xff);
	return result;
    }

    static time_t detzcode64(const char * const codep) {
	time_t result;
	int	i;

	result = (codep[0] & 0x80) ?  (~(int_fast64_t) 0) : 0;
	for (i = 0; i < 8; ++i)
	    result = result * 256 + (codep[i] & 0xff);
	return result;
    }

    static int differ_by_repeat(const time_t t1, const time_t t0) {
	if (TYPE_INTEGRAL(time_t) &&
	    TYPE_BIT(time_t) - TYPE_SIGNED(time_t) < SECSPERREPEAT_BITS)
	    return 0;
	/* R change */
	return (int_fast64_t)t1 - (int_fast64_t)t0 == SECSPERREPEAT;
    }

    static const char * getzname(const char * strp) {
	char c;

	while ((c = *strp) != '\0' && !is_digit(c) && c != ',' && c != '-' &&
	       c != '+')
	    ++strp;
	return strp;
    }

    static const char * getqzname(const char *strp, const int delim) {
	int	c;

	while ((c = *strp) != '\0' && c != delim)
	    ++strp;
	return strp;
    }

    static const char * getoffset(const char * strp, long * const offsetp) {
	int	neg = 0;

	if (*strp == '-') {
	    neg = 1;
	    ++strp;
	} else if (*strp == '+')
	    ++strp;
	strp = getsecs(strp, offsetp);
	if (strp == NULL)
	    return NULL;		/* illegal time */
	if (neg)
	    *offsetp = -*offsetp;
	return strp;
    }

    static const char * getsecs( const char * strp, long * const secsp) {
	int	num;

	/*
	** `HOURSPERDAY * DAYSPERWEEK - 1' allows quasi-Posix rules like
	** "M10.4.6/26", which does not conform to Posix,
	** but which specifies the equivalent of
	** ``02:00 on the first Sunday on or after 23 Oct''.
	*/
	strp = getnum(strp, &num, 0, HOURSPERDAY * DAYSPERWEEK - 1);
	if (strp == NULL)
	    return NULL;
	*secsp = num * (long) SECSPERHOUR;
	if (*strp == ':') {
	    ++strp;
	    strp = getnum(strp, &num, 0, MINSPERHOUR - 1);
	    if (strp == NULL)
		return NULL;
	    *secsp += num * SECSPERMIN;
	    if (*strp == ':') {
		++strp;
		/* `SECSPERMIN' allows for leap seconds. */
		strp = getnum(strp, &num, 0, SECSPERMIN);
		if (strp == NULL)
		    return NULL;
		*secsp += num;
	    }
	}
	return strp;
    }

    static const char * getnum(const char * strp, int * const nump, const int min, const int max) {
	char c;
	int	num;

	if (strp == NULL || !is_digit(c = *strp))
	    return NULL;
	num = 0;
	do {
	    num = num * 10 + (c - '0');
	    if (num > max)
		return NULL;	/* illegal value */
	    c = *++strp;
	} while (is_digit(c));
	if (num < min)
	    return NULL;		/* illegal value */
	*nump = num;
	return strp;
    }

    static const char * getrule(const char * strp, struct rule * const rulep) {
	if (*strp == 'J') {
	    /*
	    ** Julian day.
	    */
	    rulep->r_type = JULIAN_DAY;
	    ++strp;
	    strp = getnum(strp, &rulep->r_day, 1, DAYSPERNYEAR);
	} else if (*strp == 'M') {
	    /*
	    ** Month, week, day.
	    */
	    rulep->r_type = MONTH_NTH_DAY_OF_WEEK;
	    ++strp;
	    strp = getnum(strp, &rulep->r_mon, 1, MONSPERYEAR);
	    if (strp == NULL)
		return NULL;
	    if (*strp++ != '.')
		return NULL;
	    strp = getnum(strp, &rulep->r_week, 1, 5);
	    if (strp == NULL)
		return NULL;
	    if (*strp++ != '.')
		return NULL;
	    strp = getnum(strp, &rulep->r_day, 0, DAYSPERWEEK - 1);
	} else if (is_digit(*strp)) {
	    /*
	    ** Day of year.
	    */
	    rulep->r_type = DAY_OF_YEAR;
	    strp = getnum(strp, &rulep->r_day, 0, DAYSPERLYEAR - 1);
	} else	return NULL;		/* invalid format */
	if (strp == NULL)
	    return NULL;
	if (*strp == '/') {
	    /*
	    ** Time specified.
	    */
	    ++strp;
	    strp = getsecs(strp, &rulep->r_time);
	} else	rulep->r_time = 2 * SECSPERHOUR;	/* default = 2:00:00 */
	return strp;
    }

    static int tzload(const char * name, struct state * const sp, const int doextend) {
	const char * p;
	int	 i;
	int	 fid;
	int	 stored;
	int	 nread;
	union {
	    struct tzhead  tzhead;
	    char  buf[2 * sizeof(struct tzhead) + 
		      2 * sizeof *sp + 4 * TZ_MAX_TIMES];
	} u;

	sp->goback = sp->goahead = FALSE;
	/* if (name == NULL && (name = TZDEFAULT) == NULL) return -1; */
	if (name == NULL) {
	    // edd 06 Jul 2010  let's do without getTZinfo()
	    //name = getTZinfo();
	    //if( strcmp(name, "unknown") == 0 ) name = TZDEFAULT;
	    name = TZDEFAULT;
	}
	
	{
	    int  doaccess;
	    /*
	    ** Section 4.9.1 of the C standard says that
	    ** "FILENAME_MAX expands to an integral constant expression
	    ** that is the size needed for an array of char large enough
	    ** to hold the longest file name string that the implementation
	    ** guarantees can be opened."
	    */
	    char fullname[FILENAME_MAX + 1];
	    // edd 08 Jul 2010 not currently needed  const char *sname = name;

	    if (name[0] == ':')
		++name;
	    doaccess = name[0] == '/';
	    if (!doaccess) {
		char buf[1000];
		p = getenv("TZDIR");
		if (p == NULL) {
		    snprintf(buf, 1000, "%s/share/zoneinfo", 
			     getenv("R_HOME"));
		    buf[999] = '\0';
		    p = buf;
		}
		/* if ((p = TZDIR) == NULL) return -1; */
		if ((strlen(p) + strlen(name) + 1) >= sizeof fullname)
		    return -1;
		(void) strcpy(fullname, p);
		(void) strcat(fullname, "/");
		(void) strcat(fullname, name);
		/*
		** Set doaccess if '.' (as in "../") shows up in name.
		*/
		if (strchr(name, '.') != NULL) doaccess = TRUE;
		name = fullname;
	    }
	    // edd 16 Jul 2010  comment out whole block
	    //if (doaccess && access(name, R_OK) != 0) {
		// edd 08 Jul 2010  we use this without TZ for dates only 
		//                  so no need to warn
		//Rf_warning("unknown timezone '%s'", sname);
		//return -1;
	    //}
	    if ((fid = open(name, OPEN_MODE)) == -1) {
		// edd 08 Jul 2010  we use this without TZ for dates only 
		//                  so no need to warn
		//Rf_warning("unknown timezone '%s'", sname);
		return -1;
	    }
		
	}
	nread = read(fid, u.buf, sizeof u.buf);
	if (close(fid) < 0 || nread <= 0)
	    return -1;
	for (stored = 4; stored <= 8; stored *= 2) {
	    int ttisstdcnt;
	    int ttisgmtcnt;

	    ttisstdcnt = (int) detzcode(u.tzhead.tzh_ttisstdcnt);
	    ttisgmtcnt = (int) detzcode(u.tzhead.tzh_ttisgmtcnt);
	    sp->leapcnt = (int) detzcode(u.tzhead.tzh_leapcnt);
	    sp->timecnt = (int) detzcode(u.tzhead.tzh_timecnt);
	    sp->typecnt = (int) detzcode(u.tzhead.tzh_typecnt);
	    sp->charcnt = (int) detzcode(u.tzhead.tzh_charcnt);
	    p = u.tzhead.tzh_charcnt + sizeof u.tzhead.tzh_charcnt;
	    if (sp->leapcnt < 0 || sp->leapcnt > TZ_MAX_LEAPS ||
		sp->typecnt <= 0 || sp->typecnt > TZ_MAX_TYPES ||
		sp->timecnt < 0 || sp->timecnt > TZ_MAX_TIMES ||
		sp->charcnt < 0 || sp->charcnt > TZ_MAX_CHARS ||
		(ttisstdcnt != sp->typecnt && ttisstdcnt != 0) ||
		(ttisgmtcnt != sp->typecnt && ttisgmtcnt != 0))
		return -1;
	    if (nread - (p - u.buf) <
		sp->timecnt * stored +	  /* ats */
		sp->timecnt +		  /* types */
		sp->typecnt * 6 +		  /* ttinfos */
		sp->charcnt +		  /* chars */
		sp->leapcnt * (stored + 4) +  /* lsinfos */
		ttisstdcnt +		  /* ttisstds */
		ttisgmtcnt)			  /* ttisgmts */
		return -1;
	    for (i = 0; i < sp->timecnt; ++i) {
		sp->ats[i] = (stored == 4) ? detzcode(p) : detzcode64(p);
		p += stored;
	    }
	    for (i = 0; i < sp->timecnt; ++i) {
		sp->types[i] = (unsigned char) *p++;
		if (sp->types[i] >= sp->typecnt)
		    return -1;
	    }
	    for (i = 0; i < sp->typecnt; ++i) {
		struct ttinfo * ttisp;

		ttisp = &sp->ttis[i];
		ttisp->tt_gmtoff = detzcode(p);
		p += 4;
		ttisp->tt_isdst = (unsigned char) *p++;
		if (ttisp->tt_isdst != 0 && ttisp->tt_isdst != 1)
		    return -1;
		ttisp->tt_abbrind = (unsigned char) *p++;
		if (ttisp->tt_abbrind < 0 ||
		    ttisp->tt_abbrind > sp->charcnt)
		    return -1;
	    }
	    for (i = 0; i < sp->charcnt; ++i)
		sp->chars[i] = *p++;
	    sp->chars[i] = '\0';	/* ensure '\0' at end */
	    for (i = 0; i < sp->leapcnt; ++i) {
		struct lsinfo * lsisp;

		lsisp = &sp->lsis[i];
		lsisp->ls_trans = (stored == 4) ? detzcode(p) : detzcode64(p);
		p += stored;
		lsisp->ls_corr = detzcode(p);
		p += 4;
	    }
	    for (i = 0; i < sp->typecnt; ++i) {
		struct ttinfo * ttisp;

		ttisp = &sp->ttis[i];
		if (ttisstdcnt == 0)
		    ttisp->tt_ttisstd = FALSE;
		else {
		    ttisp->tt_ttisstd = *p++;
		    if (ttisp->tt_ttisstd != TRUE && ttisp->tt_ttisstd != FALSE)
			return -1;
		}
	    }
	    for (i = 0; i < sp->typecnt; ++i) {
		struct ttinfo * ttisp;

		ttisp = &sp->ttis[i];
		if (ttisgmtcnt == 0)
		    ttisp->tt_ttisgmt = FALSE;
		else {
		    ttisp->tt_ttisgmt = *p++;
		    if (ttisp->tt_ttisgmt != TRUE && ttisp->tt_ttisgmt != FALSE)
			return -1;
		}
	    }
	    /*
	    ** Out-of-sort ats should mean we're running on a
	    ** signed time_t system but using a data file with
	    ** unsigned values (or vice versa).
	    */
	    for (i = 0; i < sp->timecnt - 2; ++i)
		if (sp->ats[i] > sp->ats[i + 1]) {
		    ++i;
		    if (TYPE_SIGNED(time_t)) {
			/*
			** Ignore the end (easy).
			*/
			sp->timecnt = i;
		    } else {
			/*
			** Ignore the beginning (harder).
			*/
			int	j;

			for (j = 0; j + i < sp->timecnt; ++j) {
			    sp->ats[j] = sp->ats[j + i];
			    sp->types[j] = sp->types[j + i];
			}
			sp->timecnt = j;
		    }
		    break;
		}
	    /*
	    ** If this is an old file, we're done.
	    */
	    if (u.tzhead.tzh_version[0] == '\0')
		break;
	    nread -= p - u.buf;
	    for (i = 0; i < nread; ++i)
		u.buf[i] = p[i];
	    /*
	    ** If this is a narrow integer time_t system, we're done.
	    */
	    if (stored >= (int) sizeof(time_t) && TYPE_INTEGRAL(time_t))
		break;
	}
	if (doextend && nread > 2 &&
	    u.buf[0] == '\n' && u.buf[nread - 1] == '\n' &&
	    sp->typecnt + 2 <= TZ_MAX_TYPES) {
	    struct state ts;
	    int result;

	    u.buf[nread - 1] = '\0';
	    result = tzparse(&u.buf[1], &ts, FALSE);
	    if (result == 0 && ts.typecnt == 2 &&
		sp->charcnt + ts.charcnt <= TZ_MAX_CHARS) {
		for (i = 0; i < 2; ++i)
		    ts.ttis[i].tt_abbrind += sp->charcnt;
		for (i = 0; i < ts.charcnt; ++i)
		    sp->chars[sp->charcnt++] = ts.chars[i];
		i = 0;
		while (i < ts.timecnt && ts.ats[i] <= sp->ats[sp->timecnt - 1])
		    ++i;
		while (i < ts.timecnt &&
		       sp->timecnt < TZ_MAX_TIMES) {
		    sp->ats[sp->timecnt] = ts.ats[i];
		    sp->types[sp->timecnt] = sp->typecnt + ts.types[i];
		    ++sp->timecnt;
		    ++i;
		}
		sp->ttis[sp->typecnt++] = ts.ttis[0];
		sp->ttis[sp->typecnt++] = ts.ttis[1];
	    }
	}
	i = 2 * YEARSPERREPEAT;
	sp->goback = sp->goahead = sp->timecnt > i;
	sp->goback = sp->goback &&
	    typesequiv(sp, sp->types[i], sp->types[0]) &&
	    differ_by_repeat(sp->ats[i], sp->ats[0]);
	sp->goahead = sp->goahead &&
	    typesequiv(sp, sp->types[sp->timecnt - 1],
		       sp->types[sp->timecnt - 1 - i]) &&
	    differ_by_repeat(sp->ats[sp->timecnt - 1],
			     sp->ats[sp->timecnt - 1 - i]);
	return 0;
    }

    static time_t transtime(const time_t janfirst, const int year, const struct rule * const rulep, const long offset) {
	int	leapyear;
	time_t value;
	int	i;
	int	d, m1, yy0, yy1, yy2, dow;

	INITIALIZE(value);
	leapyear = isleap(year);
	switch (rulep->r_type) {

	case JULIAN_DAY:
	    /*
	    ** Jn - Julian day, 1 == January 1, 60 == March 1 even in leap
	    ** years.
	    ** In non-leap years, or if the day number is 59 or less, just
	    ** add SECSPERDAY times the day number-1 to the time of
	    ** January 1, midnight, to get the day.
	    */
	    value = janfirst + (rulep->r_day - 1) * SECSPERDAY;
	    if (leapyear && rulep->r_day >= 60)
		value += SECSPERDAY;
	    break;

	case DAY_OF_YEAR:
	    /*
	    ** n - day of year.
	    ** Just add SECSPERDAY times the day number to the time of
	    ** January 1, midnight, to get the day.
	    */
	    value = janfirst + rulep->r_day * SECSPERDAY;
	    break;

	case MONTH_NTH_DAY_OF_WEEK:
	    /*
	    ** Mm.n.d - nth "dth day" of month m.
	    */
	    value = janfirst;
	    for (i = 0; i < rulep->r_mon - 1; ++i)
		value += mon_lengths[leapyear][i] * SECSPERDAY;

	    /*
	    ** Use Zeller's Congruence to get day-of-week of first day of
	    ** month.
	    */
	    m1 = (rulep->r_mon + 9) % 12 + 1;
	    yy0 = (rulep->r_mon <= 2) ? (year - 1) : year;
	    yy1 = yy0 / 100;
	    yy2 = yy0 % 100;
	    dow = ((26 * m1 - 2) / 10 +
		   1 + yy2 + yy2 / 4 + yy1 / 4 - 2 * yy1) % 7;
	    if (dow < 0)
		dow += DAYSPERWEEK;

	    /*
	    ** "dow" is the day-of-week of the first day of the month. Get
	    ** the day-of-month (zero-origin) of the first "dow" day of the
	    ** month.
	    */
	    d = rulep->r_day - dow;
	    if (d < 0)
		d += DAYSPERWEEK;
	    for (i = 1; i < rulep->r_week; ++i) {
		if (d + DAYSPERWEEK >=
		    mon_lengths[leapyear][rulep->r_mon - 1])
		    break;
		d += DAYSPERWEEK;
	    }

	    /*
	    ** "d" is the day-of-month (zero-origin) of the day we want.
	    */
	    value += d * SECSPERDAY;
	    break;
	}

	/*
	** "value" is the Epoch-relative time of 00:00:00 UTC on the day in
	** question. To get the Epoch-relative time of the specified local
	** time on that day, add the transition time and the current offset
	** from UTC.
	*/
	return value + rulep->r_time + offset;
    }

    static int tzparse(const char * name, struct state * const sp, const int lastditch) {
	const char * stdname;
	const char * dstname;
	size_t  stdlen;
	size_t  dstlen;
	long stdoffset;
	long dstoffset;
	time_t * atp;
	unsigned char * typep;
	char * cp;
	int	load_result;

	INITIALIZE(dstname);
	stdname = name;
	if (lastditch) {
	    stdlen = strlen(name);	/* length of standard zone name */
	    name += stdlen;
	    if (stdlen >= sizeof sp->chars)
		stdlen = (sizeof sp->chars) - 1;
	    stdoffset = 0;
	} else {
	    if (*name == '<') {
		name++;
		stdname = name;
		name = getqzname(name, '>');
		if (*name != '>')
		    return (-1);
		stdlen = name - stdname;
		name++;
	    } else {
		name = getzname(name);
		stdlen = name - stdname;
	    }
	    if (*name == '\0')
		return -1;
	    name = getoffset(name, &stdoffset);
	    if (name == NULL)
		return -1;
	}
	load_result = tzload(TZDEFRULES, sp, FALSE);
	if (load_result != 0)
	    sp->leapcnt = 0;		/* so, we're off a little */
	if (*name != '\0') {
	    if (*name == '<') {
		dstname = ++name;
		name = getqzname(name, '>');
		if (*name != '>')
		    return -1;
		dstlen = name - dstname;
		name++;
	    } else {
		dstname = name;
		name = getzname(name);
		dstlen = name - dstname; /* length of DST zone name */
	    }
	    if (*name != '\0' && *name != ',' && *name != ';') {
		name = getoffset(name, &dstoffset);
		if (name == NULL)
		    return -1;
	    } else	dstoffset = stdoffset - SECSPERHOUR;
	    if (*name == '\0' && load_result != 0)
		name = TZDEFRULESTRING;
	    if (*name == ',' || *name == ';') {
		struct rule	start;
		struct rule	end;
		int	year;
		time_t janfirst;
		time_t starttime;
		time_t endtime;

		++name;
		if ((name = getrule(name, &start)) == NULL)
		    return -1;
		if (*name++ != ',')
		    return -1;
		if ((name = getrule(name, &end)) == NULL)
		    return -1;
		if (*name != '\0')
		    return -1;
		sp->typecnt = 2;	/* standard time and DST */
		/*
		** Two transitions per year, from EPOCH_YEAR forward.
		*/
		sp->ttis[0].tt_gmtoff = -dstoffset;
		sp->ttis[0].tt_isdst = 1;
		sp->ttis[0].tt_abbrind = stdlen + 1;
		sp->ttis[1].tt_gmtoff = -stdoffset;
		sp->ttis[1].tt_isdst = 0;
		sp->ttis[1].tt_abbrind = 0;
		atp = sp->ats;
		typep = sp->types;
		janfirst = 0;
		sp->timecnt = 0;
		for (year = EPOCH_YEAR;
		     sp->timecnt + 2 <= TZ_MAX_TIMES;
		     ++year) {
		    time_t newfirst;

		    starttime = transtime(janfirst, year, &start,
					  stdoffset);
		    endtime = transtime(janfirst, year, &end,
					dstoffset);
		    if (starttime > endtime) {
			*atp++ = endtime;
			*typep++ = 1;	/* DST ends */
			*atp++ = starttime;
			*typep++ = 0;	/* DST begins */
		    } else {
			*atp++ = starttime;
			*typep++ = 0;	/* DST begins */
			*atp++ = endtime;
			*typep++ = 1;	/* DST ends */
		    }
		    sp->timecnt += 2;
		    newfirst = janfirst;
		    newfirst += year_lengths[isleap(year)] *
			SECSPERDAY;
		    if (newfirst <= janfirst)
			break;
		    janfirst = newfirst;
		}
	    } else {
		long theirstdoffset;
		long theirdstoffset;
		long theiroffset;
		int	isdst;
		int	i;
		int	j;

		if (*name != '\0')
		    return -1;
		/*
		** Initial values of theirstdoffset and theirdstoffset.
		*/
		theirstdoffset = 0;
		for (i = 0; i < sp->timecnt; ++i) {
		    j = sp->types[i];
		    if (!sp->ttis[j].tt_isdst) {
			theirstdoffset =
			    -sp->ttis[j].tt_gmtoff;
			break;
		    }
		}
		theirdstoffset = 0;
		for (i = 0; i < sp->timecnt; ++i) {
		    j = sp->types[i];
		    if (sp->ttis[j].tt_isdst) {
			theirdstoffset =
			    -sp->ttis[j].tt_gmtoff;
			break;
		    }
		}
		/*
		** Initially we're assumed to be in standard time.
		*/
		isdst = FALSE;
		theiroffset = theirstdoffset;
		/*
		** Now juggle transition times and types
		** tracking offsets as you do.
		*/
		for (i = 0; i < sp->timecnt; ++i) {
		    j = sp->types[i];
		    sp->types[i] = sp->ttis[j].tt_isdst;
		    if (sp->ttis[j].tt_ttisgmt) {
			/* No adjustment to transition time */
		    } else {
			/*
			** If summer time is in effect, and the
			** transition time was not specified as
			** standard time, add the summer time
			** offset to the transition time;
			** otherwise, add the standard time
			** offset to the transition time.
			*/
			/*
			** Transitions from DST to DDST
			** will effectively disappear since
			** POSIX provides for only one DST
			** offset.
			*/
			if (isdst && !sp->ttis[j].tt_ttisstd) {
			    sp->ats[i] += dstoffset -
				theirdstoffset;
			} else {
			    sp->ats[i] += stdoffset -
				theirstdoffset;
			}
		    }
		    theiroffset = -sp->ttis[j].tt_gmtoff;
		    if (sp->ttis[j].tt_isdst)
			theirdstoffset = theiroffset;
		    else	theirstdoffset = theiroffset;
		}
		/*
		** Finally, fill in ttis.
		** ttisstd and ttisgmt need not be handled.
		*/
		sp->ttis[0].tt_gmtoff = -stdoffset;
		sp->ttis[0].tt_isdst = FALSE;
		sp->ttis[0].tt_abbrind = 0;
		sp->ttis[1].tt_gmtoff = -dstoffset;
		sp->ttis[1].tt_isdst = TRUE;
		sp->ttis[1].tt_abbrind = stdlen + 1;
		sp->typecnt = 2;
	    }
	} else {
	    dstlen = 0;
	    sp->typecnt = 1;		/* only standard time */
	    sp->timecnt = 0;
	    sp->ttis[0].tt_gmtoff = -stdoffset;
	    sp->ttis[0].tt_isdst = 0;
	    sp->ttis[0].tt_abbrind = 0;
	}
	sp->charcnt = stdlen + 1;
	if (dstlen != 0)
	    sp->charcnt += dstlen + 1;
	if ((size_t) sp->charcnt > sizeof sp->chars)
	    return -1;
	cp = sp->chars;
	(void) strncpy(cp, stdname, stdlen);
	cp += stdlen;
	*cp++ = '\0';
	if (dstlen != 0) {
	    (void) strncpy(cp, dstname, dstlen);
	    *(cp + dstlen) = '\0';
	}
	return 0;
    }

    static int typesequiv(const struct state * const sp, const int a, const int b) {
	int	result;

	if (sp == NULL ||
	    a < 0 || a >= sp->typecnt ||
	    b < 0 || b >= sp->typecnt)
	    result = FALSE;
	else {
	    const struct ttinfo * ap = &sp->ttis[a];
	    const struct ttinfo * bp = &sp->ttis[b];
	    result = ap->tt_gmtoff == bp->tt_gmtoff &&
		ap->tt_isdst == bp->tt_isdst &&
		ap->tt_ttisstd == bp->tt_ttisstd &&
		ap->tt_ttisgmt == bp->tt_ttisgmt &&
		strcmp(&sp->chars[ap->tt_abbrind],
		       &sp->chars[bp->tt_abbrind]) == 0;
	}
	return result;
    }

    static int leaps_thru_end_of(const int y) {
	return (y >= 0) ? (y / 4 - y / 100 + y / 400) :
	    -(leaps_thru_end_of(-(y + 1)) + 1);
    }

    static struct tm * timesub(const time_t * const timep, const long offset, const struct state * const sp, struct tm * const tmp) {
	const struct lsinfo * lp;
	time_t tdays;
	int	idays;	/* unsigned would be so 2003 */
	long rem;
	int	 y;
	const int *	ip;
	long corr;
	int	 hit;
	int	 i;

	corr = 0;
	hit = 0;
	i = sp->leapcnt;
	while (--i >= 0) {
	    lp = &sp->lsis[i];
	    if (*timep >= lp->ls_trans) {
		if (*timep == lp->ls_trans) {
		    hit = ((i == 0 && lp->ls_corr > 0) ||
			   lp->ls_corr > sp->lsis[i - 1].ls_corr);
		    if (hit)
			while (i > 0 &&
			       sp->lsis[i].ls_trans ==
			       sp->lsis[i - 1].ls_trans + 1 &&
			       sp->lsis[i].ls_corr ==
			       sp->lsis[i - 1].ls_corr + 1) {
			    ++hit;
			    --i;
			}
		}
		corr = lp->ls_corr;
		break;
	    }
	}
	y = EPOCH_YEAR;
	tdays = *timep / SECSPERDAY;
	rem = *timep - tdays * SECSPERDAY;
	while (tdays < 0 || tdays >= year_lengths[isleap(y)]) {
	    int  newy;
	    time_t tdelta;
	    int idelta;
	    int leapdays;

	    tdelta = tdays / DAYSPERLYEAR;
	    idelta = tdelta;
	    if (tdelta - idelta >= 1 || idelta - tdelta >= 1)
		return NULL;
	    if (idelta == 0)
		idelta = (tdays < 0) ? -1 : 1;
	    newy = y;
	    if (increment_overflow(&newy, idelta))
		return NULL;
	    leapdays = leaps_thru_end_of(newy - 1) -
		leaps_thru_end_of(y - 1);
	    tdays -= ((time_t) newy - y) * DAYSPERNYEAR;
	    tdays -= leapdays;
	    y = newy;
	}
	{
	    long seconds;

	    seconds = tdays * SECSPERDAY + 0.5;
	    tdays = seconds / SECSPERDAY;
	    rem += seconds - tdays * SECSPERDAY;
	}
	/*
	** Given the range, we can now fearlessly cast...
	*/
	idays = tdays;
	rem += offset - corr;
	while (rem < 0) {
	    rem += SECSPERDAY;
	    --idays;
	}
	while (rem >= SECSPERDAY) {
	    rem -= SECSPERDAY;
	    ++idays;
	}
	while (idays < 0) {
	    if (increment_overflow(&y, -1))
		return NULL;
	    idays += year_lengths[isleap(y)];
	}
	while (idays >= year_lengths[isleap(y)]) {
	    idays -= year_lengths[isleap(y)];
	    // if (increment_overflow(&y, 1)) // commented-out because of nasty g++ -Wall comment 
	    // 	return NULL;
	}
	tmp->tm_year = y;
	tmp->tm_yday = idays;
	/*
	** The "extra" mods below avoid overflow problems.
	*/
	tmp->tm_wday = EPOCH_WDAY +
	    ((y - EPOCH_YEAR) % DAYSPERWEEK) *
	    (DAYSPERNYEAR % DAYSPERWEEK) +
	    leaps_thru_end_of(y - 1) -
	    leaps_thru_end_of(EPOCH_YEAR - 1) +
	    idays;
	tmp->tm_wday %= DAYSPERWEEK;
	if (tmp->tm_wday < 0)
	    tmp->tm_wday += DAYSPERWEEK;
	tmp->tm_hour = (int) (rem / SECSPERHOUR);
	rem %= SECSPERHOUR;
	tmp->tm_min = (int) (rem / SECSPERMIN);
	/*
	** A positive leap second requires a special
	** representation. This uses "... ??:59:60" et seq.
	*/
	tmp->tm_sec = (int) (rem % SECSPERMIN) + hit;
	ip = mon_lengths[isleap(y)];
	for (tmp->tm_mon = 0; idays >= ip[tmp->tm_mon]; ++(tmp->tm_mon))
	    idays -= ip[tmp->tm_mon];
	tmp->tm_mday = (int) (idays + 1);
	tmp->tm_isdst = 0;
#ifdef TM_GMTOFF
	tmp->TM_GMTOFF = offset;
#endif /* defined TM_GMTOFF */
	return tmp;
    }

    static void gmtload(struct state * const sp) {
	if (tzload(gmt, sp, TRUE) != 0)
	    (void) tzparse(gmt, sp, TRUE);
    }

    static struct tm * gmtsub(const time_t * const timep, const long offset, struct tm * const	tmp) {
	struct tm * result;

	if (!gmt_is_set) {
	    gmt_is_set = TRUE;
	    gmtload(gmtptr);
	}
	result = timesub(timep, offset, gmtptr, tmp);
	return result;
    }

    // [[Rcpp::register]]
    struct tm * gmtime_(const time_t * const	timep) {
        return gmtsub(timep, 0L, &tm);
    }
}
