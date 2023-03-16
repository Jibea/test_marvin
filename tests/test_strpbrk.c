/*
** EPITECH PROJECT, 2023
** B-ASM-400-NAN-4-1-asmminilibc-guylain.thomas [WSL : Ubuntu]
** File description:
** test_strpbrk
*/

#include <dlfcn.h>
#include <criterion/criterion.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char *(*my_strpbrk)(const char *str1, const char *accept);

static void loader(void)
{
    void *handle = dlopen("tests/libasm.so", RTLD_LAZY);
    if (!handle)
        write(2, "./libasm.so: Not found\n", 23);
    else {
        my_strpbrk = dlsym(handle, "strpbrk");
    }
}

Test(my_strpbrk, test_same_strings, .init=loader)
{
    cr_assert_eq(my_strpbrk("Hello", "Hello"), strpbrk("Hello", "Hello"));
}

Test(my_strpbrk, test_different_strings, .init=loader)
{
    cr_assert_eq(my_strpbrk("Hello", "World"), strpbrk("Hello", "World"));
}

Test(my_strpbrk, test_empty_strings, .init=loader)
{
    cr_assert_eq(my_strpbrk("", ""), strpbrk("", ""));
}

Test(my_strpbrk, test_empty_string, .init=loader)
{
    cr_assert_eq(my_strpbrk("", "Hello"), strpbrk("", "Hello"));
}

Test(my_strpbrk, test_empty_string2, .init=loader)
{
    cr_assert_eq(my_strpbrk("Hello", ""), strpbrk("Hello", ""));
}

Test(my_strpbrk, basic, .init=loader)
{
    cr_assert_eq(my_strpbrk("Hello", "l"), strpbrk("Hello", "l"));
}

Test(my_strpbrk, null, .init=loader)
{
    cr_assert_eq(my_strpbrk("NULL", "x"), strpbrk("NULL", "x"));
}

Test(my_strpbrk, empty, .init=loader)
{
    cr_assert_eq(my_strpbrk("Hello", ""), strpbrk("Hello", ""));
}

Test(my_strpbrk, empty2, .init=loader)
{
    cr_assert_eq(my_strpbrk("", "Hello"), strpbrk("", "Hello"));
}

Test(my_strpbrk, basic_classic, .init=loader)
{
    cr_assert_eq(my_strpbrk("HelloyTT", "xpmy"), strpbrk("HelloyTT", "xpmy"));
}

Test(my_strpbrk, double_empty, .init=loader)
{
    cr_assert_eq(my_strpbrk("", ""), strpbrk("", ""));
}

Test(my_strpbrk, multiple_chars, .init=loader)
{
    cr_assert_eq(my_strpbrk("Hello", "ol"), strpbrk("Hello", "ol"));
}