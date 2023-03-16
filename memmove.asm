BITS 64 

section .text

global memmove

memmove:
    xor rax, rax
    xor rcx, rcx
    xor r8, r8; copy rdx
    xor r9, r9; array

    mov r8, rdx

    .copy_value:
        cmp r8, 0
        je .end
        cmp r8, rcx
        je .main_loop
        mov al, [rsi + rcx]
        mov byte [r9 + rcx], al
        cmp r9, 0
        je .main_loop
        inc rcx
        jmp .copy_value

    .main_loop:
        mov r8, rcx
        xor rcx, rcx
        cmp r8, rcx
        je .end
        cmp byte [rdi + rcx], 0
        je .end
        mov al, [r9 + rcx]
        mov byte [rdi + rcx], al
        inc rcx
        jmp .main_loop

    .end:
        lea rax, [rdi]
        ret