/*
** EPITECH PROJECT, 2020
** block_linked_list
** File description:
** block_linked_list
*/

#include "src.h"

bool add_command_block(block_t **block, char ***cmd, char const separator)
{
    block_t *new = malloc(sizeof(block_t));

    if (!new) return (true);
    if (*block)
        (*block)->prev = new;
    new->next = *block;
    new->prev = NULL;
    new->cmd = cmd;
    new->separator = separator;
    *block = new;
    return (false);
}

void reverse_list(block_t **block)
{
    for (; (*block)->next; *block = (*block)->next);
}

void free_node(block_t *block)
{
    if (block->cmd)
        free_3d_array(block->cmd);
    if (block)
        free(block);
}

void free_cmd_list(block_t **block)
{
    block_t *tmp = *block;

    if (*block)
        do {
            PREV((*block));
            free_node(tmp);
            tmp = *block;
        } while (*block);
    *block = NULL;
}
