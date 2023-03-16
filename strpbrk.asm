BITS 64

section .text
global strpbrk

strpbrk:
    xor rax, rax
    xor rcx, rcx
    xor r8, r8
    cmp rsi, 0
    jz .exit
    .main_loop:
        mov al, [rdi + rcx]
        cmp al, 0
        jz .exit
        xor r8, r8
        .inner_loop:
            cmp al, [rsi + r8]
            jz .end
            inc r8
            cmp byte [rsi + r8], 0
            jnz .inner_loop
        inc rcx
        jmp .main_loop
    .exit:
        xor rax, rax
        ret
    .end:
        lea rax, [rdi + rcx]
        ret
