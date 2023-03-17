/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "cesar.h"

int main(int ac, char **av)
{
    if (ac != 4)
        exit(84);
    call_cesar(av);
    return (0);
}
