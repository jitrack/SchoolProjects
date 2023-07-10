/*
** EPITECH PROJECT, 2021
** reallocarray
** File description:
** reallocarray
*/

#include "../include/include.h"
#include <string.h>

extern chunk_p head_chunk;

void *reallocarray(void *ptr, size_t const nb, size_t const size)
{
    chunk_p p = NULL;
    void *new = NULL;
    size_t const total = ALIGN(nb * size);

    if (!size) {
        free(ptr);
        return (NULL);
    }
    if (!ptr)
        return (malloc(total));
    p = GET_CHUNK_FROM_PTR(ptr);
    if (p->is_free)
        return (NULL);
    if (total <= p->size)
        return (ptr);
    if ((new = malloc(total)))
        memcpy(new, ptr, p->size);
    free(ptr);
    return (new);
}
