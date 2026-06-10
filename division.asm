default rel
    
section .text

global div_by_3_unsigned_down_32
global div_by_3_unsigned_up_32
global div_by_3_signed_zero_32
global div_by_3_signed_down_32
global div_by_3_signed_up_32
global div_by_7_unsigned_down_32
global div_by_7_unsigned_up_32
global div_by_7_signed_zero_32
global div_by_7_signed_down_32
global div_by_7_signed_up_32
global div_by_3_unsigned_down_64
global div_by_3_unsigned_up_64
global div_by_3_signed_zero_64
global div_by_3_signed_down_64
global div_by_3_signed_up_64
global div_by_21_unsigned_down_64
global div_by_21_unsigned_up_64
global div_by_21_signed_zero_64
global div_by_21_signed_down_64
global div_by_21_signed_up_64

%define MAGIC_U_3_32 2863311531    ; 32 bits
%define P_U_3_32 33
%define MAGIC_S_3_32 715827883     ; 30 bits
%define P_S_3_32 31

div_by_3_unsigned_down_32:
;;
;; Function signature:
;;
;;   uin32_t div_by_3_unsigned_down_32(uint32_t x);
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
    mov eax, MAGIC_U_3_32       ; rax = M
    imul rax, rdi               ; rax = n * M
    shr rax, P_U_3_32           ; eax = (n * M) >> P_U_3_32
    ret
    
div_by_3_unsigned_up_32:
;;
;; Function signature:
;;
;;   uint32_t div_by_3_unsigned_up_32(uint32_t x);
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
    mov eax, MAGIC_U_3_32       ; eax = M
    imul rax, rdi               ; rax = nu * M
    shr rax, P_U_3_32           ; eax = (nu * M) >> P_U_3_32
    add eax, ecx                ; eax = (nu * M) >> P_U_3_32 + (n > 0)
    ret
    
div_by_3_signed_zero_32:
;;
;; Function signature:
;;
;;   int32_t div_by_3_signed_zero_32(int32_t x);
;;
;; Parameters:
;;
;;   edi: int32_t, dividend
;;
;; Return value:
;;
;;   eax: int32_t, quotient
;;
;; This function calculates sgn(edi) * ceil(|edi| / 3) using
;; the division by multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    movsx rax, edi              ; eax = n
    shr edi, 31                 ; edi = (n < 0)
    imul rax, rax, MAGIC_S_3_32 ; rax = n * M
    sar rax, P_S_3_32           ; eax = (n * M) >> P_S_3_32
    add eax, edi                ; eax = (n * M) >> P_S_3_32 + (n < 0)
    ret
    
div_by_3_signed_down_32:
;;
;; Function signature:
;;
;;   int32_t div_by_3_signed_down_32(int32_t x);
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
    imul rax, rax, MAGIC_S_3_32 ; rax = mu * M
    sar rax, P_S_3_32           ; eax = (mu * M) >> P_S_3_32
    sub eax, edx                ; eax = (mu * M) >> P_S_3_32 - (n == -1)
    ret
    
div_by_3_signed_up_32:    
;;
;; Function signature:
;;
;;   int32_t div_by_3_signed_up_32(int32_t x);
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
    imul rax, rdi, MAGIC_S_3_32 ; rax = nu * M
    sar rax, P_S_3_32           ; eax = (nu * M) >> P_S_3_32
    add eax, ecx                ; eax = (nu * M) >> P_S_3_32 + (n !== 0)
    ret

%define MAGIC_U_7_32 613566757     ; 30 bits
%define S_U_7_32 3
%define MAGIC_S_7_32 -1840700269   ; 31 bits
%define S_S_7_32 2

div_by_7_unsigned_down_32:
;;
;; Function signature:
;;
;;   uin32_t div_by_7_unsigned_down_32(uint32_t x);
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
    imul rax, rdi, MAGIC_U_7_32 ; rax = n * M
    shr rax, 32                 ; rax = (n * M) >> 32
    add rax, rdi                ; rax = ((n * M) >> 32) + n
    shr rax, S_U_7_32           ; rdx = (((n * M) >> 32) + n) >> S_U_7_32
    ret
    
div_by_7_unsigned_up_32:
;;
;; Function signature:
;;
;;   uint32_t div_by_7_unsigned_up_32(uint32_t x);
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
    imul rax, rdi, MAGIC_U_7_32 ; rax = nu * M
    shr rax, 32                 ; rax = (nu * M) >> 32
    add rax, rdi                ; rax = ((nu * M) >> 32) + nu
    shr rax, S_U_7_32           ; rax = ((nu * M) >> 32) + nu) >> S_U_7_32
    add eax, ecx                ; eax = (((nu * M) >> 32) + nu) >> S_U_7_32) + (n > 0)
    ret
    
