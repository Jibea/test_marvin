BITS 64

section .text
global strrchr

strrchr:
strchr:
    xor rax, rax
    xor rcx, rcx
    xor rdx, rdx

    .loop:
        cmp byte [rdi + rcx], sil; test caractère
        je .found

        cmp byte [rdi + rcx], 0; test fin de chaîne
        je .check_if_found


        inc rcx; incrémente l'index
        jmp .loop
    .found:
        lea rdx, [rdi + rcx]; mets l'adresse de rdi + rcx dans rdx
        inc rcx
        inc rax

        cmp byte [rdi + rcx], 0
        je .check_if_found

        jmp .loop
    .check_if_found:
        cmp rax, 0
        je .notfound

        mov rax, rdx
        jmp .end
    .notfound:
        mov rax, 0
        jmp .end
    .end:
        ret