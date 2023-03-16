BITS 64

section .text
global strlen

strlen:
    ENTER 0, 0

    xor rax, rax             ; initialisation de compteur à 0

    .loop:
        cmp byte [rdi + rax], 0 ; test de la fin de chaîne
        je .end

        inc rax                 ; incrément du compteur
        jmp .loop

    .end:
        LEAVE
        ret                  ; retour de la fonction