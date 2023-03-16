/*
** EPITECH PROJECT, 2023
** B-ASM-400-NAN-4-1-asmminilibc-guylain.thomas [WSL : Ubuntu]
** File description:
** test_memmove
*/

#include <dlfcn.h>
#include <criterion/criterion.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void *(*my_memmove)(void *dest, void* src, size_t n);

static void loader(void)
{
    void *handle = dlopen("tests/libasm.so", RTLD_LAZY);
    if (!handle)
        write(2, "./libasm.so: Not found\n", 23);
    else {
        my_memmove = dlsym(handle, "memmove");
    }
}

//Test(my_memmove, test_same_strings, .init=loader)
//{
//    char *str1 = "Hello";
//    char *str2 = "Hello";
//    printf("my %s", memmove(str1, str2, 5));
//    //cr_assert_eq(my_memmove(str1, str2, 5), memmove(str1, str2, 5));
//}
//
//Test(my_memmove, test_different_strings, .init=loader)
//{
//    char *str1 = "Hello";
//    char *str2 = "World";
//    cr_assert_eq(my_memmove(str1, str2, 5), memmove(str1, str2, 5));
//}
//
//Test(my_memmove, test_empty_strings, .init=loader)
//{
//    char *str1 = "";
//    char *str2 = "";
//    cr_assert_eq(my_memmove(str1, str2, 0), memmove(str1, str2, 0));
//}
//
//Test(my_memmove, test_empty_string, .init=loader)
//{
//    char *str1 = "";
//    char *str2 = "Hello";
//    cr_assert_eq(my_memmove(str1, str2, 5), memmove(str1, str2, 5));
//}
//
//Test(my_memmove, test_empty_string2, .init=loader)
//{
//    char *str1 = "Hello";
//    char *str2 = "";
//    cr_assert_eq(my_memmove(str1, str2, 0), memmove(str1, str2, 0));
//}
//
//Test(my_memmove, test_empty_string3, .init=loader)
//{
//    char *str1 = "Hello";
//    char *str2 = "World";
//    cr_assert_eq(my_memmove(str1, str2, 0), memmove(str1, str2, 0));
//}
//
//Test(my_memmove, test_empty_string4, .init=loader)
//{
//    char *str1 = "Hello";
//    char *str2 = "World";
//    cr_assert_eq(my_memmove(str1, str2, 1), memmove(str1, str2, 1));
//}