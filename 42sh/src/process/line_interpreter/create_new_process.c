/*
** EPITECH PROJECT, 2020
** create_new_process
** File description:
** create_new_process
*/

#include "../../../include/src.h"

static bool execute_builtin_function(sh_t *sh)
{
    static int (*environnement_handling[NB_BUILTIN_FCT]) (sh_t *, char **) =
        {&disp_env, &my_setenv, &my_unsetenv, &cd, &my_echo};
    char const builtin_command[NB_BUILTIN_FCT][12] =
        {"env", "setenv", "unsetenv", "cd", "echo"};

    for (unsigned char i = 0; i < NB_BUILTIN_FCT; ++i)
        if (my_strcmp(*sh->cur_cmd, builtin_command[i]) == 0) {
            environnement_handling[i](sh, sh->cur_cmd);
            return (true);
        }
    return (false);
}

static bool check_binary_right(char const *path, char const *cmd)
{
    if (check_path_right(path, cmd) && !fopen(path, "r")) {
        if (errno == ENOENT) {
            my_printf(2, "%s: No such file or directory.\n", cmd);
            return (false);
        } else if (errno == EACCES) {
            my_printf(2, "%s: Permission denied.\n", cmd);
            return (false);
        }
    }
    return (true);
}

static char check_all_binary_path(char ***env, char const *path,
                                char **cmd, bool const local)
{
    char *cmd_path = (local) ? (LOCAL_EXEC(cmd, env)) : (NULL);

    if (local) {
        if (check_binary_right(cmd_path, *cmd))
        execve(cmd_path, cmd, *env);
        return (false);
    }
    for (char const *i = path; *i; ++i) {
        if (!(cmd_path = my_strcat_end_crt(i, *cmd, ':', '/'))) return (84);
        if (check_right(cmd_path, F_OK) && check_right(cmd_path, X_OK))
            execve(cmd_path, cmd, *env);
        freeif(cmd_path);
        for (; *i && i[1] && *i != ':'; ++i);
    }
    return (true);
}

static void execute_commande(sh_t *sh, char **cmd)
{
    if (check_all_binary_path(&sh->env, GET_PATH_ENV(sh), cmd,
                              IS_LOCAL(*cmd, *cmd + 1)) == 1) {
        if (errno == ENOENT)
            my_printf(2, "%s: Command not found.\n", *cmd);
        else
            my_printf(2, "%s\n", strerror(errno));
    }
}

int create_new_process(sh_t *sh, char const io[2], char const inverse[2])
{
    bool const builtin = execute_builtin_function(sh);
    pid_t child_pid = 0;
    int status = 0;

    if (builtin == true) {
        sh->last = status;
        return (0);
    }
    if (create_pipe(sh, io, inverse) == 84 ||
        (child_pid = fork()) == -1) return (84);
    if (child_pid == 0) {
        if (init_redirection(sh, io, inverse) >= THERE_IS_A_COMMAND)
            execute_commande(sh, sh->cur_cmd);
        exit(0);
    }
    catch_all_signal();
    waitpid(child_pid, &status, 0);
    prepare_for_next_redirection(sh, io, inverse);
    fork_status_handling(sh, status);
    return (status);
}
