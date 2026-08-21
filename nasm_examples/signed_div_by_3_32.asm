;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Examples of division by multiplication
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Copyright © 2026 Borderite
;; Licnsed under the MIT License     
;;
default rel

%define MAGIC 715827883     ; 30 bits
%define SHIFT 31

section .text

global signed_div_by_3_zero_32
global signed_div_by_3_down_32
global signed_div_by_3_up_32

signed_div_by_3_zero_32:
;;
;; Function signature:
;;
;;   int32_t signed_div_by_3_zero_32(int32_t x);
;;
;; Parameters:
;;
;;   edi: int32_t, dividend
;;
;; Return value:
;;
;;   eax: int32_t, quotient
;;
;; This function calculates sgn(edi) * floor(|edi| / 3) using the
;; division by multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    movsx rax, edi              ; eax = n
    shr edi, 31                 ; edi = (n < 0)
    imul rax, rax, MAGIC        ; rax = n * M
    sar rax, SHIFT              ; eax = (n * M) >> SHIFT
    add eax, edi                ; eax = (n * M) >> SHIFT + (n < 0)
    ret
    
signed_div_by_3_down_32:
;;
;; Function signature:
;;
;;   int32_t signed_div_by_3_down_32(int32_t x);
;;
;; Parameters:
;;
;;   edi: int32_t, dividend
;;
;; Return value:
;;
;;   eax: int32_t, quotient
;;
;; This function calculates floor(edi / 3) using the division by
;; multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    movsx rax, edi              ; rax = n
    xor edx, edx
    cmp edi, -1
    sete dl                     ; edx = (n == -1)
    shr edi, 31                 ; edi = (n < 0)
    add rax, rdi                ; rax = mu = n + (n < 0)
    imul rax, rax, MAGIC        ; rax = mu * M
    sar rax, SHIFT              ; eax = (mu * M) >> SHIFT
    sub eax, edx                ; eax = (mu * M) >> SHIFT - (n == -1)
    ret
    
signed_div_by_3_up_32:    
;;
;; Function signature:
;;
;;   int32_t signed_div_by_3_up_32(int32_t x);
;;
;; Parameters:
;;
;;   edi: int32_t, dividend
;;
;; Return value:
;;
;;   eax: int32_t, quotient
;;
;; This function calculates ceil(edi / 3) using the division by
;; multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    xor ecx, ecx
    xor edx, edx
    cmp edi, 0
    setne cl                    ; ecx = (n != 0)
    setg dl                     ; edx = (n > 0)
    sub edi, edx                ; rdi = nu = n - (n > 0)
    movsx rdi, edi              ; rdi = nu
    imul rax, rdi, MAGIC        ; rax = nu * M
    sar rax, SHIFT              ; eax = (nu * M) >> SHIFT
    add eax, ecx                ; eax = (nu * M) >> SHIFT + (n !== 0)
    ret
