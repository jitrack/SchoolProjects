/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "../../include/src.h"

static void mysh(sh_t *sh)
{
    while (sh->is_exit == false && get_cmd(sh) != EOF)
        if (sh->block) {
            line_interpreter(sh);
            free_cmd_list(&sh->block);
        }
}

int main(int const ac , char * const *arg UNUSED, char const * const *env)
{
    int error_arg UNUSED = error_start(ac, env);
    sh_t sh = init_shell(env, *arg);

    mysh(&sh);
    free_shell(&sh);
    if (sh.isatty)
        my_putstr("exit\n");
    return (sh.last);
}
