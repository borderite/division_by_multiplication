;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Examples of division by multiplication
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Copyright © 2026 Borderite
;; Licnsed under the MIT License     
;;
default rel

MAGIC equ -1717986919           ; 31 bits
SHIFT equ 33

section .text

global signed_div_by_neg_5_zero_32
global signed_div_by_neg_5_down_32
global signed_div_by_neg_5_up_32

signed_div_by_neg_5_zero_32:
;;
;; Function signature:
;;
;;   int32_t signed_div_by_neg_5_zero_32(int32_t x);
;;
;; Parameters:
;;
;;   edi: int32_t, dividend
;;
;; Return value:
;;
;;   eax: int32_t, quotient
;;
;; This function calculates -sgn(edi) * floor(|edi| / 5) using
;; the division by multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    movsx rax, edi              ; eax = n
    imul rax, rax, MAGIC        ; rax = n * M
    sar rax, SHIFT              ; eax = (n * M) >> SHIFT
    mov edi, eax                ; edi = (n * M) >> SHIFT
    sar edi, 31                 ; edi = (n * M) < 0 ? -1 : 0 = -(n > 0)
    sub eax, edi                ; eax = ((n * M) >> SHIFT) + (n > 0)
    ret
signed_div_by_neg_5_down_32:
;;
;; Function signature:
;;
;;   int32_t signed_div_by_neg_5_down_32(int32_t x);
;;
;; Parameters:
;;
;;   edi: int32_t, dividend
;;
;; Return value:
;;
;;   eax: int32_t, quotient
;;
;; This function calculates floor(edi / (-5)) using the division by
;; multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    xor ecx, ecx                ; Clear rcx
    xor edx, edx                ; Clear rdx
    cmp edi, 1                  ;
    setge cl                    ; ecx = (n > 0)
    sete dl                     ; edx = (n == 1)
    sub edi, ecx                ; edi = nu = n - (n > 0)
    movsx rax, edi              ; rax = nu
    imul rax, rax, MAGIC        ; rax = nu * M
    sar rax, SHIFT              ; eax = (nu * M) >> SHIFT
    sub eax, edx                ; eax = ((nu * M) >> SHIFT) - (n == 0)
    ret
    
signed_div_by_neg_5_up_32:    
;;
;; Function signature:
;;
;;   int32_t signed_div_by_neg_5_up_32(int32_t x);
;;
;; Parameters:
;;
;;   edi: int32_t, dividend
;;
;; Return value:
;;
;;   eax: int32_t, quotient
;;
;; This function calculates ceil(edi / (-5)) using the division by
;; multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    xor ecx, ecx
    xor edx, edx
    cmp edi, 0
    setl cl                     ; ecx = (n < 0)
    setne dl                    ; edx = (n != 0)
    add edi, ecx                ; rdi = nu = n + (n > 0)
    movsx rax, edi              ; rdi = nu
    imul rax, rax, MAGIC        ; rax = nu * M
    sar rax, SHIFT              ; eax = (nu * M) >> SHIFT
    add eax, edx                ; eax = (nu * M) >> SHIFT + (n !== 0)
    ret
