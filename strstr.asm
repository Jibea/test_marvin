BITS 64 

section .text
global strstr

strstr:
    xor rax, rax
    xor rcx, rcx

    .main_loop:
        mov al, [rdi + rcx]
        cmp byte [rsi], 0
        je .exit_no_string_to_found
        cmp al, 0
        je .exit_not_found
        xor r8, r8
        xor r9, r9
        mov r9, rcx
        cmp al, [rsi + r8]
        je .innerloop
        inc rcx
        jmp .main_loop

        .innerloop:
            inc r8
            cmp byte [rsi + r8], 0
            je .exit_found
            mov al, [rdi + r9]
            cmp al, 0
            je .exit_not_found
            inc r9
            jmp .innerloop

    .exit_found:
        lea rax, [rdi + rcx]
        ret
    .exit_no_string_to_found:
        lea rax, [rdi]
        ret

    .exit_not_found:
        xor rax, rax
        ret