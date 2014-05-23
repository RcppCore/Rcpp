;; -*- emacs-lisp -*-
((nil .
      (
       (tab-width . 8)
       (indent-tabs-mode . nil)
       (fill-column . 80)
       ))
 (c++-mode .
	   (
	    (indent-tabs-mode . nil)
	    (tab-width . 8)
	    (show-trailing-whitespace . t)
	    (indicate-empty-lines . t)
	    (c-basic-offset . 4)
	    (eval . (progn
		      (c-set-offset 'innamespace '0)
		      (c-set-offset 'inline-open '0)
		      )
		  )
	    )
	   )
 )
