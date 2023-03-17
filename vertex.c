/*
** EPITECH PROJECT, 2023
** RUSH2
** File description:
** vertex
*/

#include <stdio.h>
#include "vertex.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x, y, z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
    (void)this;
}

// Create additional functions here
static char *Vertex_str(VertexClass *this)
{
    int length = snprintf(NULL, 0, "<%s (%i, %i, %i)>", this->base.__name__, \
                this->x, this->y, this->z);
    char *str = calloc(length + 1, sizeof(char));
    sprintf(str, "<%s (%i, %i, %i)>", this->base.__name__, \
                this->x, this->y, this->z);
    return str;
}

static Object *Vertex_Add(VertexClass *v1, VertexClass *v2)
{
    return (new(Vertex, (v1->x + v2->x), (v1->y + v2->y), (v1->z + v2->z)));
}

static Object *Vertex_Sub(VertexClass *v1, VertexClass *v2)
{
    return (new(Vertex, (v1->x - v2->x), (v1->y - v2->y), (v1->z - v2->z)));
}

static const VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_str,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&Vertex_Add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Vertex_Sub,    /* Implement this method for exercice 03 */
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
        },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class   *Vertex = (const Class *)&_description;
