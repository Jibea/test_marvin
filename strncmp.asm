BITS 64

section .text
global strncmp

strncmp:
    xor rax, rax
    xor r10, r10

    .main_loop:
        cmp byte [rdi + rax], 0
        je .end
        cmp byte [rsi + rax], 0
        je .end
        jmp .cmp_str

    .cmp_str:
        mov r8b, [rdi + rax]
        mov r9b, [rsi + rax]
        cmp byte r8b, r9b
        jne .end
        mov r10, rax
        inc r10
        cmp r10, rdx
        je .end
        inc rax
        jmp .main_loop

    .end:
        mov r8b, [rdi + rax]
        mov r9b, [rsi + rax]
        cmp r8b , r9b
        je .end_null
        sub r8b, r9b
        cmp r8b , 0
        jg .end_ret_positive
        jl .end_ret_negative
    .end_null:
        mov rax, 0
        ret
    .end_ret_negative:
        movsx eax, r8b
        ret
    .end_ret_positive:
        movsx eax, r8b
        ret