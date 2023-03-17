/*
** EPITECH PROJECT, 2023
** RUSH2
** File description:
** int
*/

#include "object.h"
#include <stdio.h>
#include <stdlib.h>
#include "int.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     justInt;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    this->justInt = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
    (void)this;
}

static char *Int_str(IntClass *this)
{
    int length = snprintf(NULL, 0, "<%s (%i)>", this->base.__name__, \
                this->justInt);
    char *str = calloc(length + 1, sizeof(char));
    sprintf(str, "<%s (%i)>", this->base.__name__, \
                this->justInt);
    return str;
}

static Object *Int_Add(IntClass *p1, IntClass *p2)
{
    return (new(Int, (p1->justInt + p2->justInt)));
}

static Object *Int_Sub(IntClass *p1, IntClass *p2)
{
    return (new(Int, (p1->justInt - p2->justInt)));
}

static Object *Int_Mul(IntClass *p1, IntClass *p2)
{
    return (new(Int, (p1->justInt * p2->justInt)));
}

static Object *Int_Div(IntClass *p1, IntClass *p2)
{
    return (new(Int, (p1->justInt / p2->justInt)));
}

static bool Int_Eq(IntClass *p1, IntClass *p2)
{
    return ((p1->justInt == p2->justInt));
}

static bool Int_Gt(IntClass *p1, IntClass *p2)
{
    return ((p1->justInt > p2->justInt));
}

static bool Int_Lt(IntClass *p1, IntClass *p2)
{
    return ((p1->justInt < p2->justInt));
}

static const IntClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_str,
        .__add__ = (binary_operator_t)&Int_Add,
        .__sub__ = (binary_operator_t)&Int_Sub,
        .__mul__ = (binary_operator_t)&Int_Mul,
        .__div__ = (binary_operator_t)&Int_Div,
        .__eq__ = (binary_comparator_t)&Int_Eq,
        .__gt__ = (binary_comparator_t)&Int_Gt,
        .__lt__ = (binary_comparator_t)&Int_Lt,
    },
    .justInt = 0
};

const Class   *Int = (const Class *)&_description;