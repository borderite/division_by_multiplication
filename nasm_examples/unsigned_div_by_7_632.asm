;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Examples of division by multiplication
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Copyright © 2026 Borderite
;; Licnsed under the MIT License     
;;
default rel
    
%define MAGIC 613566757     ; 30 bits
%define SHIFT 3

section .text

global unsigned_div_by_7_down_32
global unsigned_div_by_7_up_32

unsigned_div_by_7_down_32:
;;
;; Function signature:
;;
;;   uint32_t unsigned_div_by_7_down_32(uint32_t x);
;;
;; Parameters:
;;
;;   edi: uint32_t, dividend
;;
;; Return value:
;;
;;   eax: uint32_t, quotient
;;
;; This function calculates floor(edi / 7) using the division by
;; multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    imul rax, rdi, MAGIC ; rax = n * M
    shr rax, 32                 ; rax = (n * M) >> 32
    add rax, rdi                ; rax = ((n * M) >> 32) + n
    shr rax, SHIFT           ; rdx = (((n * M) >> 32) + n) >> SHIFT
    ret
    
unsigned_div_by_7_up_32:
;;
;; Function signature:
;;
;;   uint32_t unsigned_div_by_7_up_32(uint32_t x);
;;
;; Parameters:
;;
;;   edi: uint32_t, dividend
;;
;; Return value:
;;
;;   eax: uint32_t, quotient
;;
;; This function calculates ceil(edi / 7) using the division by
;; multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    xor ecx, ecx
    test edi, edi
    setnz cl                    ; ecx = (n > 0)
    sub edi, ecx                ; edi = nu = n - (n > 0)
    imul rax, rdi, MAGIC ; rax = nu * M
    shr rax, 32                 ; rax = (nu * M) >> 32
    add rax, rdi                ; rax = ((nu * M) >> 32) + nu
    shr rax, SHIFT           ; rax = ((nu * M) >> 32) + nu) >> SHIFT
    add eax, ecx                ; eax = (((nu * M) >> 32) + nu) >> SHIFT) + (n > 0)
    ret
