/*
** EPITECH PROJECT, 2020
** str_compare_2
** File description:
** compare two string in alphabetical order
*/

#include "my.h"

bool is_there_an_occurence(char const *s1, char const *s2)
{
    for (; *s1 && *s2 && s2[1] && *s1 == *s2; ++s1, ++s2);
    return (*s1 == *s2);
}

short int find_word_in_list(char const *line, char const * const *list,
                            char const *end)
{
    for (register char const * const *i = list; *i; ++i)
        if (!(strcmp_to_flag(line, *i, end)))
            return (i - list);
    return (-1);
}

unsigned int count_nbr_words(char const *str, char const *sptr)
{
    char const *end = str + get_end(str, sptr);
    unsigned int count = 1;

    for (; *str && str != end; str++)
        if (flag_cmp(*str, sptr)) {
            ++count;
            skip_string_flag(&str, sptr, 0, true);
        }
    return (count);
}

unsigned int get_end(char const *str, char const *flag)
{
    char const *end = str + my_strlen(str);

    for (; *end && end != str && flag_cmp(*end, flag); --end);
    return (end - str);
}
