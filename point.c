/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
    (void)this;
}

// Create additional functions here
static char *Point_str(PointClass *this)
{
    int length = snprintf(NULL, 0, "<%s (%i, %i)>", this->base.__name__, \
                this->x, this->y);
    char *str = calloc(length + 1, sizeof(char));
    sprintf(str, "<%s (%i, %i)>", this->base.__name__, \
                this->x, this->y);
    return str;
}

static Object *Point_Add(PointClass *p1, PointClass *p2)
{
    return (new(Point, (p1->x + p2->x), (p1->y + p2->y)));
}

static Object *Point_Sub(PointClass *p1, PointClass *p2)
{
    return (new(Point, (p1->x - p2->x), (p1->y - p2->y)));
}

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_str,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&Point_Add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Point_Sub,    /* Implement this method for exercice 03 */
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;
