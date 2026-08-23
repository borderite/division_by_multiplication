;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Examples of division by multiplication
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Copyright © 2026 Borderite
;; Licnsed under the MIT License     
;;
default rel

%define MAGIC 6148914691236517205   ; 63 bits
%define SHIFT 1

section .text

global signed_div_by_neg_3_zero_64
global signed_div_by_neg_3_down_64
global signed_div_by_neg_3_up_64

signed_div_by_neg_3_zero_64:
;;
;; Function signature:
;;
;;   int64_t signed_div_by_neg_3_zero_64(int64_t x);
;;
;; Parameters:
;;
;;   rdi: int64_t, dividend
;;
;; Return value:
;;
;;   rax: int64_t, quotient
;;
;; This function calculates -sgn(rdi) * floor(|rdi| / 3) using
;; the division by multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    ; rdi = n
    xor esi, esi                ; Clear rsi
    cmp rdi, 0     
    setg sil                    ; rsi = n > 0
    mov rax, MAGIC              ; rax = M
    imul rdi                    ; rdx = (n * M) >> 64
    mov rax, rdx                ; rax = (n * M) >> 64
    sub rax, rdi                ; rax = ((n * M) >> 64) - n
    sar rax, SHIFT              ; rax = (((n * M) >> 64) - n) >> SHIFT
    add rax, rsi                ; rax = ((((n * M) >> 64) - n) >> SHIFT)
                                ;       + (n > 0)
    ret
    
signed_div_by_neg_3_down_64:
;;
;; Function signature:
;;
;;   int64_t signed_div_by_neg_3_down_64(int64_t x);
;;
;; Parameters:
;;
;;   rdi: int64_t, dividend
;;
;; Return value:
;;
;;   rax: int64_t, quotient
;;
;; This function calculates floor(edi / (-3)) using the division by
;; multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    xor ecx, ecx                ; Clear rcx
    xor esi, esi                ; Clear rsi
    cmp rdi, 1                  
    setge cl                    ; rcx = (n >= 1) = (n > 0)
    sete sil                    ; rsi = (n == 1)
    sub rdi, rcx                ; rdi = nu = n - (n > 0)
    mov rax, MAGIC              ; rax = M
    imul rdi                    ; rdx = nu * M >> 64
    mov rax, rdx                ; rax = nu * M >> 64
    sub rax, rdi                ; rax = (nu * M >> 64) - nu
    sar rax, SHIFT              ; rax = ((nu * M >> 64) - nu) >> SHIFT
    sub rax, rsi                ; rax = ((nu * M >> 64) - nu) >> SHIFT - (n == 1)
    ret
    
signed_div_by_neg_3_up_64:    
;;
;; Function signature:
;;
;;   int64_t signed_div_by_neg_3_up_64(int64_t x);
;;
;; Parameters:
;;
;;   rdi: int64_t, dividend
;;
;; Return value:
;;
;;   rax: int64_t, quotient
;;
;; This function calculates ceil(edi / (=3)) using the division by
;; multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    xor ecx, ecx                ; Clear rcx
    xor esi, esi                ; Clear rsi
    cmp rdi, 0                  
    setl cl                     ; rcx = (n < 0)
    setne sil                   ; rsi = (n != 0)
    add rdi, rcx                ; rdi = mu = n + (n < 0)
    mov rax, MAGIC              ; rax = M
    imul rdi                    ; rdx = (mu * M) >> 64
    mov rax, rdx                ; rax = (mu * M) >> 64
    sub rax, rdi                ; rax = (mu * M) >> 64 - mu
    sar rax, SHIFT              ; rax = ((mu * M) >> 64 - mu) >> SHIFT
    add rax, rsi                ; rax = ((mu * M) >> 64 - mu) >> SHIFT + (n != 0)
    ret
