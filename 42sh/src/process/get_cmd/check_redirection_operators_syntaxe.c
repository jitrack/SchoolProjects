/*
** EPITECH PROJECT, 2020
** check_redirection_operators_syntaxe
** File description:
** check_redirection_operators_syntaxe
*/

#include "src.h"

char check_redirection_operators_syntaxe(char const *str)
{
    char const operator = *str;

    ++str;
    if (operator == '|') {
        if (check_next_caracters(str, "<>", " |"))
            return (CHEVRON_SYNTAXE_ERROR);
        else if (*str == '|')
            return (THERE_IS_OR);
        else if (*str == ' ' && check_next_caracters(str, "|\0", " "))
            return (PIPE_SYNTAXE_ERROR);
        else if (check_next_caracters(str, "<>\0", " "))
            return (CHEVRON_SYNTAXE_ERROR);
    } else if (operator == '<' || operator == '>')
        if ((*str == ' ' && check_next_caracters(str, "<|>\0", " ")) ||
            (*str == operator && check_next_caracters(str + 1, "<|>\0", " ")))
            return (CHEVRON_SYNTAXE_ERROR);
    return (0);
}
