/*
** EPITECH PROJECT, 2020
** my_memset
** File description:
** my_memset
*/

void my_memmove(char **str, char const offset)
{
    char *i = *str;

    for (; *i && *(i + offset); ++i)
        *i = *(i + offset);
    *i = 0;
}

