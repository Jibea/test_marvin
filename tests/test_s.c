#include <criterion/criterion.h>
#include <criterion/assert.h>
#include <string.h>

Test(strlen, simple_word)
{
    cr_assert_eq(strlen("Hello"), 5);
}
