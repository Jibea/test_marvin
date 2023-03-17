/*
** EPITECH PROJECT, 2022
** read_file.c
** File description:
** read_file
*/

#include "cesar.h"

char *read_file(char *filepath)
{
    struct stat buf;
    char *buffer = NULL;
    int fd = 0;
    size_t size = 0;

    stat(filepath, &buf);
    size = buf.st_size;
    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        exit (84);
    buffer = malloc(sizeof(char) * (size + 1));
    if (read(fd, buffer, size) == -1)
        exit(84);
    if (buffer == NULL)
        exit (84);
    buffer[size] = '\0';
    return (buffer);
}
