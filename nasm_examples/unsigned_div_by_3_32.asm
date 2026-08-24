;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Examples of division by multiplication
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Copyright © 2026 Borderite
;; Licnsed under the MIT License     
;;
default rel
    
MAGIC equ 2863311531            ; 32 bits
P equ 33

section .text    

global unsigned_div_by_3_down_32
global unsigned_div_by_3_up_32

unsigned_div_by_3_down_32:
;;
;; Function signature:
;;
;;   uint32_t unsigned_div_by_3_down_32(uint32_t x);
;;
;; Parameters:
;;
;;   edi: uint32_t, dividend
;;
;; Return value:
;;
;;   eax: uint32_t, quotient
;;
;; This function calculates floor(edi / 3) using the division by
;; multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    mov eax, MAGIC              ; rax = M
    imul rax, rdi               ; rax = n * M
    shr rax, P                  ; eax = (n * M) >> P
    ret
    
unsigned_div_by_3_up_32:
;;
;; Function signature:
;;
;;   uint32_t unsigned_div_by_3_up_32(uint32_t x);
;;
;; Parameters:
;;
;;   edi: uint32_t, dividend
;;
;; Return value:
;;
;;   eax: uint32_t, quotient
;;
;; This function calculates ceil(edi / 3) using the division by
;; multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    xor ecx, ecx                ;
    test edi, edi
    setnz cl                    ; ecx = (n > 0)
    sub edi, ecx                ; edi = nu = n - (n > 0)
    mov eax, MAGIC              ; eax = M
    imul rax, rdi               ; rax = nu * M
    shr rax, P                  ; eax = (nu * M) >> P
    add eax, ecx                ; eax = (nu * M) >> P + (n > 0)
    ret
