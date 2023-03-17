/*
** EPITECH PROJECT, 2023
** RUSH2
** File description:
** char
*/

#include <stdio.h>
#include "char.h"
#include "new.h"

typedef struct
{
    Class   base;
    char    x;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
    (void)this;
}

// Create additional functions here
static char *Char_str(CharClass *this)
{
    int length = snprintf(NULL, 0, "<%s (%c)>", this->base.__name__, \
                this->x);
    char *str = calloc(length + 1, sizeof(char));
    sprintf(str, "<%s (%c)>", this->base.__name__, \
                this->x);
    return str;
}

static Object *Char_Add(CharClass *p1, CharClass *p2)
{
    return (new(Char, (p1->x + p2->x)));
}

static Object *Char_Sub(CharClass *p1, CharClass *p2)
{
    return (new(Char, (p1->x - p2->x)));
}

static Object *Char_Mul(CharClass *p1, CharClass *p2)
{
    return (new(Char, (p1->x * p2->x)));
}

static Object *Char_Div(CharClass *p1, CharClass *p2)
{
    if (p2->x != 0) {
        return (new(Char, (p1->x / p2->x)));
    } else {
        return (new(Char, 0));
    }
}

static bool Char_Eq(CharClass *p1, CharClass *p2)
{
    if (p2->x == p1->x) {
        return (true);
    } else {
        return (false);
    }
}

static bool Char_Gt(CharClass *p1, CharClass *p2)
{
    if (p1->x > p2->x) {
        return (true);
    } else {
        return (false);
    }
}

static bool Char_Lt(CharClass *p1, CharClass *p2)
{
    if (p1->x < p2->x) {
        return (true);
    } else {
        return (false);
    }
}

static const CharClass _description = {
        {   /* Class struct */
            .__size__ = sizeof(CharClass),
            .__name__ = "Char",
            .__ctor__ = (ctor_t)&Char_ctor,
            .__dtor__ = (dtor_t)&Char_dtor,
            .__str__ = (to_string_t)&Char_str,    /* Implement this method for exercice 02 */
            .__add__ = (binary_operator_t)&Char_Add,    /* Implement this method for exercice 03 */
            .__sub__ = (binary_operator_t)&Char_Sub,    /* Implement this method for exercice 03 */
            .__mul__ = (binary_operator_t)&Char_Mul,
            .__div__ = (binary_operator_t)&Char_Div,
            .__eq__ = (binary_comparator_t)&Char_Eq,
            .__gt__ = (binary_comparator_t)&Char_Gt,
            .__lt__ = (binary_comparator_t)&Char_Lt
        },
        .x = 0,
};

const Class   *Char = (const Class *)&_description;
