/*
** EPITECH PROJECT, 2019
** my_free
** File description:
** my_free
*/

#include "my.h"

static void my_free(void *thing, unsigned int nb)
{
    intptr_t *ptr = thing;

    for (; *ptr; ++ptr) {
        if (nb)
            my_free((void *)*ptr, nb - 1);
        free((void *)*ptr);
    }
}

void free_all(void *thing, unsigned int nb)
{
    if (thing) {
        if (nb > 1) my_free(thing, nb - 2);
        free(thing);
    }

}

void free_if(void *elem)
{
    if (elem)
        free(elem);
}
