;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Examples of division by multiplication
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Copyright © 2026 Borderite
;; Licnsed under the MIT License     
;;
default rel
    
%define MAGIC 12297829382473034411 ; 64 bits
%define P 65
%define P_U_3_64_MINUS_64 1

section .text

global unsigned_div_by_3_down_64
global unsigned_div_by_3_up_64

unsigned_div_by_3_down_64:
;;
;; Function signature:
;;
;;   uint64_t unsigned_div_by_3_down_64(uint64_t x);
;;
;; Parameters:
;;
;;   rdi: uint64_t, dividend
;;
;; Return value:
;;
;;   rax: uint64_t, quotient
;;
;; This function calculates floor(rdi / 3) using the division by
;; multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    mov rax, MAGIC              ; rax = M
    mul rdi                     ; [rdx:rax] = n * M
    shr rdx, P - 64             ; rdx = (n * M) >> P
    mov rax, rdx
    ret
    
unsigned_div_by_3_up_64:
;;
;; Function signature:
;;
;;   uint64_t unsigned_div_by_3_up_64(uint64_t x);
;;
;; Parameters:
;;
;;   rdi: uint64_t, dividend
;;
;; Return value:
;;
;;   rax: uint64_t, quotient
;;
;; This function calculates ceil(rdi / 3) using the division by
;; multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    xor ecx, ecx
    test rdi, rdi
    setnz cl                    ; rcx = (n > 0)
    sub rdi, rcx                ; rdi = nu = n - (n > 0)
    mov rax, MAGIC              ; rax = M
    mul rdi                     ; [rdx:rax] = nu * M
    shr rdx, P - 64             ; rdx = (nu * M) >> P
    lea rax, [rdx + rcx]        ; rax = ((nu * M) >> P)
                                ;       + (n > 0)
    ret
