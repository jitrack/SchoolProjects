/*
** EPITECH PROJECT, 2020
** pipe_handlin
** File description:
** pipe_handling
*/

#include "src.h"

char create_pipe(sh_t *sh, char const io[2], char const inverse[2])
{
    if (((io[out] >= 0 && inverse[out] == false) ||
        (io[in] >= 0 && inverse[in] == true)) &&
        pipe(sh->fd[sh->current_fd]) < 0)
        return (84);
    if (sh->fd[sh->current_fd][read_] == -1 ||
        sh->fd[sh->current_fd][write_] == -1 ||
        sh->fd[sh->old_fd][read_] == -1 ||
        sh->fd[sh->old_fd][write_] == -1)
        return (84);
    return (0);
}

void handle_std_flow(int (*fd)[2], char const unused_fd,
                    char const used_fd, char const redirection)
{
    close((*fd)[unused_fd]);
    if (dup2((*fd)[used_fd], redirection) == -1) exit(84);
    close((*fd)[used_fd]);
}

void prepare_for_next_redirection(sh_t *sh, char const io[2],
                                char const inverse[2])
{
    if ((io[out] >= 0 && inverse[out] == false) ||
        (io[in] >= 0 && inverse[in] == true))
        close(sh->fd[sh->current_fd][write_]);
    if ((io[in] >= 0 && inverse[in] == false) ||
        (io[out] >= 0 && inverse[out] == true))
        close(sh->fd[sh->old_fd][read_]);
    sh->old_fd = sh->current_fd;
    sh->current_fd = ~sh->current_fd;
}

char init_redirection(sh_t *sh, char const io[2], char const inverse[2])
{
    static char (*redirection[5]) (int (*)[2], char const * const *, char const, char const) =
        {&my_pipe, &right_chevron, &double_right_chevron, &left_chevron, &double_left_chevron};
    char is_there_a_command = 0;

    if (io[out] >= 0) is_there_a_command = redirection[io[out]](&(sh->fd[((inverse[out] == false) ? (sh->current_fd) : (sh->old_fd))]),
        (char const * const *)sh->cur_cmd, ((inverse[out] == false) ? (write_) : (read_)), io[in]);
    if (io[in] >= 0) is_there_a_command = redirection[io[in]](&(sh->fd[sh->old_fd]), (char const * const *)sh->cur_cmd,
        ((inverse[in] == false) ? (read_) : (write_)), io[out]);
    return ((io[out] < 0 && io[in] < 0) ? (THERE_IS_A_COMMAND) :
                                        (is_there_a_command));
}
