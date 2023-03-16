BITS 64

section .text

global strcspn

strcspn:
    xor rax, rax
    xor rcx, rcx
    xor r8, r8
    .main_loop:
        mov al, [rdi + rcx]
        cmp al, 0
        jz .end_str
        xor r8, r8
        .inner_loop:
            cmp al, [rsi + r8]
            je .found
            cmp byte [rsi + r8], 0
            jz .end_reject
            inc r8
            cmp byte [rsi + r8], 0
            jnz .inner_loop
        inc rcx
        jmp .main_loop
    .end_str:
        cmp rcx, 0
        jz .exit
        mov rax, rcx
        ret
    .exit:
        xor rax, rax
        ret
    .end_reject:
        call strlen
        ret
    .found:
        mov rax, rcx
        ret

strlen:
    xor rax, rax
    .loop:
        cmp byte [rdi + rax], 0
        je .end
        inc rax
        jmp .loop
    .end:
        ret