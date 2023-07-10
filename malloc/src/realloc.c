/*
** EPITECH PROJECT, 2021
** realloc
** File description:
** realloc
*/

#include "../include/include.h"
#include <string.h>

extern chunk_p head_chunk;

void *realloc(void *ptr, size_t size)
{
    chunk_p p = NULL;
    void *new = NULL;

    if (!size) {
        free(ptr);
        return (NULL);
    }
    if (!ptr)
        return (malloc(size));
    p = GET_CHUNK_FROM_PTR(ptr);
    if (p->is_free)
        return (NULL);
    if (ALIGN(size) <= p->size)
        return (ptr);
    if ((new = malloc(size)))
        memcpy(new, ptr, p->size);
    free(ptr);
    return (new);
}
