/*
** EPITECH PROJECT, 2019
** my_str_isnum
** File description:
** my_str_isnum
*/

char is_num(char const *str)
{
    for (; *str ;++str)
        if ((*str < '0' || *str > '9') && *str != '-')
            return (1);
    return (0);
}

char is_alpha(char const *str)
{
    for (char const *i = str; *str; str++) {
        if (!((*i >= 48 && *i <= 57)
            || (*i >= 65 && *i <= 90)
            || (*i >= 97 && *i <= 122)))
            return (0);
    }
    return (1);
}
