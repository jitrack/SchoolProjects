/*
** EPITECH PROJECT, 2020
** clean_input_utilities
** File description:
** clean_inout_utilities
*/

#include "src.h"

int crt_count(char const *str, char const *fl, int const end)
{
    char const *i = str;
    char quote = 0;

    str += flag_cmp(*str, fl);
    for (; *i && (i - str) < end; i++) {
        if (*i == '"') quote = ((quote == 0) ? (1) : (0));
        if (quote == 0 && flag_cmp(*i, fl) > 0 && flag_cmp(*(i - 1), fl) > 0)
            str++;
    }
    if (quote == 1) {
        my_putstr_ch("Unmatched '\"'.\n", 2);
        return (-1);
    }
    return (i - str);
}
