;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Examples of division by multiplication
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Copyright © 2026 Borderite
;; Licnsed under the MIT License     
;;
default rel

%define MAGIC -4392081922311798003 ; 62 bits
%define SHIFT 4
    
section .text

global signed_div_by_21_zero_64
global signed_div_by_21_down_64
global signed_div_by_21_up_64

signed_div_by_21_zero_64:
;;
;; Function signature:
;;
;;   int64_t signed_div_by_21_zero_64(int64_t x);
;;
;; Parameters:
;;
;;   rdi: int64_t, dividend
;;
;; Return value:
;;
;;   rax: int64_t, quotient
;;
;; This function calculates sgn(rdi) * floor(|rdi| / 21) using the
;; division by multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    mov rax, MAGIC              ; rdx = M
    imul rdi                    ; rdx = (n * M) >> 32
    lea rax, [rdx + rdi]        ; rax = ((n * M) >> 32) + n
    sar rax, SHIFT              ; rax = (((n * M) >> 32) + n) >> SHIFT
    sar rdi, 63                 ; rdi = -(n < 0)
    sub rax, rdi                ; rax = (((n * M) >> 32) + n) >> SHIFT
                                ;       + (n < 0)
    ret
    
signed_div_by_21_down_64:
;;
;; Function signature:
;;
;;   int64_t signed_div_by_21_down_64(int64_t x);
;;
;; Parameters:
;;
;;   rdi: int64_t, dividend
;;
;; Return value:
;;
;;   rax: int64_t, quotient
;;
;; This function calculates floor(edi / 21) using the division by
;; multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    mov rax, MAGIC              ; rdx = M
    mov rdx, rdi
    shr rdx, 63                 ; rdx = (n < 0)
    xor rcx, rcx
    cmp rdi, -1
    sete cl                     ; rcx = (n == -1)
    add rdi, rdx                ; rdi = mu = n + (n < 0)
    imul rdi                    ; rdx = (mu * M) >> 32
    lea rax, [rdx + rdi]        ; rax = ((mu * M) >> 32) + mu
    sar rax, SHIFT              ; rax = (((n * M) >> 32) + n) >> SHIFT
    sub rax, rcx                ; rax = ((((n * M) >> 32) + n) >> SHIFT)
                                ;       - (n == -1)
    ret
    
signed_div_by_21_up_64:    
;;
;; Function signature:
;;
;;   int64_t signed_div_by_21_up_64(int64_t x);
;;
;; Parameters:
;;
;;   rdi: int64_t, dividend
;;
;; Return value:
;;
;;   rax: int64_t, quotient
;;
;; This function calculates ceil(rdi / 21) using the division by
;; multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    xor ecx, ecx
    xor edx, edx
    cmp rdi, 0
    setne cl                    ; rcx = (n != 0)
    setg dl                     ; rdx = (n > 0)
    sub rdi, rdx                ; rdi = nu = n - (n > 0)
    mov rax, MAGIC              ; rax = M
    imul rdi                    ; rdx = (nu * M) >> 32
    lea rax, [rdx + rdi]        ; rax = ((mu * M) >> 32) + n
    sar rax, SHIFT              ; rax = (((mu * M) >> 32) + n) >> SHIFT
    add rax, rcx                ; rax = (nu * M) >> SHIFT + (n !== 0)
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif
