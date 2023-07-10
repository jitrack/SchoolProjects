/*
** EPITECH PROJECT, 2021
** nm
** File description:
** nm
*/

#include <stdint.h>
#include "nm.h"

unsigned int list_len(void *start)
{
    intptr_t *thing = start;
    unsigned int len = 0;

    if (!start) return 0;
    for (; thing ; thing = (intptr_t *)*thing)
        ++len;
    return len;
}

sym_p new_sym_p(void const *sym, char const *name,
                file_archi_t const file_archi)
{
    sym_p new = malloc(sizeof(sym_t));

    new->next = NULL;
    new->prev = NULL;
    new->name = name;
    new->data_64bits = NULL;
    new->data_32bits = NULL;
    if (file_archi == _64bits)
        new->data_64bits = sym;
    else if (file_archi == _32bits)
        new->data_32bits = sym;
    return (new);
}

bool add_sym(sym_p *syms, sym_p new)
{
    if (!new) return (true);
    new->next = NULL;
    new->prev = NULL;
    if (*syms) {
        if ((*syms)->prev) {
            (*syms)->prev->next = new;
            new->prev = (*syms)->prev;
        } else {
            new->prev = *syms;
            (*syms)->next = new;
        }
        (*syms)->prev = new;
    } else
        *syms = new;
    return (false);
}

void free_syms_list(sym_p syms)
{
    sym_p tmp = NULL;

    if (!syms)
        return;
    while (syms) {
        tmp = syms;
        NEXT(syms);
        free(tmp);
    }
}
