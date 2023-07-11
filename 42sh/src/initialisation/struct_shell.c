/*
** EPITECH PROJECT, 2020
** struct_shell
** File description:
** struct_shell
*/

#include "../../include/src.h"

void free_shell(sh_t *sh)
{
    free_cmd_list(&sh->block);
    free_2d_array(sh->env);
    freeif(sh->bin_path_backup);
    freeif(sh->pwd);
}

static void initialize_values(sh_t *sh)
{
    sh->fd[0][0] = 0;
    sh->fd[0][1] = 0;
    sh->fd[1][0] = 0;
    sh->fd[1][1] = 0;
    sh->ret = 0;
    sh->is_exit = false;
    sh->current_fd = 0;
    sh->old_fd = 0;
    sh->last = 0;
    sh->isatty = isatty(0);
    sh->block = NULL;
    sh->alias = NULL;
}

sh_t init_shell(char const *const *env, char const *path)
{
    sh_t sh;

    initialize_values(&sh);
    sh.env = my_arraycpy(env);
    sh.bin_path = search_env_var_content(&sh, "PATH", true);
    sh.bin_path_backup = my_strcpy_m(sh.bin_path);
    sh.pwd = get_pwd();
    sh.instruction_42shrc = create_and_set_2d_array(NB_42SHRC_FCT,
                                            "alias\0", "export\0");
    if (!sh.bin_path || !sh.env || !sh.pwd || !sh.bin_path_backup) {
        free_shell(&sh);
        exit(84);
    }
    return (sh);
}
