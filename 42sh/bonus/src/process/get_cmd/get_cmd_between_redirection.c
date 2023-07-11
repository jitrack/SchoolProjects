/*
** EPITECH PROJECT, 2020
** my_str_to_array
** File description:
** my_str_to_array
*/

#include "../../../include/src.h"

static int nbr_ln_n(char const *str, char const sptr, int *count,
                    char const *end)
{
    char quote = 0;

    for (; *str && flag_cmp(*str, end) == 0; str++) {
        if (*str == '"') quote = ((quote == 0) ? (1) : (0));
        if (quote == 0 && *str != sptr && (*(str + 1) == '\0' ||
                flag_cmp(*(str + 1), end) == 1 ||
                *(str + 1) == sptr))
            ++*count;
    }
    return (*count);
}

static char *my_strcpy_flag_m(char const **src, char const *flag)
{
    char *dest = malloc(my_strlen_flag(*src, flag) + 1);
    char *i = dest;
    char quote = 0;

    if (!*src || (*src)[0] == '\0' || !dest) return (NULL);
    for (; *(*src) && (quote == 1 ||
        flag_cmp(*(*src), flag) == 0); ++(*src), ++i) {
        if (*(*src) == '"') {
            quote = ((quote == 0) ? (1) : (0));
            --i;
        } else
            *i = *(*src);
    }
    *i = '\0';
    return (dest);
}

char **get_command_between_redirection(char const *s, char const *sptr,
                                    char const *flag)
{
    int count = 0;
    char **arr = malloc(sizeof(char *) *
                        (nbr_ln_n(s, *sptr, &count, flag) + 1));
    char **y = arr;

    if (!arr) return (NULL);
    for (; y - arr < count; ++s, ++y) {
        *y = my_strcpy_flag_m(&s, "<>| ;");
        if (!*y) return (NULL);
    }
    *y = NULL;
    return (arr);
}
