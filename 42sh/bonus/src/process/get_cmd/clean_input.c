/*
** EPITECH PROJECT, 2020
** skip_crt
** File description:
** skip_crt
*/

#include "src.h"

static unsigned int get_end(char const *str, char const *flag)
{
    unsigned int end = my_strlen(str);

    for (; end > 0 && flag_cmp(*str, flag) == true; --str, --end);
    return (end);
}

static int new_string_size(char const *str, char const *flag)
{
    unsigned int size = 0;
    char const *end = str + get_end(str, flag);
    bool quote = false;

    for(; str != end && *str; ++str, ++size) {
        if (*str == '"') TOGGLE_BOOL(quote);
        if (flag_cmp(*str, "<>|") && flag_cmp(str[1], " \t") &&
            check_next_caracters(str + 1, "|<>", " \t")) {
            ++size;
        }
        if (quote == false) {
            if (flag_cmp(*str, flag) == true) {
                skip_fl(&str, " \t;", 0, true);
                ++size;
            }
        }
    }
    return ((quote == true) ? (0) : (size));
}

static char *initialize_new_str(char const **i,char const *fl,
                            char const *str, int const size)
{
    char *new_str = malloc(size + 1);

    if (!new_str || size == 0) {
        freeif(new_str);
        return (NULL);
    }
    skip_fl(i, fl, ';', true);
    if (flag_cmp(*(*i), fl) == true) ++*i;
    return (new_str);
}

static inline void check_special_crt(char const i, unsigned char *into)
{
    if (i == '"')
        TOGGLE(*into, 0);
}

static void fill_new_str(char **index, char const **i, unsigned char const into)
{
    static char op = 0;

    if (flag_cmp(*(*i), "<>|") && (*i)[1] && flag_cmp((*i)[1], " \t") &&
        check_next_caracters(*i + 1, "|<>", " \t")) {
        *(*index) = *(*i);
        (*index)[1]  = ' ';
        skip_flag(&*i, " \t", 0, true);
    } else if (!BIT(into, quote_e) && *(*i) == ';') {
        *(*index) = *(*i);
        skip_flag(i, CLEAN_INPUT_FLAG, ';', true);
    } else if (BIT(into, quote_e) ||
            !flag_cmp(*(*i), CLEAN_INPUT_FLAG)) {
        *(*index) = *(*i);
        if (flag_cmp(*(*i), REDIRECTION_OPERATORS) &&
            (op = check_next_caracters
            (*i + 1, REDIRECTION_OPERATORS, CRT_TO_SKIP)))
            skip_flag(i, CRT_TO_SKIP, ';', true);
    } else {
        *(*index) = ' ';
        if (skip_flag(i, CRT_TO_SKIP, ';', true) || op)
            --*index;
    }
    op = false;
}

char *clean_input(char *str)
{
    int const size = new_string_size(str, CLEAN_INPUT_FLAG);
    char const *i = str;
    unsigned char into = 0;
    char *new_str = initialize_new_str(&i, CLEAN_INPUT_FLAG, str, size);
    char *index = new_str;
    char a = 0;

    if (!new_str) return (NULL);
    for (; *i && index - new_str < size; ++i, ++index, ++a) {
        check_special_crt(*i, &into);
        fill_new_str(&index, &i, into);
    }
    *index = '\0';
    freeif(str);
    return (new_str);
}
