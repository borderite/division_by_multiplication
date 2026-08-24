;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Examples of division by multiplication
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Copyright © 2026 Borderite
;; Licnsed under the MIT License     
;;
default rel

MAGIC equ -7378697629483820647  ; 63 bits
P equ 65

section .text

global signed_div_by_neg_5_zero_64
global signed_div_by_neg_5_down_64
global signed_div_by_neg_5_up_64

signed_div_by_neg_5_zero_64:
;;
;; Function signature:
;;
;;   int64_t signed_div_by_neg_5_zero_64(int64_t n);
;;
;; Parameters:
;;
;;   rdx: int64_t, dividend
;;
;; Return value:
;;
;;   rax: int64_t, quotient
;;
;; This function calculates -sgn(rdi) * floor(|rdi| / 5) using
;; the division by multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    ; rdi = n
    mov rax, MAGIC              ; rax = M
    imul rdi                    ; rdx = (n * M) >> 64
    mov rax, rdx                ; rax = (n * M) >> 64
    sar rax, P - 64             ; rax = (n * M) >> P
    sar rdx, 63                 ; rdx = -(n * M < 0) = -(n > 0)
    sub rax, rdx                ; rax = (n * M) >> (64 + SHIFT) + (n > 0)
    ret
signed_div_by_neg_5_down_64:
;;
;; Function signature:
;;
;;   int64_t signed_div_by_neg_5_down_64(int64_t n);
;;
;; Parameters:
;;
;;   rdi: int64_t, dividend
;;
;; Return value:
;;
;;   rax: int64_t, quotient
;;
;; This function calculates floor(rdi / (-5)) using the division by
;; multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    ; rdi = n
    xor ecx, ecx                ; Clear rcx
    xor esi, esi                ; Clear rsi
    cmp rdi, 1                  ;
    setge cl                    ; rcx = (n > 0)
    sete sil                    ; rsi = (n == 1)
    sub rdi, rcx                ; rdi = nu = n - (n > 0)
    mov rax, MAGIC              ; rax = M
    imul rdi                    ; rdx = (nu * M) >> 64
    mov rax, rdx                ; rax = (nu * M) >> 64
    sar rax, P - 64             ; rax = (nu * M) >> P
    sub rax, rsi                ; rax = (nu * M) >> P - (n == 1)
    ret
    
signed_div_by_neg_5_up_64:    
;;
;; Function signature:
;;
;;   int64_t signed_div_by_neg_5_up_64(int64_t n);
;;
;; Parameters:
;;
;;   rdi: int64_t, dividend
;;
;; Return value:
;;
;;   rax: int64_t, quotient
;;
;; This function calculates ceil(rdi / (-5)) using the division by
;; multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    xor ecx, ecx                ; Clear rcx
    xor esi, esi                ; Clear rsi
    cmp rdi, 0
    setl cl                     ; rcx = (n < 0)
    setne sil                   ; rsi = (n != 0)
    add rdi, rcx                ; rdi = nu = n + (n > 0)
    mov rax, MAGIC              ; rax = M
    imul rdi                    ; rdx = (nu * M) >> 64
    mov rax, rdx                ; rax = (nu * M) >> 64
    sar rax, P - 64             ; rax = (nu * M) >> P
    add rax, rsi                ; rax = (nu * M) >> P + (n !== 0)
    ret
