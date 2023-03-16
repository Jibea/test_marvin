BITS 64

section .text
global strcmp

strcmp:
    xor rax, rax

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
        mov rax, -1
        ret
    .end_ret_positive:
        mov rax, 1
        ret