#!/usr/bin/Rscript

cppfiles <- list.files( pattern = "[.]cpp$" )
for( f in cppfiles ){
	base <- sub( "[.]cpp$", "", f )
	output <- sprintf( "%s.tex", base )
	system( sprintf( "highlight --input=%s --output=%s -L --pretty-symbols --replace-tabs=4", f, output ) )
	
	tex <- readLines( output )
	keep <- seq( which( tex == "\\noindent" ), which( tex == "\\normalfont" ) )
	tex <- c( 
		"\\vspace{1em}\\noindent\\fbox{\\begin{minipage}{0.9\\textwidth}" , 
		tex[ keep ],
		"\\end{minipage}}\\vspace{1em}" )
	
	writeLines( tex, output )
}

require( highlight )
if( compareVersion( "0.1-9", packageDescription( "highlight" )[["Version"]] ) ){
	stop( "version 0.1-9 of highlight is required for the minipage argument" )
}

r <- renderer_latex( doc = FALSE, minipage = TRUE )
rfiles <- setdiff( list.files( pattern = "[.]R$" ), "highlight.R" )
for( f in rfiles ){
	base <- sub( "[.]R$", "", f )
	output <- sprintf( "%s.tex", base )
	
	highlight( f, renderer = r, output = output )
}

