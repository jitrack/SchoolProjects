/*
** EPITECH PROJECT, 2020
** str_compare_2
** File description:
** compare two string in alphabetical order
*/

#include <stdbool.h>

bool is_there_an_occurence(char const *s1, char const *s2)
{
    for (; *s1 && *s2 && s2[1] && *s1 == *s2; ++s1, ++s2);
    return (*s1 == *s2);
}
