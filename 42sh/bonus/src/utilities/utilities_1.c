/*
** EPITECH PROJECT, 2020
** utilities_1
** File description:
** utilities_1
*/

#include "src.h"

int strcmp_quote(char const *s1, char const *s2)
{
    char quote = false;

    if (!s1 || !s2) return (84);
    if (*s2 == '"') {
        quote = true;
        ++s2;
    }
    for (; *s1 && *s2 && *s1 == *s2 && *(s2 + 1) != '"'; ++s1, ++s2) {
        if (*s2 == '"') quote = ((quote == false) ? (1) : (0));
        if (quote == false && *s2 == ' ') return (1);
    }
    return (*s1 - *s2);
}

bool skip_fl(char const **i, char const *fl, char const end, bool const check)
{
    if (!*i || *(*i) == 0) return (false);
    if (check == flag_cmp(*(*i), fl))
        for (; *(*i) && flag_cmp(*(*i), fl) == check; ++*i);
    return (*(*i) == end);
}

bool skip_flag(char const **i, char const *fl, char const end, bool const check)
{
    if (!*i || *(*i) == 0) return (false);
    if (check == flag_cmp(*(*i), fl))
        for (; *(*i) && flag_cmp(*(*i), fl) == check &&
                 *(*i + 1) && flag_cmp(*(*i + 1), fl) == check; ++*i);
    return (*(*i + 1) == end);
}

bool check_next_caracters(char const *str, char const *flag,
                        char const *crt_to_skip)
{
    if (!str) return (false);
    for (; *str && flag_cmp(*str, crt_to_skip) == true; ++str);
    return (flag_cmp(*str, flag));
}

bool is_end(char const *str, char const *flag, char const *end_flag)
{
    for (; *str; ++str)
        if (flag_cmp(*str, flag) && (!str[1] || flag_cmp(*str, end_flag)))
            return (true);
    return (false);
}
