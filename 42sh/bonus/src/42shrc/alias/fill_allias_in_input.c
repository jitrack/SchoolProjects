/*
** EPITECH PROJECT, 2020
** fill_allias_in_input
** File description:
** fill_allias_in_input
*/

#include "src.h"
static bool is_there_an_occurence_flag(char const *s1, char const *s2,
                                  char const *flag)
{
    for (; *s1 && *s2 && s2[1] && *s1 == *s2; ++s1, ++s2);
    return (*s1 == *s2 && (!s1[1] || flag_cmp(s1[1], flag)));
}


static alias_t *is_there_an_alias(alias_t *alias, char const *i)
{
    for (; alias; NEXT(alias)) {
        if(*i == *alias->shortcut &&
           is_there_an_occurence_flag(i, alias->shortcut, " \t|&;\n\0<>")) {
            return (alias);
        }
    }
    return (NULL);
}

static bool fill_alias_in_cmd(char **new_input, char **ni, alias_t *alias,
    unsigned int const rest)
{
    unsigned int len = *ni - *new_input;
    unsigned int entire_cmd_len = my_strlen(alias->entire_cmd);

    if (!(*new_input = realloc(*new_input, len + entire_cmd_len + rest + 1)))
        return (true);
    *ni = *new_input + len;
    my_strcpy(*ni, alias->entire_cmd);
    *ni += entire_cmd_len;
    return (false);
}

char *fill_allias_in_input(sh_t *sh, char *input)
{
    char *new_input = malloc(!input ? 0 : my_strlen(input) + 1);
    char *ni = new_input;
    alias_t *alias = NULL;

    if (!new_input || !input) return (NULL);
    for (char const *i = input; *i; ++i, ++ni) {
        if (!(alias = is_there_an_alias(sh->alias, i))) {
            *ni = *i;
        } else {
            fill_alias_in_cmd(&new_input, &ni, alias, my_strlen(i + 
            my_strlen(alias->shortcut)));
            i += my_strlen(alias->shortcut) - 1;
        }
    }
    *--ni = 0;
    if (alias)
        free(input);
    return ((alias) ? (new_input) : (input));
}
