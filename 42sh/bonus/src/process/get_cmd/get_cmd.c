/*
** EPITECH PROJECT, 2020
** get_cmd
** File description:
** get_cmd
*/

#include "../../../include/src.h"

static char get_separator(char const **str)
{
    char const separator = **str;
    char ret = (separator == ';') ? (comma) : (separator == '&') ? (and) : (or);

    if (*(*str) == 0) return (end);
    else if (ret == comma);
    else if ((check_next_caracters(*str + 1, "&|", " ") == false ||
        is_end(*str, " |&", ";") || check_next_caracters(*str +
        (my_strlen_flag(*str + 1, "&|") + my_strlen_flag(*str +
        my_strlen_flag(*str + 1, "&|") + 1, "&|") + 2), "&|;", " "))) {
        my_printf(1, "Invalid null command.\n");
        return (84);
    }
    skip_fl(str, "&| ;", 0, true);
    return (ret);
}

static bool parse_command(block_t **block, char *str)
{
    char const *i = str;
    char ***cmd = NULL;
    char ret = 0;

    if (!str) return (true);
    while (*i) {
        if (!(cmd = create_3d_array(&i))) return (true);
        skip_fl(&i, ";&|", 0, false);
        if ((ret = get_separator(&i)) == 84 ||
            add_command_block(block, cmd, ret)) return (true);
        if (!*block) return (true);
    }
    freeif(str);
    return (false);
}

char get_cmd(sh_t *sh)
{
    char *input = NULL;
    size_t len = 0;

    if (sh->isatty)
        my_printf(1, "%s $> ", sh->pwd);
    catch_all_signal();
    if (getline(&input, &len, stdin) == EOF) return (EOF);
    else if (input) {
        input[my_strlen_crt(input, '\n')] = 0;
        input = fill_allias_in_input(sh, input);
        if (parse_command(&sh->block, clean_input(input)))
            return (true);
    }
    reverse_list(&sh->block);
    return (false);
}
