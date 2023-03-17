/*
** EPITECH PROJECT, 2022
** cesar
** File description:
** cesar.c (algo)
*/

#include "cesar.h"

static int check_number_to_replace(char *string)
{
    if ((string[0] < '0' || string[0] > '9') && string[0] != '-')
        exit(84);
    for (int i = 1; string[i] != '\0'; i++) {
        if (string[i] < '0' || string[i] > '9')
            exit(84);
    }
    return (atoi(string));
}

static char *modif_each_letter(char *str, int i, int to_replace)
{
    int up_or_lowcase = -1;

    if (str[i] >= 'A' && str[i] <= 'Z')
        up_or_lowcase = UPCASE;
    if (str[i] >= 'a' && str[i] <= 'z')
        up_or_lowcase = LOWCASE;
    if (str[i] >= 'A' && str[i] <= 'z') {
        str[i] += to_replace;
        while ((str[i] > 'Z' && up_or_lowcase == UPCASE) ||
            (str[i] > 'z' && up_or_lowcase == LOWCASE) || str[i] < 0)
            str[i] -= 26;
        while ((str[i] < 'A' && up_or_lowcase == UPCASE) ||
            (str[i] < 'a' && up_or_lowcase == LOWCASE))
            str[i] += 26;
    }
    return (str);
}

static char *cesar(char *str, int to_replace)
{
    for (int i = 0; str[i] != '\0'; i++) {
        str = modif_each_letter(str, i, to_replace);
    }
    return (str);
}

void call_cesar(char **av)
{
    char *message = NULL;
    int fd = 0;
    int to_replace = check_number_to_replace(av[3]);

    message = recup_args(av[1], av[2]);
    message = cesar(message, to_replace);
    fd = open("crypt", O_CREAT | O_WRONLY, 0444);
    write(fd, message, strlen(message));
    close (fd);
    if (strcmp(av[1], "-f") == 0)
        free(message);
}
