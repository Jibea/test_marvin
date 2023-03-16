BITS 64
section .text
global strchr

strchr:
    xor rax, rax
    xor rcx, rcx

    .loop:
        cmp byte [rdi + rcx], sil; test caractère
        je .found
        cmp byte [rdi + rcx], 0; test fin de chaîne
        je .notfound


        inc rcx; incrémente l'index
        jmp .loop

    .found:
        lea rax, [rdi + rcx]
        jmp .end

    .notfound:
        xor rax, rax
        jmp .end

    .end:
        ret
