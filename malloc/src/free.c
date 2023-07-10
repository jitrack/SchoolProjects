/*
** EPITECH PROJECT, 2021
** free
** File description:
** free
*/

#include "../include/include.h"

extern chunk_p head_chunk;

static chunk_p is_malloc_mem_address(void const *ptr)
{
    for (chunk_p i = head_chunk; i; NEXT(i))
        if (i->address == ptr)
            return (i);
    return (NULL);
}

static inline void check_chuknk_side(chunk_p *to_connect,
                                    chunk_p *p, size_t *size)
{
    if (*to_connect && (*to_connect)->is_free) {
        *size += CHUNK_SIZE((*to_connect)->size);
        NEXT((*to_connect));
    }
    if ((*p)->prev && *p != head_chunk && (*p)->prev->is_free) {
        PREV((*p));
        *size += (*p)->size;
    }
}

void free(void *ptr)
{
    chunk_p p = NULL;
    chunk_p to_connect = NULL;
    size_t size = 0;

    if (!head_chunk || !ptr || !(p = is_malloc_mem_address(ptr)) || p->is_free)
        return;
    size = p->size;
    to_connect = p->next;
    check_chuknk_side(&to_connect, &p, &size);
    p->is_free = true;
    p->size = size;
    p->next = to_connect;
    if (to_connect)
        to_connect->prev = p;
    if (!p->next)
        head_chunk->prev = p;
}
