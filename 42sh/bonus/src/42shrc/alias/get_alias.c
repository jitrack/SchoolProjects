/*
** EPITECH PROJECT, 2020
** get_alias
** File description:
** get_alias
*/

#include "src.h"

bool get_alias(sh_t *sh, char *line)
{
    alias_t *new = malloc(sizeof(alias_t));

    if (!new || !line || !*line) return (true);
    line[my_strlen(line) - 1] = 0;
    skip_fl((char const **)&line, " \t", 0, false);
    skip_fl((char const **)&line, " \t", 0, true);
    new->entire_cmd = line + my_strlen_crt(line, '=') + 1;
    if ((my_strlen_cmp(line, "'")) != 2 || *new->entire_cmd++ != '\''
        || is_end(new->entire_cmd + my_strlen_crt(new->entire_cmd, '\'') + 1,
        " \t", "\0"))
        return (true);
    new->entire_cmd[my_strlen_crt(new->entire_cmd, '\'')] = 0;
    new->shortcut = line;
    new->shortcut[my_strlen_crt(line, '=')] = 0;
    ADD_NODE(new, sh->alias);
    return (false);
}
