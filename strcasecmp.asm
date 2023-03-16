section .text
global strcasecmp

strcasecmp:
    xor rax, rax
    xor r8, r8
    xor r9, r9
    xor rcx, rcx

    .main_loop:
        cmp byte [rdi + rcx], 0
        je .end
        cmp byte [rsi + rcx], 0
        je .end
        mov r8b, [rdi + rcx]
        mov r9b, [rsi + rcx]
        jmp .check_if_upper_r8

    .check_if_upper_r8:
        cmp byte r8b, 90
        jg .check_if_upper_r9
        cmp byte r8b, 65
        jl .check_if_upper_r9
        add r8b, 32

    .check_if_upper_r9:
        cmp byte r9b, 90
        jg .compare_chars
        cmp byte r9b, 65
        jl .compare_chars
        add r9b, 32

    .compare_chars:
        cmp r8b, r9b
        jne .end
        inc rcx
        jmp .main_loop

    .end:
        sub r8b, r9b
        movsx rax, r8b
        ret