div_by_7_signed_zero_32:
;;
;; Function signature:
;;
;;   int32_t div_by_7_signed_zero_32(int32_t x);
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
    imul rax, rdi, MAGIC_S_7_32 ; rax = n * M
    sar rax, 32                 ; rax = (n * M) >> 32
    add rax, rdi                ; rax = ((n * M) >> 32) + n
    sar rax, S_S_7_32           ; eax = (((n * M) >> 32) + n) >> S_S_7_32
    add eax, edx                ; eax = (n * M) >> S_S_7_32 + (n < 0)
    ret
    
div_by_7_signed_down_32:
;;
;; Function signature:
;;
;;   int32_t div_by_7_signed_down_32(int32_t x);
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
    imul rax, rdi, MAGIC_S_7_32 ; rax = mu * M
    sar rax, 32                 ; rax = (mu * M) >> 32
    add rax, rdi                ; rax = ((mu * M) >> 32) + mu
    sar rax, S_S_7_32              ; eax = (mu * M) >> S_S_7_32
    sub eax, edx                ; eax = (mu * M) >> S_S_7_32 + (n == -1)
    ret
    
div_by_7_signed_up_32:    
;;
;; Function signature:
;;
;;   int32_t div_by_7_signed_up_32(int32_t x);
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
    imul rax, rdi, MAGIC_S_7_32 ; rax = nu * M
    sar rax, 32                 ; rax = (mu * M) >> 32
    add rax, rdi                ; rax = ((mu * M) >> 32) + n
    sar rax, S_S_7_32           ; rax = (((mu * M) >> 32) + n) >>
                                ;    S_S_7_32
    add eax, ecx                ; eax = ((nu * M) >> S_S_7_32)
                                ;    + (n != 0)
    ret
    
%define MAGIC_U_3_64 12297829382473034411 ; 64 bits
%define P_U_3_64 65
%define P_U_3_64_MINUS_64 1
%define MAGIC_S_3_64 3074457345618258603 ; 62 bits
%define P_S_3_64 63
%define D_S_3_64 1

div_by_3_unsigned_down_64:
;;
;; Function signature:
;;
;;   uin64_t div_by_3_unsigned_down_64(uint64_t x);
;;
;; Parameters:
;;
;;   rdi: uint64_t, dividend
;;
;; Return value:
;;
;;   rax: uint64_t, quotient
;;
;; This function calculates floor(rdi / 3) using the division by
;; multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    mov rax, MAGIC_U_3_64       ; rax = M
    mul rdi                     ; [rdx:rax] = n * M
    shr rdx, P_U_3_64_MINUS_64  ; rdx = (n * M) >> P_U_3_64
    mov rax, rdx
    ret
    
div_by_3_unsigned_up_64:
;;
;; Function signature:
;;
;;   uint64_t div_by_3_unsigned_up_64(uint64_t x);
;;
;; Parameters:
;;
;;   rdi: uint64_t, dividend
;;
;; Return value:
;;
;;   rax: uint64_t, quotient
;;
;; This function calculates ceil(rdi / 3) using the division by
;; multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    xor ecx, ecx
    test rdi, rdi
    setnz cl                    ; rcx = (n > 0)
    sub rdi, rcx                ; rdi = nu = n - (n > 0)
    mov rax, MAGIC_U_3_64       ; rax = M
    mul rdi                     ; [rdx:rax] = nu * M
    shr rdx, P_U_3_64_MINUS_64  ; rdx = (nu * M) >> P_U_3_64
    lea rax, [rdx + rcx]        ; rax = ((nu * M) >> P_U_3_64)
                                ;       + (n > 0)
    ret
    
div_by_3_signed_zero_64:
;;
;; Function signature:
;;
;;   int64_t div_by_3_signed_zero_64(int64_t x);
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
    mov rdx, MAGIC_S_3_64       ; rdx = M
    imul rdx                    ; [rdx:rax] = n * M
    shld rdx, rax, D_S_3_64     ; rax = (n * M) >> P_S_3_64
    lea rax, [rdx + rdi]        ; rax = (n * M) >> P_S_3_64
                                ;        + (n < 0)
    ret
    
div_by_3_signed_down_64:
;;
;; Function signature:
;;
;;   int64_t div_by_3_signed_down_64(int64_t x);
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
    mov rdx, MAGIC_S_3_64         ; rdx = M
    imul rdx                      ; [rdx:rax] = mu * M
    shld rdx, rax, D_S_3_64       ; rdx = (mu * M) >> P_S_3_64
    lea rax, [rdx + rcx - 1]      ; rax = ((mu * M) >> P_S_3_64) + (n != -1) - 1
                                  ;     = ((mu * M) >> P_S_3_64) - (n == -1)
    ret
    
div_by_3_signed_up_64:    
;;
;; Function signature:
;;
;;   int64_t div_by_3_signed_up_64(int64_t x);
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
    mov rax, MAGIC_S_3_64         ; rax = M
    imul rdi                      ; [rdx:rax] = nu * M
    shld rdx, rax, D_S_3_64       ; rdx = (nu * M) >> P_S_3_64
    lea rax, [rdx + rcx]          ; rax = ((mu * M) >> P_S_3_64) 
                                  ;       + (n != 0)
    ret

