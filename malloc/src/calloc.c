/*
** EPITECH PROJECT, 2021
** calloc
** File description:
** calloc
*/

#include "../include/include.h"

extern chunk_p head_chunk;

void *calloc(size_t size, size_t type_size)
{
    size_t total = type_size * size;
    void *p = NULL;
    unsigned char *i = NULL;

    if (!(p = malloc(total)))
        return (NULL);
    --total;
    for (i = p; total; --total)
        *i++ = 0;
    return (p);
}
