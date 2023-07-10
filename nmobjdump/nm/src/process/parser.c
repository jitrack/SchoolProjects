/*
** EPITECH PROJECT, 2021
** parser
** File description:
** parser
*/

#include "nm.h"

static file_p new_file_p(char const *path)
{
    file_p new = malloc(sizeof(file_t));

    if (!new)
        return (NULL);
    new->path = path;
    new->next = NULL;
    new->content = NULL;
    new->prev = NULL;
    new->archi = unknown;
    return (new);
}

static bool add_file(file_p *files, char const *path)
{
    file_p new = new_file_p(path);

    if (!new) return (true);
    if (*files) {
        if ((*files)->prev) {
            (*files)->prev->next = new;
            new->prev = (*files)->prev;
        } else {
            new->prev = *files;
            (*files)->next = new;
        }
        (*files)->prev = new;
    } else
        *files = new;
    return (false);
}

void free_files_list(file_p files)
{
    file_p tmp = NULL;

    if (!files)
        return;
    while (files) {
        tmp = files;
        NEXT(files);
        free(tmp);
    }
}

file_p get_all_files(char const * const *argv)
{
    file_p files = NULL;

    if (!argv)
        return (NULL);
    for (; *argv; ++argv) {
        if (add_file(&files, *argv))
            return (NULL);
    }
    return (files);
}
