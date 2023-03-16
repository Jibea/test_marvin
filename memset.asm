BITS 64

section .text

global memset

memset:
        xor rax, rax
        jmp .main_loop

        .main_loop:
            cmp rdx, 0
            je .exit
            mov [rdi + rax], sil
            inc rax
            cmp [rdi + rax], rdx
            jne .main_loop

        .exit:
            mov rax, rdi
            ret