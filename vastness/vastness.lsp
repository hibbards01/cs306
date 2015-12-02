(require 'cl)
(require 'calc)
(require 'bigint)

(defun power-of-two (n)
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

(defun bigint-power-of-two (n)
  (if (zerop n) *one*
    (let* ((x *one*)
	   (power *two*))
      (while (> n 1)
	(cond ((= 1 (% n 2))
	       (setq x (bigint-multiply x power))
	       (setq n (/ (1- n) 2)))
	      (t
	       (setq n (/ n 2))))
	(setq power (bigint-multiply power power)))
      (bigint-multiply x power))))

;use these for power-of-two
;(setq *one* 1)
;(setq *two* 2)

;use these for bigint-power-of-two
(setq *one* (bigint-int-to-bigint 1 10))
(setq *two* (bigint-int-to-bigint 2 10))

(defun display-all
  (maphash (lambda (key val) (princ (format "%s ---> 2^%d\n" key val))) *prefix-table*))

(setq one (bigint-int-to-bigint 1 10))
(setq two (bigint-int-to-bigint (- most-positive-fixnum 1) 10))

; double the most-positive-finum
(setq biggg (bigint-add two two))

;double most-positive-fixnum in bigint form
biggg ;Will be ([0 0 9 7 8 3 7 2 4 8 1 0 ...] 10)

;double most-positive-fixnum in string form
(bigint-to-string biggg) ;will be "4611686018427387900"

;wraps and fails
(+ 1 most-positive-fixnum) ;will be -2305843009213693952

; output is correct
(bigint-to-string (bigint-power-of-two 100)) ;"1267650600228229401496703205376"
