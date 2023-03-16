/*
** EPITECH PROJECT, 2023
** B-ASM-400-NAN-4-1-asmminilibc-guylain.thomas [WSL : Ubuntu]
** File description:
** test_strcspn
*/

#include <dlfcn.h>
#include <criterion/criterion.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

size_t (*my_strcspn)(const char *str1, const char *reject);

static void loader(void)
{
    void *handle = dlopen("tests/libasm.so", RTLD_LAZY);
    if (!handle)
        write(2, "./libasm.so: Not found\n", 23);
    else {
        my_strcspn = dlsym(handle, "strcspn");
    }
}

Test(my_strcspn, test_same_strings, .init=loader)
{
    cr_assert_eq(my_strcspn("Hello", "Hello"), strcspn("Hello", "Hello"));
}

Test(my_strcspn, test_different_strings, .init=loader)
{
    cr_assert_eq(my_strcspn("Hello", "World"), strcspn("Hello", "World"));
}

Test(my_strcspn, test_empty_strings, .init=loader)
{
    cr_assert_eq(my_strcspn("", ""), strcspn("", ""));
}

Test(my_strcspn, test_empty_string, .init=loader)
{
    cr_assert_eq(my_strcspn("", "Hello"), strcspn("", "Hello"));
}

Test(my_strcspn, test_empty_string2, .init=loader)
{
    cr_assert_eq(my_strcspn("Hello", ""), strcspn("Hello", ""));
}

Test(my_strcspn, test_different_strings2, .init=loader)
{
    cr_assert_eq(my_strcspn("Hello", "World"), strcspn("Hello", "World"));
}

Test(my_strcspn, test_different_strings3, .init=loader)
{
    cr_assert_eq(my_strcspn("Hello", "World"), strcspn("Hello", "World"));
}

Test(my_strcspn, test_different_strings4, .init=loader)
{
    cr_assert_eq(my_strcspn("Hello", "World"), strcspn("Hello", "World"));
}

Test(my_strcspn, test_different_strings5, .init=loader)
{
    cr_assert_eq(my_strcspn("abc", "d"), strcspn("abc", "d"));
}