/*
** EPITECH PROJECT, 2020
** check_redirection
** File description:
** check_redirection
*/

#include "../../include/src.h"

char my_pipe(int (*fd)[2], char const * const *cmd, char const io,
            char const second_io)
{
    if (io == write_)
        handle_std_flow(fd, read_, write_, STDOUT_FILENO);
    else
        handle_std_flow(fd, write_, read_, STDIN_FILENO);
    return (THERE_IS_A_COMMAND);
}

char right_chevron(int (*fd)[2], char const * const *cmd, char const io,
                char const second_io)
{
    if (io == write_)
        handle_std_flow(fd, read_, write_, STDOUT_FILENO);
    else {
        close((*fd)[write_]);
        if (dup2((*fd)[read_], STDIN_FILENO) == -1) return (84);
        write_file((*fd)[read_], open(*cmd, O_CREAT | O_TRUNC | O_WRONLY,
                    S_IRWXU), 3);
        return (NO_COMMAND);
    }
    return (THERE_IS_A_COMMAND);
}

char double_right_chevron(int (*fd)[2], char const * const *cmd, char const io,
                        char const second_io)
{
    if (io == write_)
        handle_std_flow(fd, read_, write_, STDOUT_FILENO);
    else {
        close((*fd)[write_]);
        if (dup2((*fd)[read_], STDIN_FILENO) == -1) exit(84);
        write_file((*fd)[read_],
                open(*cmd, O_CREAT | O_APPEND | O_WRONLY, S_IRWXU), 3);
        return (NO_COMMAND);
    }
    return (THERE_IS_A_COMMAND);
}

char left_chevron(int (*fd)[2], char const * const *cmd, char const io,
                char const second_io)
{
    if (io == write_) {
        close((*fd)[read_]);
        if (dup2((*fd)[write_], STDOUT_FILENO) == -1) exit(84);
        if (write_file(open(*cmd, O_RDONLY), (*fd)[write_], 3) == 84)
            my_printf(2, "%s: No such file or directory\n", *cmd);
        return (NO_COMMAND);
    } else
        handle_std_flow(fd, write_, read_, STDIN_FILENO);
    return (THERE_IS_A_COMMAND);
}

