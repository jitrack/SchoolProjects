
/*
** EPITECH PROJECT, 2020
** signal
** File description:
** signal
*/

#include "src.h"

void fork_status_handling(sh_t *sh, int status)
{
    if (WTERMSIG(status) == SIGFPE)
        my_printf(1, "Floating exception\n");
    if (WTERMSIG(status) == SIGSEGV)
        my_printf(1, "Segmentation fault\n");
    if (WTERMSIG(status) == SIGABRT)
        my_printf(1, "Aborted\n");
    if (WTERMSIG(status) == SIGBUS)
        my_printf(1, "Bus error\n");
    sh->last = WEXITSTATUS(status);
}

void signal_handling(int status)
{
    if (status == SIGINT) {
        my_putchar('\n');
    } else if (status == SIGPIPE)
        exit(84);
}

void catch_all_signal(void)
{
    signal(SIGINT, signal_handling);
    signal(SIGPIPE, signal_handling);
}
