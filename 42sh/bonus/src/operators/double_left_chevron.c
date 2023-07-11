/*
** EPITECH PROJECT, 2020
** check_redirection
** File description:
** check_redirection
*/

#include "../../include/src.h"

static void double_left_chevron_write(int (*fd)[2], char const * const *cmd,
char const io, char const second_io)
{
    char *str = NULL;
    char *tmp = NULL;
    ssize_t is_end = 0;
    size_t nb_crt = 0;
    int len = my_strlen(*cmd);

    if (!(tmp = malloc(len + 2))) exit(84);
    tmp = my_strcpy(tmp, *cmd);
    tmp[len] = '\n';
    tmp[len + 1] = 0;
    close((*fd)[read_]);
    if (dup2((*fd)[write_], STDOUT_FILENO) == -1) exit(84);
    while (is_end != EOF && strcmp_quote(tmp, str) != 0) {
        if (str) write((*fd)[write_], str, is_end);
        is_end = getline(&str, &nb_crt, stdin);
    }
}

char double_left_chevron(int (*fd)[2], char const * const *cmd, char const io,
                         char const second_io)
{
    if (io == write_) {
        double_left_chevron_write(fd, cmd, io, second_io);
        close((*fd)[write_]);
        return (NO_COMMAND);
    } else
        handle_std_flow(fd, write_, read_, STDIN_FILENO);
    return (THERE_IS_A_COMMAND);
}
