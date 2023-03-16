/*
** EPITECH PROJECT, 2023
** B-ASM-400-NAN-4-1-asmminilibc-guylain.thomas [WSL : Ubuntu]
** File description:
** test_strchr
*/

#include <dlfcn.h>
#include <criterion/criterion.h>
#include <unistd.h>
#include <string.h>

char *(*my_strchr)(char *str, char c);
char *(*my_strrchr)(char *str, char c);
//void*(*my_memset)(void *str, int c, size_t n);
//void *(*my_memcpy)(void *dest, void *src, size_t n);

static void loader(void)
{
    void *handle = dlopen("tests/libasm.so", RTLD_LAZY);
    if (!handle)
        write(2, "./libasm.so: Not found\n", 23);
    else {
        //int (*strlen)(const char *str) = dlsym(handle, "strlen");
        my_strchr = dlsym(handle, "strchr");
        my_strrchr = dlsym(handle, "strrchr");
        //my_memset = dlsym(handle, "memset");
        //my_memcpy = dlsym(handle, "memcpy");
    }
}

Test(my_strchr, test_first_occurence, .init=loader)
{
    char *str = "Hello World";
    cr_assert_eq(my_strchr(str, 'H'), str);
}

Test(my_strchr, test_last_occurence, .init=loader)
{
    cr_assert_eq(my_strchr("Hello World", 'd'), strchr("Hello World", 'd'));
}

Test(my_strchr, test_middle_occurence, .init=loader)
{
    char *str = "Hello World";
    cr_assert_eq(my_strchr(str, 'o'), str + 4);
}

Test(my_strchr, test_multiple_occurences, .init=loader)
{
    char *str = "Hello World";
    cr_assert_eq(my_strchr(str, 'l'), str + 2);
}

Test(my_strchr, test_no_occurences, .init=loader)
{
    cr_assert_eq(my_strchr("Hello", 'z'), NULL);
}

Test(my_strchr, test_null_char, .init=loader)
{
    char *str = "Hello World";
    cr_assert_eq(my_strchr("Hello World", '\0'), strchr("Hello World", '\0'));
}


Test(my_strchr, test_empty_string_and_char, .init=loader)
{
    char *str = "";
    cr_assert_eq(my_strchr(str, '\0'), str);
}



Test(my_strrchr, test_first_occurence, .init=loader)
{
    cr_assert_eq(my_strrchr("Hello World", 'H'), strrchr("Hello World", 'H'));
}

Test(my_strrchr, test_last_occurence, .init=loader)
{
    cr_assert_eq(my_strrchr("Hello World", 'd'), strrchr("Hello World", 'd'));
}

Test(my_strrchr, test_middle_occurence, .init=loader)
{
    char *str = "Hello World";
    cr_assert_eq(my_strrchr(str, 'o'), str + 7);
}

Test(my_strrchr, test_multiple_occurences, .init=loader)
{
    char *str = "Hello World";
    cr_assert_eq(my_strrchr(str, 'l'), str + 9);
}

Test(my_strrchr, test_no_occurences, .init=loader)
{
    cr_assert_eq(my_strrchr("Hello", 'z'), NULL);
}

Test(my_strrchr, test_null_char, .init=loader)
{
    char *str = "Hello World";
    cr_assert_eq(my_strrchr(str, '\0'), strrchr("Hello World", '\0'));
}

Test(my_strrchr, test_empty_string_and_char, .init=loader)
{
    char *str = "";
    cr_assert_eq(my_strrchr(str, '\0'), str);
}

//Test(my_memset, test_with_char, .init=loader)
//{
//    char * str1 = my_memset("Hello World", 'a', sizeof(char)*5);
//    char *str2 = memset("Hello World", 'a', sizeof(char)*5);
//    cr_assert_eq(str1, str2);
//}

//Test(my_memset, test2, .init=loader)
//{
//    char str[12] = "Hello World";
//    cr_assert_eq(my_memset(str, 'a', 0), str);
//    cr_assert_str_eq(str, "Hello World");
//}

//Test(my_memset, test_with_int, .init=loader)
//{
//    int str[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
//    cr_assert_eq(my_memset(str, 0, (sizeof(int)*5)), str);
//    cr_assert_eq(str[0], 0);
//    cr_assert_eq(str[1], 0);
//    cr_assert_eq(str[2], 0);
//    cr_assert_eq(str[3], 0);
//    cr_assert_eq(str[4], 0);
//    cr_assert_eq(str[5], 6);
//    cr_assert_eq(str[6], 7);
//    cr_assert_eq(str[7], 8);
//    cr_assert_eq(str[8], 9);
//    cr_assert_eq(str[9], 10);
//    cr_assert_eq(str[10], 11);
//    cr_assert_eq(str[11], 12);
//}
//Test(my_memset, test_with_char_outofrange, .init=loader)
//{
//    char str[12] = "Hello World";
//    cr_assert_eq(my_memset(str, 'r', (sizeof(char)*45)), str);
//    cr_assert_str_eq(str, "rrrrrrrrrrrr");
//}
//
//Test(my_memcpy, test_with_char, .init=loader)
//{
//    char str[12] = "Hello World";
//    char dest[12] = "World";
//    cr_assert_eq(my_memcpy(dest, str, 5), dest);
//    cr_assert_str_eq(dest, "World World");
//}

//Test(my_memcpy, test_with_int, .init=loader)
//{
//    int str[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
//    int dest[12] = {12,11,10,9,8,7,6,5,4,3,2,1};
//    cr_assert_eq(my_memcpy(dest, str, (sizeof(int)*5)), dest);
//    cr_assert_eq(dest[0], 1);
//    cr_assert_eq(dest[1], 2);
//    cr_assert_eq(dest[2], 3);
//    cr_assert_eq(dest[3], 4);
//    cr_assert_eq(dest[4], 5);
//    cr_assert_eq(dest[5], 7);
//    cr_assert_eq(dest[6], 8);
//    cr_assert_eq(dest[7], 9);
//    cr_assert_eq(dest[8], 10);
//    cr_assert_eq(dest[9], 11);
//    cr_assert_eq(dest[10], 12);
//    cr_assert_eq(dest[11], 1);
//}
//
//Test(my_memcpy, test_with_char_outofrange, .init=loader)
//{
//    char str[12] = "Hello World";
//    char dest[12] = "World";
//    cr_assert_eq(my_memcpy(dest, str, (sizeof(char)*45)), dest);
//    cr_assert_str_eq(dest, "World World");
//}