%define MAGIC_U_21_64 9662580229085955609 ; 64 bits
%define S_U_21_64 5
%define S_U_21_64_MINUS_1 4
%define MAGIC_S_21_64 -4392081922311798003 ; 62 bits
%define S_S_21_64 4


div_by_21_unsigned_down_64:
;;
;; Function signature:
;;
;;   uin64_t div_by_21_unsigned_down_64(uint64_t x);
;;
;; Parameters:
;;
;;   rdi: uint64_t, dividend
;;
;; Return value:
;;
;;   rax: uint64_t, quotient
;;
;; This function calculates floor(rdi / 21) using the division by
;; multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    mov rax, MAGIC_U_21_64      ; rax = M
    mul rdi                     ; [rdx:rax] = n * M
    add rdx, rdi                ; [cf:rdx] = ((n * M) >> 32) + n
    rcr rdx, 1                  ; rdx = (((n * M) >> 32) + n) >> 1
    shr rdx, S_U_21_64_MINUS_1  ; rdx = (((n * M) >> 32) + n) >> S_U_21_64
    mov rax, rdx
    ret
    
div_by_21_unsigned_up_64:
;;
;; Function signature:
;;
;;   uint64_t div_by_21_unsigned_up_64(uint64_t x);
;;
;; Parameters:
;;
;;   rdi: uint64_t, dividend
;;
;; Return value:
;;
;;   rax: uint64_t, quotient
;;
;; This function calculates ceil(rdi / 21) using the division by
;; multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    mov rax, MAGIC_U_21_64      ; rax = M
    xor ecx, ecx
    test edi, edi
    setnz cl                   ; rcx = (n > 0)
    sub rdi, rcx               ; rdi = nu = n - (n > 0)
    mul rdi                    ; [rdx:rax] = n * M
    add rdx, rdi               ; [cf:rdx] = ((n * M) >> 32) + n
    rcr rdx, 1                 ; rdx = (((n * M) >> 32) + n) >> 1
    shr rdx, S_U_21_64_MINUS_1 ; rdx = (((n * M) >> 32) + n) >> S_U_21_64
    lea rax, [rdx + rcx]       ; rax = (((n * M) >> 32) + n) >> S_U_21_64
                               ;       + (n > 0)
    ret
    
div_by_21_signed_zero_64:
;;
;; Function signature:
;;
;;   int64_t div_by_21_signed_zero_64(int64_t x);
;;
;; Parameters:
;;
;;   rdi: int64_t, dividend
;;
;; Return value:
;;
;;   rax: int64_t, quotient
;;
;; This function calculates sgn(rdi) * ceil(|rdi| / 21) using
;; the division by multiplication method.
;;
;; Let n denote the dividend in comments below.
;;
    mov rax, MAGIC_S_21_64      ; rdx = M
    imul rdi                    ; rdx = (n * M) >> 32
    lea rax, [rdx + rdi]        ; rax = ((n * M) >> 32) + n
    sar rax, S_S_21_64          ; rax = (((n * M) >> 32) + n) >> S_S_21_64
    sar rdi, 63                 ; rdi = -(n < 0)
    sub rax, rdi                ; rax = (((n * M) >> 32) + n) >> S_S_21_64
                                ;       + (n < 0)
    ret
    
div_by_21_signed_down_64:
;;
;; Function signature:
;;
;;   int64_t div_by_21_signed_down_64(int64_t x);
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
    mov rax, MAGIC_S_21_64      ; rdx = M
    mov rdx, rdi
    shr rdx, 63                 ; rdx = (n < 0)
    xor rcx, rcx
    cmp rdi, -1
    sete cl                     ; rcx = (n == -1)
    add rdi, rdx                ; rdi = mu = n + (n < 0)
    imul rdi                    ; rdx = (mu * M) >> 32
    lea rax, [rdx + rdi]        ; rax = ((mu * M) >> 32) + mu
    sar rax, S_S_21_64          ; rax = (((n * M) >> 32) + n) >> S_S_21_64
    sub rax, rcx                ; rax = ((((n * M) >> 32) + n) >> S_S_21_64)
                                ;       - (n == -1)
    ret
    
div_by_21_signed_up_64:    
;;
;; Function signature:
;;
;;   int64_t div_by_21_signed_up_64(int64_t x);
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
    mov rax, MAGIC_S_21_64      ; rax = M
    imul rdi                    ; rdx = (nu * M) >> 32
    lea rax, [rdx + rdi]        ; rax = ((mu * M) >> 32) + n
    sar rax, S_S_21_64          ; rax = (((mu * M) >> 32) + n) >> S_S_21_64
    add rax, rcx                ; rax = (nu * M) >> S_S_21_64 + (n !== 0)
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif
