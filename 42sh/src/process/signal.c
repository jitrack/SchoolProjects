
/*
** EPITECH PROJECT, 2020
** signal
** File description:
** signal
*/

#include "src.h"

void fork_status_handling(sh_t *sh, int status)
{
    sh->last = WEXITSTATUS(status);
    if (WTERMSIG(status) == SIGFPE) {
        sh->last = status;
        my_printf(1, "Floating exception\n");
    }
    if (WTERMSIG(status) == SIGSEGV) {
        sh->last = status;
        my_printf(1, "Segmentation fault\n");
    }
    if (WTERMSIG(status) == SIGABRT) {
        sh->last = status;
        my_printf(1, "Aborted\n");
    }
    if (WTERMSIG(status) == SIGBUS) {
        sh->last = status;
        my_printf(1, "Bus error\n");
    }
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
