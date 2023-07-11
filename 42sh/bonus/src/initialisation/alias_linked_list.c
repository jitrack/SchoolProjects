/*
** EPITECH PROJECT, 2020
** alias_linked_list
** File description:
** alias_linked_list
*/

#include "src.h"

bool add_alias(alias_t **alias, char *shortcut, char *entire_cmd)
{
    alias_t *new = malloc(sizeof(alias_t));

    if (!new) return (true);
    new->next = *alias;
    new->shortcut = shortcut;
    new->entire_cmd = entire_cmd;
    *alias = new;
    return (false);
}

void free_alias_node(alias_t *alias)
{
    if (alias)
        free(alias);
}

void free_alias_list(alias_t **alias)
{
    alias_t *tmp = *alias;

    if (*alias)
        do {
            NEXT((*alias));
            free_alias_node(tmp);
            tmp = *alias;
        } while (*alias);
    *alias = NULL;
}
