/*
** EPITECH PROJECT, 2023
** B-ASM-400-NAN-4-1-asmminilibc-guylain.thomas [WSL : Ubuntu]
** File description:
** test_strstr
*/

#include <dlfcn.h>
#include <criterion/criterion.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char *(*my_strstr)(char *str, char *str2);


static void loader(void)
{
    void *handle = dlopen("tests/libasm.so", RTLD_LAZY);
    if (!handle)
        write(2, "./libasm.so: Not found\n", 23);
    else {
        my_strstr = dlsym(handle, "strstr");
    }
}

Test(my_strstr, test_same_strings, .init=loader)
{
    cr_assert_eq(my_strstr("Hello", "Hello"), strstr("Hello", "Hello"));
}

Test(my_strstr, test_different_strings, .init=loader)
{
    cr_assert_eq(my_strstr("Hello", "World"), strstr("Hello", "World"));
}

Test(my_strstr, test_empty_strings, .init=loader)
{
    cr_assert_eq(my_strstr("", ""), strstr("", ""));
}

Test(my_strstr, test_empty_string, .init=loader)
{
    cr_assert_eq(my_strstr("", "Hello"), strstr("", "Hello"));
}

Test(my_strstr, test_empty_string2, .init=loader)
{
    cr_assert_eq(my_strstr("Hello", ""), strstr("Hello", ""));
}

Test(my_strstr, test_empty_string3, .init=loader)
{
    cr_assert_eq(my_strstr("Hello", "l"), strstr("Hello", "l"));
}

Test(my_strstr, test_empty_string4, .init=loader)
{
    cr_assert_eq(my_strstr("Hello", "llo"), strstr("Hello", "llo"));
}