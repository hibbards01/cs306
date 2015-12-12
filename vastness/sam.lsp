;; Vastness
;; Author: Samuel Hibbard
;; Summary:
;;   This will find the prefix number from the powers of two.

;; lower-bound
;; This will find the lower bound of the prefix
(defun lower-bound (prefix)
  (calc-eval "floor(log($)/log(2))" nil prefix))

;; grab-fractional-log-of-base-10 
;; This will grab the fractional log of base 10 of what value is given.
(defun grab-fractional-log-of-base-10 (value)
  (calc-eval "log10($) - floor(log10($))" nil value))

;; grab-log-of-2
;; Grab the log base 10 of 2
(defun grab-log-of-2 ()
  (calc-eval "log10(2)"))

;; calc-n-log-of-2
;; This will calculate the nlog10 of 2.
(defun calc-n-log-of-2 (n log2)
  (calc-eval "($ * $$) - floor($ * $$)" nil n log2))

;; check-num
;x; Did it pass the bounds?
(defun check-num (lower upper num)
  (let ((lhs (calc-eval "$ < $$" nil lower num))
	(rhs (calc-eval "$ < $$" nil num upper)))
    (setq good nil)
    (if (and (string= lhs "1")
	     (string= rhs "1"))
	(setq good 1))
    good))

;; find-pow-of-2
;; This will find the value that we are searching for.
(defun find-pow-of-2 (prefix)
  ;; Set all the values
  (let ((n (string-to-number (lower-bound prefix)))
	(lower (grab-fractional-log-of-base-10 prefix))
	(upper (grab-fractional-log-of-base-10 (+ prefix 1)))
	(log2 (grab-log-of-2))
	(found nil))
    ;; Now find it!
    (while (not found)
      ;; Grab the value
      (setq num (calc-n-log-of-2 n log2))
      ;; Now see if it meets the criteria
      (if (check-num lower upper num)
	  (setq found n)
	(setq n (+ 1 n))))
    found))

;; run
;; This will grab the prefix from the ARGS and start the program.
(defun run (args)
  (let* ((prefix args)
	 (found (find-pow-of-2 (string-to-number prefix))))
    (calc-eval '(calc-precision 199) 'eval)
    (if found
	(princ (format "Power of 2 found with %s\nIt equals this: %s\n"
		       found
		       (calc-eval "2^$" nil found)))
      (princ (format "Not found\n")))
    t))
