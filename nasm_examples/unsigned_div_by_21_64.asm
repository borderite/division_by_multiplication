;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Examples of division by multiplication
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Copyright © 2026 Borderite
;; Licnsed under the MIT License     
;;
default rel
    
MAGIC equ 9662580229085955609   ; 64 bits
SHIFT equ 5

section .text

global unsigned_div_by_21_down_64
global unsigned_div_by_21_up_64

unsigned_div_by_21_down_64:
;;
;; Function signature:
;;
;;   uin64_t unsigned_div_by_21_down_64(uint64_t x);
;;
;; Parameters:
;;
;;   rdi: uint64_t, dividend
;;
;; Return value:
;;
;;   rax: uint64_t, quotient
;;
;; This function calculates floor(rdi / 21) using the division by
;; multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    mov rax, MAGIC              ; rax = M
    mul rdi                     ; [rdx:rax] = n * M
    add rdx, rdi                ; [cf:rdx] = ((n * M) >> 32) + n
    rcr rdx, 1                  ; rdx = (((n * M) >> 32) + n) >> 1
    shr rdx, SHIFT - 1          ; rdx = (((n * M) >> 32) + n) >> SHIFT
    mov rax, rdx
    ret
    
unsigned_div_by_21_up_64:
;;
;; Function signature:
;;
;;   uint64_t unsigned_div_by_21_up_64(uint64_t x);
;;
;; Parameters:
;;
;;   rdi: uint64_t, dividend
;;
;; Return value:
;;
;;   rax: uint64_t, quotient
;;
;; This function calculates ceil(rdi / 21) using the division by
;; multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    mov rax, MAGIC              ; rax = M
    xor ecx, ecx                ; Clear rcx
    test edi, edi
    setnz cl                    ; rcx = (n > 0)
    sub rdi, rcx                ; rdi = nu = n - (n > 0)
    mul rdi                     ; rdx = (n * M) >> 32
    add rdx, rdi                ; [cf:rdx] = ((n * M) >> 32) + n
    rcr rdx, 1                  ; rdx = (((n * M) >> 32) + n) >> 1
    shr rdx, SHIFT - 1          ; rdx = (((n * M) >> 32) + n) >> SHIFT
    lea rax, [rdx + rcx]        ; rax = (((n * M) >> 32) + n) >> SHIFT
                                ;       + (n > 0)
    ret
