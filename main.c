/*
** EPITECH PROJECT, 2023
** B-ASM-400-NAN-4-1-asmminilibc-guylain.thomas
** File description:
** main
*/

#include <dlfcn.h>
#include <criterion/criterion.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

void*(*my_memset)(void *str, int c, size_t n);
int (*my_strlen)(const char *str);

static void loader(void)
{
    void *handle = dlopen("tests/libasm.so", RTLD_LAZY);
    if (!handle)
        write(2, "./libasm.so: Not found\n", 23);
    else {
        my_memset = dlsym(handle, "memset");
        my_strlen = dlsym(handle, "strlen");
    }
}

int main()
{
    loader();
    int array[] = {1, 2, 3, 4, 5};
    size_t size = sizeof(int)*5;
    my_memset(array, '0', size);
    my_memset(array, 8, sizeof(char)*3);
    for (int i=0; i < 5; i++)
        printf("%d\n", array[i]);
    return 0;
}