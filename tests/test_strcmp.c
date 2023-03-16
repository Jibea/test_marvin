/*
** EPITECH PROJECT, 2023
** B-ASM-400-NAN-4-1-asmminilibc-guylain.thomas [WSL : Ubuntu]
** File description:
** test_strcmp
*/

#include <dlfcn.h>
#include <criterion/criterion.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int (*my_strcmp)(const char *str1, const char *str2);

static void loader(void)
{
    void *handle = dlopen("tests/libasm.so", RTLD_LAZY);
    if (!handle)
        write(2, "./libasm.so: Not found\n", 23);
    else {
        my_strcmp = dlsym(handle, "strcmp");
    }
}

Test(my_strcmp, test_same_strings, .init=loader)
{
    cr_assert_eq(my_strcmp("Hello", "Hello"), strcmp("Hello", "Hello"));
}

Test(my_strcmp, test_different_strings, .init=loader)
{
    cr_assert_eq(my_strcmp("Hello", "World"), strcmp("Hello", "World"));
}

Test(my_strcmp, test_empty_strings, .init=loader)
{
    cr_assert_eq(my_strcmp("", ""), strcmp("", ""));
}

Test(my_strcmp, test_empty_string, .init=loader)
{
    cr_assert_eq(my_strcmp("", "Hello"), strcmp("", "Hello"));
}

Test(my_strcmp, test_empty_string2, .init=loader)
{
    cr_assert_eq(my_strcmp("Hello", ""), strcmp("Hello", ""));
}

Test(strcmp, test_strcmp, .init=loader)
{
    cr_assert_eq(my_strcmp("Hello", "Hello"), strcmp("Hello", "Hello"));
}

Test(strcmp, test_strcmp2, .init=loader)
{
    cr_assert_eq(my_strcmp("Hello", "Hello World"), strcmp("Hello", "Hello World"));
}

Test(strcmp, test_strcmp3, .init=loader)
{
    cr_assert_eq(my_strcmp("Hello World", "Hello"), strcmp("Hello World", "Hello"));
}