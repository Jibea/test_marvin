/*
** EPITECH PROJECT, 2023
** B-PDG-300-NAN-3-1-PDGRUSH2-matthias.gaste
** File description:
** new
*/

#include "new.h"

Object *new(const Class *class, ...)
{
    Object *obj = NULL;
    va_list ap;

    va_start(ap, class);
    if (class == NULL)
        raise("Class is NULL");
    obj = (Object*)malloc(class->__size__);
    if (obj == NULL)
        raise("Malloc failed");
    memcpy(obj, class, class->__size__);
    if (class->__ctor__ != NULL)
        class->__ctor__(obj, &ap);
    va_end(ap);
    return (obj);
}

void delete(Object *ptr)
{
    Class *class = ptr;

    if (ptr == NULL)
        raise("Object is NULL");
    if (class->__dtor__ != NULL)
        class->__dtor__(ptr);
    free(ptr);
}

Object *va_new(const Class *class, va_list *ap)
{
    Object *obj = NULL;

    if (class == NULL)
        raise("Class is NULL");
    obj = (Object*)malloc(class->__size__);
    if (obj == NULL)
        raise("Malloc failed");
    memcpy(obj, class, class->__size__);
    if (class->__ctor__ != NULL)
        class->__ctor__(obj, ap);
    return (obj);
}
