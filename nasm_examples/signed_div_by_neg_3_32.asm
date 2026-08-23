;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Examples of division by multiplication
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Copyright © 2026 Borderite
;; Licnsed under the MIT License     
;;
default rel

%define MAGIC 1431655765   ; 31 bits
%define SHIFT 1

section .text

global signed_div_by_neg_3_zero_32
global signed_div_by_neg_3_down_32
global signed_div_by_neg_3_up_32

signed_div_by_neg_3_zero_32:
;;
;; Function signature:
;;
;;   int32_t signed_div_by_neg_3_zero_32(int32_t x);
;;
;; Parameters:
;;
;;   edi: int32_t, dividend
;;
;; Return value:
;;
;;   eax: int32_t, quotient
;;
;; This function calculates -sgn(edi) * floor(|edi| / 3) using
;; the division by multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    movsx rdx, edi              ; rdx = n
    imul rax, rdx, MAGIC        ; rax = n * M
    sar rax, 32                 ; eax = (n * M) >> 32
    sub eax, edi                ; eax = ((n * M) >> 32) - n
    mov edx, eax                ; edx = ((n * M) >> 32) - n
    sar edx, 31                 ; edx = -(((n * M) >> 32) - n < 0) = -(n > 0)
    sar eax, SHIFT              ; eax = (((n * M) >> 32) - n) >> SHIFT
    sub eax, edx                ; eax = ((((n * M) >> 32) - n) >> SHIFT) + (n > 0)
    ret
    
signed_div_by_neg_3_down_32:
;;
;; Function signature:
;;
;;   int32_t signed_div_by_neg_3_down_32(int32_t x);
;;
;; Parameters:
;;
;;   edi: int32_t, dividend
;;
;; Return value:
;;
;;   eax: int32_t, quotient
;;
;; This function calculates floor(edi / (-3)) using the division by
;; multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    xor ecx, ecx                ; Clear rcx
    xor edx, edx                ; Clear rdx
    cmp edi, 1                  
    setge cl                    ; ecx = (n >= 1) = (n > 0)
    sete dl                     ; edx = (n == 1)
    sub edi, ecx                ; edi = nu = n - (n > 0)
    movsx rax, edi              ; rax = nu
    imul rax, rax, MAGIC        ; rax = nu * M
    sar rax, 32                 ; eax = (nu * M) >> 32
    sub eax, edi                ; eax = (nu * M) >> 32 - nu
    sar eax, SHIFT              ; eax = ((nu * M) >> 32 - nu) >> SHIFT
    sub eax, edx                ; eax = (((nu * M) >> 32 - nu) >> SHIFT) - (n == 1)
    ret
    
signed_div_by_neg_3_up_32:    
;;
;; Function signature:
;;
;;   int32_t signed_div_by_neg_3_up_32(int32_t x);
;;
;; Parameters:
;;
;;   edi: int32_t, dividend
;;
;; Return value:
;;
;;   eax: int32_t, quotient
;;
;; This function calculates ceil(edi / (=3)) using the division by
;; multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    xor ecx, ecx                ; Clear rcx
    xor edx, edx                ; Clear rdx
    cmp edi, 0                  
    setl cl                     ; ecx = (n < 0)
    setne dl                    ; edx = (n != 0)
    add edi, ecx                ; edi = mu = n + (n < 0)
    movsx rax, edi              ; rax = mu
    imul rax, rax, MAGIC        ; rax = mu * M
    sar rax, 32                 ; eax = (mu * M) >> 32
    sub eax, edi                ; eax = (mu * M) >> 32 - mu
    sar eax, SHIFT              ; eax = ((mu * M) >> 32 - mu) >> SHIFT
    add eax, edx                ; eax = (((mu * M) >> 32 - mu) >> SHIFT) + (n != 1)
    ret
