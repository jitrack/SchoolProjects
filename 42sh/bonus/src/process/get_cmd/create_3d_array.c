/*
** EPITECH PROJECT, 2020
** create_3d_array
** File description:
** create_3d_array
*/

#include "src.h"

static char check_if_syntax_error(char const **str, char const *flag)
{
    char const cur_flag = ((*(*str) == '|') ? (-1) :
                        (*(*str) == '<' || *(*str) == '>') ? (-2) : (0));
    char error = 0;

    if ((*str)[1] == 0) return (cur_flag);
    if ((error = check_redirection_operators_syntaxe(*str)) != 0)
        return (error);
    for (; flag_cmp(*(*str), "<>| ") == true; ++*str) {
        if (!(*str)[1] || (*str)[1] == ';')
            return (cur_flag);
    }
    return (0);
}

static int count_nbr_word_between_redirection(char const *str, char const *flag)
{
    short int count = ((*str == '|') ? (-1) : (*str == '<' || *str == '>') ?
                       (-2) : (1));
    char error = 0;

    if (!str) return (-3);
    if (count < 0) return (count);
    for (; *str && *str != ';'; str++) {
        if (flag_cmp(*str, "<>|")) {
            if ((error = check_if_syntax_error(&str, flag)) == THERE_IS_OR)
                return (count);
            ++count;
        }
        if (error < 0) return (error);
        else skip_fl(&str, flag, ';', true);
    }
    return (count);
}

static char get_redirection_operators(char const **str, char ***x)
{
    char const operator[8][6] = {{"|"}, {">"}, {">>"}, {"<"}, {"<<"}, {"2>>"},
                                {"2>&1"}, {"2>>&1"}};
    char i = 0;

    for (; *(*str) && flag_cmp(*(*str), "<>|;") == false; ++*str);
    *x = malloc(sizeof(char **) * 2);
    if (!*x) return (84);
    for (; i < 8 && strcmp_crt(*str, operator[i], ' ') != 0; ++i);
    *(*x) = malloc(2);
    if (!*(*x)) return (84);
    *(*(*x)) = i;
    *(*(*x) + 1) = 0;
    *(1 + *x) = NULL;
    for (; *(*str) && *(*str) != ';' && flag_cmp(*(*str), "<>| ") > 0; ++*str);
    return (0);
}

static inline bool is_there_logical_operator(char const *str)
{
    if (*str == ';' || *str == '&' || (*str == '|' && str[1] == '|'))
        return (true);
    return (false);
}

char ***create_3d_array(char const **str)
{
    int nb_cmd = count_nbr_word_between_redirection(*str, ";<>|");
    char ***x = NULL;
    char ***array = init_3d_array(&x, nb_cmd);

    if (!array || !*str || nb_cmd <= 0) return (NULL);
    for (; *(*str) && is_there_logical_operator(*str) == false
        && x - array < nb_cmd; ++x) {
        if (!(*x = get_command_between_redirection(*str, " ", "<>|;&")) ||
       (x - array + 1 < nb_cmd && get_redirection_operators(str, ++x) == 84))
            return (NULL);
    }
    array[nb_cmd] = NULL;
    return (array);
}
