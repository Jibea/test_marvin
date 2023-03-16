/*
** EPITECH PROJECT, 2023
** B-ASM-400-NAN-4-1-asmminilibc-guylain.thomas [WSL : Ubuntu]
** File description:
** test_strcasecmp
*/

#include <dlfcn.h>
#include <criterion/criterion.h>
#include <unistd.h>
#include <stdio.h>
#include <strings.h>

int (*my_strcasecmp)(char *s1, char *s2);

static void loader(void)
{
    void *handle = dlopen("tests/libasm.so", RTLD_LAZY);
    if (!handle)
        write(2, "./libasm.so: Not found\n", 23);
    else {
        my_strcasecmp = dlsym(handle, "strcasecmp");
    }
}

Test(my_strcasecmp, test_same_strings2, .init=loader)
{
    char *str1 = "HELLO";
    char *str2 = "Hallo";
    //cr_assert_eq(my_strcasecmp(str1, str2), strcasecmp(str1, str2));
}

//Test(my_strcasecmp, test, .init=loader)
//{
//    //printf("my %d\n", my_strcasecmp("Cze", "Dze"));
//    //printf("%d", my_strcasecmp("B", "a"));
//    //cr_assert_eq(my_strcasecmp("B", "a"), strcasecmp("B", "a"));
//}
//
//Test(my_strcasecmp, maj_no_diff, .init=loader)
//{
//    int result = my_strcasecmp("abC", "abc");
//    int expected = strcasecmp("abC", "abc");
//
//    cr_assert_eq(result, expected);
//}
//
//Test(my_strcasecmp, maj_diff, .init=loader)
//{
//    int result = my_strcasecmp("abC", "abd");
//    int expected = strcasecmp("abC", "abd");
//
//    cr_assert_eq(result, expected);
//}
//
//
//Test(my_strcasecmp, double_maj, .init=loader)
//{
//    int result = my_strcasecmp("abC", "abC");
//    int expected = strcasecmp("abC", "abC");
//
//    cr_assert_eq(result, expected);
//}
//
//Test(my_strcasecmp, right_maj, .init=loader)
//{
//    int result = my_strcasecmp("abe", "abC");
//    int expected = strcasecmp("abe", "abC");
//
//    cr_assert_eq(result, expected);
//}
//
//Test(my_strcasecmp, no_letter, .init=loader)
//{
//    int result = my_strcasecmp("ab]", "ab]");
//    int expected = strcasecmp("ab]", "ab]");
//
//    cr_assert_eq(result, expected);
//}
//