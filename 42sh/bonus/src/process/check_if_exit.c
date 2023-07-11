/*
** EPITECH PROJECT, 2020
** exit_fct
** File description:
** exit_fct
*/

#include "../../include/src.h"

bool check_if_exit(sh_t *sh, char const * const *i)
{
    if (strcmp_crt(*i, "exit", ' ') == 0) {
        if ((!1[i] || (!2[i] && is_num(1[i]) == 0))) {
            sh->last = (unsigned char)((!1[i]) ? (0) : (i[1][0] != '-') ?
            (my_getnbr(1[i])) : (256 - my_getnbr(1[i] + 1)));
            sh->is_exit = true;
        } else {
            my_printf(2, "%s\n", (!1[i] && i[1][0] == '-') ?
            ("exit: Badly formed number.") :
            ("exit: Expression Syntax."));
        }
        return (true);
    }
    return (false);
}
