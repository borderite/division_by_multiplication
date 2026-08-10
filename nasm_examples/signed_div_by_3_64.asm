;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Examples of division by multiplication
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Copyright © 2026 Borderite
;; Licnsed under the MIT License     
;;
default rel

%define MAGIC 3074457345618258603 ; 62 bits
%define P 63

section .text

global signed_div_by_3_zero_64
global signed_div_by_3_down_64
global signed_div_by_3_up_64

signed_div_by_3_zero_64:
;;
;; Function signature:
;;
;;   int64_t signed_div_by_3_zero_64(int64_t x);
;;
;; Parameters:
;;
;;   rdi: int64_t, dividend
;;
;; Return value:
;;
;;   rax: int64_t, quotient
;;
;; This function calculates sgn(rdi) * floor(|rdi| / 3) using
;; the division by multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    mov rax, rdi                ; rax = n
    shr rdi, 63                 ; rdi = (n < 0)
    mov rdx, MAGIC              ; rdx = M
    imul rdx                    ; [rdx:rax] = n * M We want to do
    ; [rdx:rax] >> P. But we can get the same value in rdx if we do
    ; [rdx:rax] << 64 - P.
    shld rdx, rax, 64 - P       ; rdx = (n * M) >> P
    lea rax, [rdx + rdi]        ; rax = (n * M) >> P
                                ;        + (n < 0)
    ret
    
signed_div_by_3_down_64:
;;
;; Function signature:
;;
;;   int64_t signed_div_by_3_down_64(int64_t x);
;;
;; Parameters:
;;
;;   rdi: int64_t, dividend
;;
;; Return value:
;;
;;   rax: int64_t, quotient
;;
;; This function calculates floor(rdi / 3) using the division by
;; multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    mov rax, rdi                  ; rax = n
    xor ecx, ecx
    cmp rdi, -1
    setne cl                      ; rdx = (n != -1)
    shr rdi, 63                   ; rdi = (n < 0)
    add rax, rdi                  ; rax = mu = n + (n < 0)
    mov rdx, MAGIC                ; rdx = M
    imul rdx                      ; [rdx:rax] = mu * M
    ; [rdx:rax] >> P. But we can get the same value in rdx if we do
    ; [rdx:rax] << 64 - P.
    shld rdx, rax, 64 - P         ; rdx = (mu * M) >> P
    lea rax, [rdx + rcx - 1]      ; rax = ((mu * M) >> P) + (n != -1) - 1
                                  ;     = ((mu * M) >> P) - (n == -1)
    ret
    
signed_div_by_3_up_64:    
;;
;; Function signature:
;;
;;   int64_t signed_div_by_3_up_64(int64_t x);
;;
;; Parameters:
;;
;;   rdi: int64_t, dividend
;;
;; Return value:
;;
;;   rax: int64_t, quotient
;;
;; This function calculates ceil(rdi / 3) using the division by
;; multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    xor ecx, ecx
    xor esi, esi
    cmp rdi, 0
    setne cl                      ; rdx = (n != 0)
    setg sil                      ; rsi = (n > 0)
    sub rdi, rsi                  ; rdi = nu = n - (n > 0)
    mov rax, MAGIC                ; rax = M
    imul rdi                      ; [rdx:rax] = nu * M
    ; [rdx:rax] >> P. But we can get the same value in rdx if we do
    ; [rdx:rax] << 64 - P.
    shld rdx, rax, 64 - P         ; rdx = (nu * M) >> P
    lea rax, [rdx + rcx]          ; rax = ((mu * M) >> P) 
                                  ;       + (n != 0)
    ret

