/*
** EPITECH PROJECT, 2022
** recup_args.c
** File description:
** recup_args
*/

#include "cesar.h"

char *recup_args(char *param, char *str)
{
    if (strcmp(param, "-f") == 0)
        return (read_file(str));
    else if (strcmp(param, "-s") == 0)
        return (str);
    else
        exit(84);
}
