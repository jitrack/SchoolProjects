/*
** EPITECH PROJECT, 2021
** include
** File description:
** include
*/

#ifndef __INCLUDE__
#define __INCLUDE__

#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>

#define ALIGN(x) ((x + sizeof(void *) - 1) & ~(sizeof(void *) - 1))
#define META_SIZE sizeof(chunk_t)
#define CHUNK_SIZE(s) META_SIZE + s
#define DATA_START(a) META_SIZE + a
#define GET_CHUNK_FROM_PTR(a) ((struct chunk_s *)(a - META_SIZE))
#define INVALID_ADDRESS (void *)-1
#define NEXT(l) l = l->next
#define PREV(l) l = l->prev
#define IS_CHUNK_VALID(i, size) i->is_free && i->size >= size
#define ABS(n) n < 0 ? (~n + 1) : n

typedef struct chunk_s {
    size_t size;
    struct chunk_s *next;
    struct chunk_s *prev;
    bool is_free;
    void *address;
} chunk_t;

typedef chunk_t *chunk_p;

void *malloc(size_t const size);
void show_alloc_mem();
void free(void *ptr);
void *realloc(void *ptr, size_t size);
void *calloc(size_t size, size_t nb);
void *reallocarray(void *ptr, size_t const nb, size_t const size);

#endif /* __INCLUDE__ */
