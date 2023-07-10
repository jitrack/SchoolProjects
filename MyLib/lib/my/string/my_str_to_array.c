/*
** EPITECH PROJECT, 2020
** my_str_to_array
** File description:
** my_str_to_array
*/

#include "my.h"

char **str_to_array(char const *str, char const *sptr)
{
    unsigned int nb_words = count_nbr_words(str, sptr);
    char **array = malloc(sizeof(char *) * (nb_words + 1));
    char **y = array;

    if (!array || !*str || !(*y++ = my_strcpy_m_to_crt(str, *sptr)))
        return (NULL);
    for (; *str && y - array < nb_words; ++str, ++y) {
        skip_to_next_word(&str, sptr, 0);
        if (!(*y = my_strcpy_m_to_crt(str, *sptr)))
            return (NULL);
    }
    *y = NULL;
    return (array);
}

