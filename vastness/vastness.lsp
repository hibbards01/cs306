(defun power-of-2 (n)
  (if (zerop n) *one*
    (let* ((x *one*)
	   (power *two*))
      (while (> n 1)
	(cond ((= 1 (% n 2))
	       (setq x (* x power))
	       (setq n (/ (1- n) 2)))
	      (t
	       (setq n (/ n 2))))
	(setq power (* power power)))
      (* x power))))
power-of-2


(defun display-all ()
  (maphash (lambda (key val) (princ (format "%s ---> 2^%d\n" key val))) *prefix-table*))
