BITS 64

section .text
global memcpy

memcpy:
    xor rax, rax
    xor rcx, rcx

    .loop:
        cmp byte [rdi + rcx], 0
        je .end
        cmp byte [rsi + rcx], 0
        je .end
        mov rax, [rsi + rcx]
        mov [rdi + rcx], rax
        inc rcx
        cmp rcx, rdx
        jne .loop
    .end:
        mov rax, rdi
        ret