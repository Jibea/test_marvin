/*
** EPITECH PROJECT, 2023
** RUSH2
** File description:
** float
*/

#include <stdio.h>
#include "float.h"
#include "new.h"

typedef struct
{
    Class   base;
    float     m;
}   FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    this->m = va_arg(*args, double);
}

static void Float_dtor(FloatClass *this)
{
    (void)this;
}

// Create additional functions here
static char *Float_str(FloatClass *this)
{
    int length = snprintf(NULL, 0, "<%s (%f)>", this->base.__name__, \
                this->m);
    char *str = calloc(length + 1, sizeof(char));
    sprintf(str, "<%s (%f)>", this->base.__name__, \
                this->m);
    return str;
}

static Object *Float_Add(FloatClass *f1, FloatClass *f2)
{
    return (new(Float, (f1->m + f2->m)));
}

static Object *Float_Sub(FloatClass *f1, FloatClass *f2)
{
    return (new(Float, (f1->m - f2->m)));
}

static Object *Float_Mul(FloatClass *f1, FloatClass *f2)
{
    return (new(Float, (f1->m * f2->m)));
}

static Object *Float_Div(FloatClass *f1, FloatClass *f2)
{
    return (new(Float, (f1->m / f2->m)));
}

static bool Float_Equal(FloatClass *f1, FloatClass *f2)
{
    if (f1->m == f2->m)
        return (true);
    return (false);
}

static bool Float_Gt(FloatClass *f1, FloatClass *f2)
{
    if (f1->m > f2->m)
        return (true);
    return (false);
}

static bool Float_Lt(FloatClass *f1, FloatClass *f2)
{
    if (f1->m < f2->m)
        return (true);
    return (false);
}

static const FloatClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_str,
        .__add__ = (binary_operator_t)&Float_Add,
        .__sub__ = (binary_operator_t)&Float_Sub,
        .__mul__ = (binary_operator_t)&Float_Mul,
        .__div__ = (binary_operator_t)&Float_Div,
        .__eq__ = (binary_comparator_t)&Float_Equal,
        .__gt__ = (binary_comparator_t)&Float_Gt,
        .__lt__ = (binary_comparator_t)&Float_Lt
    },
    .m = 0
};

const Class   *Float = (const Class *)&_description;
