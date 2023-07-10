/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** malloc
*/

#include <stdio.h>
#include "../include/include.h"

chunk_p head_chunk = NULL;

static chunk_p find_smallest_chunk(size_t const size)
{
    chunk_p i = head_chunk;
    chunk_p smallest = NULL;

    if (!head_chunk) return (NULL);
    for (; i; NEXT(i)) {
        if (IS_CHUNK_VALID(i, size)) {
            smallest = i;
            break;
        }
    }
    if (!smallest || smallest->size == size) return (smallest);
    for (; i; NEXT(i)) {
        if (IS_CHUNK_VALID(i, size) && i->size < smallest->size) {
            smallest = i;
            if (smallest->size == size)
                return (smallest);
        }
    }
    return (smallest);
}

static void split_block(chunk_p i, size_t const size)
{
    void *new_chunk_address = i->address + size;
    chunk_p new = new_chunk_address;

    new->address = DATA_START(new_chunk_address);
    new->size = ABS(i->size - size) - META_SIZE;
    new->is_free = true;
    new->next = i->next;
    new->prev = i;
    i->size = size;
    i->next = new;
    if (new->next)
        new->next->prev = new;
    else if (head_chunk)
        head_chunk->prev = new;
}

static inline void add_to_head(chunk_p *node)
{
    if (head_chunk) {
        if (head_chunk->prev) {
            head_chunk->prev->next = *node;
            (*node)->prev = head_chunk->prev;
        }
        head_chunk->prev = *node;
    } else
        (*node)->prev = NULL;
}

static chunk_p extend_heap(size_t const size)
{
    chunk_p b = sbrk(0);
    void *address = NULL;
    size_t const page_size = getpagesize();
    size_t mem_size = page_size * (2 + ((CHUNK_SIZE(size)) / page_size));

    if ((address = sbrk(mem_size)) == INVALID_ADDRESS)
        return (NULL);
    b->size = mem_size - META_SIZE;
    b->address = DATA_START(address);
    b->is_free = false;
    b->next = NULL;
    add_to_head(&b);
    if (ABS(b->size - size) >= CHUNK_SIZE(4))
        split_block(b, size);
    return (b);
}

void *malloc(size_t const size_)
{
    size_t const size = ALIGN(size_);
    chunk_p p = NULL;

    if (!size_)
        return (NULL);
    if (!head_chunk) {
        if (!(p = extend_heap(size)))
            return (NULL);
        head_chunk = p;
        return (p->address);
    }
    if ((p = find_smallest_chunk(size))) {
        if (ABS(p->size - size) >= CHUNK_SIZE(4)) split_block(p, size);
        p->is_free = false;
    } else if (!(p = extend_heap(size)))
        return (NULL);
    return (p->address);
}
