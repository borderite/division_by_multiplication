;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Examples of division by multiplication
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Copyright © 2026 Borderite
;; Licnsed under the MIT License     
;;
default rel
    
%define MAGIC -1840700269   ; 31 bits
%define SHIFT 2

section .text

global signed_div_by_7_zero_32
global signed_div_by_7_down_32
global signed_div_by_7_up_32

signed_div_by_7_zero_32:
;;
;; Function signature:
;;
;;   int32_t signed_div_by_7_zero_32(int32_t x);
;;
;; Parameters:
;;
;;   edi: int32_t, dividend
;;
;; Return value:
;;
;;   eax: int32_t, quotient
;;
;; This function calculates sgn(edi) * ceil(|edi| / 7) using
;; the division by multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    movsx rdi, edi              ; rdi = n
    mov edx, edi                ; edx = n
    shr edx, 31                 ; edx = (n < 0)
    imul rax, rdi, MAGIC        ; rax = n * M
    sar rax, 32                 ; rax = (n * M) >> 32
    add rax, rdi                ; rax = ((n * M) >> 32) + n
    sar rax, SHIFT              ; eax = (((n * M) >> 32) + n) >> SHIFT
    add eax, edx                ; eax = (n * M) >> SHIFT + (n < 0)
    ret
    
signed_div_by_7_down_32:
;;
;; Function signature:
;;
;;   int32_t signed_div_by_7_down_32(int32_t x);
;;
;; Parameters:
;;
;;   edi: int32_t, dividend
;;
;; Return value:
;;
;;   eax: int32_t, quotient
;;
;; This function calculates floor(edi / 7) using the division by
;; multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    xor edx, edx
    cmp edi, -1
    sete dl                     ; edx = (n == -1)
    mov esi, edi
    shr esi, 31                 ; esi = (n < 0)
    add edi, esi                ; edi = mu = n + (n < 0)
    movsx rdi, edi              ; rdi = mu
    imul rax, rdi, MAGIC        ; rax = mu * M
    sar rax, 32                 ; rax = (mu * M) >> 32
    add rax, rdi                ; rax = ((mu * M) >> 32) + mu
    sar rax, SHIFT              ; eax = (mu * M) >> SHIFT
    sub eax, edx                ; eax = (mu * M) >> SHIFT + (n == -1)
    ret
    
signed_div_by_7_up_32:    
;;
;; Function signature:
;;
;;   int32_t signed_div_by_7_up_32(int32_t x);
;;
;; Parameters:
;;
;;   edi: int32_t, dividend
;;
;; Return value:
;;
;;   eax: int32_t, quotient
;;
;; This function calculates ceil(edi / 7) using the division by
;; multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    xor ecx, ecx
    xor edx, edx
    cmp edi, 0
    setne cl                    ; ecx = (n != 0)
    setg dl                     ; edx = (n > 0)
    sub edi, edx                ; edi = nu = n - (n > 0)
    movsx rdi, edi              ; rdi = nu
    imul rax, rdi, MAGIC        ; rax = nu * M
    sar rax, 32                 ; rax = (mu * M) >> 32
    add rax, rdi                ; rax = ((mu * M) >> 32) + n
    sar rax, SHIFT              ; rax = (((mu * M) >> 32) + n) >>
                                ;    SHIFT
    add eax, ecx                ; eax = ((nu * M) >> SHIFT)
                                ;    + (n != 0)
    ret
