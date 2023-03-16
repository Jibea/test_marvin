/*
** EPITECH PROJECT, 2023
** B-ASM-400-NAN-4-1-asmminilibc-guylain.thomas [WSL : Ubuntu]
** File description:
** test_memset
*/

#include <dlfcn.h>
#include <criterion/criterion.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void *(*my_memset)(void *dest, int c, size_t n);

static void loader(void)
{
    void *handle = dlopen("tests/libasm.so", RTLD_LAZY);
    if (!handle)
        write(2, "./libasm.so: Not found\n", 23);
    else {
        my_memset = dlsym(handle, "memset");
    }
}

Test(my_memset, test_same_strings, .init=loader)
{
    char *str1 = "Hello";
    char *str2 = "Hello";
    my_memset(str1, 'a', 5);
    //cr_assert_eq(my_memset(str1, 'a', 5), memset(str2, 'a', 5));
}
