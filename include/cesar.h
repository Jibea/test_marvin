/*
** EPITECH PROJECT, 2022
** cesar.h
** File description:
** cesar.h
*/

#pragma once

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define UPCASE 0
#define LOWCASE 1

void call_cesar(char **av);
char *read_file(char *filepath);
char *recup_args(char *param, char *str);
