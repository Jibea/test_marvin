/*
** EPITECH PROJECT, 2023
** B-ASM-400-NAN-4-1-asmminilibc-guylain.thomas [WSL : Ubuntu]
** File description:
** test_strncmp
*/

#include <dlfcn.h>
#include <criterion/criterion.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int (*my_strncmp)(const char *str1, const char *str2, size_t n);

static void loader(void)
{
    void *handle = dlopen("tests/libasm.so", RTLD_LAZY);
    if (!handle)
        write(2, "./libasm.so: Not found\n", 23);
    else {
        my_strncmp = dlsym(handle, "strncmp");
    }
}

Test(my_strncmp, test_same_strings, .init=loader)
{
    cr_assert_eq(my_strncmp("Hello", "Hello", 5), strncmp("Hello", "Hello", 5));
}

Test(my_strncmp, test_different_strings, .init=loader)
{
    cr_assert_eq(my_strncmp("Hello", "World", 5), strncmp("Hello", "World", 5));
}

Test(my_strncmp, test_empty_strings, .init=loader)
{
    cr_assert_eq(my_strncmp("", "", 5), strncmp("", "", 5));
}

Test(my_strncmp, test_empty_string, .init=loader)
{
    cr_assert_eq(my_strncmp("", "Hello", 5), strncmp("", "Hello", 5));
}

Test(my_strncmp, test_empty_string2, .init=loader)
{
    cr_assert_eq(my_strncmp("Hello", "", 5), strncmp("Hello", "", 5));
}

Test(my_strncmp, test_different_strings2, .init=loader)
{
    cr_assert_eq(my_strncmp("Hello", "World", 2), strncmp("Hello", "World", 2));
}

Test(my_strncmp, falsee, .init=loader)
{
    cr_assert_eq(my_strncmp("azc", "abc", 3), strncmp("azc", "abc", 3));
}

Test(my_strncmp, basic, .init=loader)
{
    cr_assert_eq(my_strncmp("abc", "abc", 3), strncmp("abc", "abc", 3));
}

Test(my_strncmp, basic2, .init=loader)
{
    cr_assert_eq(my_strncmp("abc", "abz", 2), strncmp("abc", "abz", 2));
}

Test(my_strncmp, basic3, .init=loader)
{
    cr_assert_eq(my_strncmp("abz", "abc", 2), strncmp("abz", "abc", 2));
}

Test(my_strncmp, long_str1, .init=loader)
{
    cr_assert_eq(my_strncmp("azert", "abz", 3), strncmp("azert", "abz", 3));
}

Test(my_strncmp, long_str2, .init=loader)
{
    cr_assert_eq(my_strncmp("azert", "abz", 1), strncmp("azert", "abz", 1));
}

Test(my_strncmp, long_str3, .init=loader)
{
    cr_assert_eq(my_strncmp("azert", "abz", 5), strncmp("azert", "abz", 5));
}

Test(my_strncmp, long_str4, .init=loader)
{
    cr_assert_eq(my_strncmp("Lylian", "L", 1), strncmp("Lylian", "L", 1));
}

Test(my_strncmp, long_str5, .init=loader)
{
    cr_assert_eq(my_strncmp("\0", "\0", 2), strncmp("\0", "\0", 2));
}

Test(my_strncmp, long_str6, .init=loader)
{
    cr_assert_eq(my_strncmp("\0", "\0", 1), strncmp("\0", "\0", 1));
}

Test(my_strncmp, long_str7, .init=loader)
{
    cr_assert_eq(my_strncmp("\0", "\0", 0), strncmp("\0", "\0", 0));
}

Test(my_strncmp, long_str8, .init=loader)
{
    cr_assert_eq(my_strncmp("hello", "hello World", 12), strncmp("hello", "hello World", 12));
}

Test(my_strncmp, long_str9, .init=loader)
{
    cr_assert_eq(my_strncmp("hello", "hello World", 10), strncmp("hello", "hello World", 10));
}