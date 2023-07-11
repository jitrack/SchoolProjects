/*
** EPITECH PROJECT, 2020
** line_interprete** File description:
** line_interpreter
*/

#include "../../../include/src.h"

static void replace_all_home_tile(char ***cmd, char const * const *env)
{
    for (char **ar = *cmd; *ar; ar++)
        if (!*ar && *(*ar) == '~')
            home_tile_replace(ar, env);
}

static char check_cmd(sh_t *sh, char **cmd, char const io[2],
                    char const inverse[2])
{
    sh->cur_cmd = cmd;
    replace_all_home_tile(&cmd, (char const * const *)sh->env);
    create_new_process(sh, io, inverse);
    return (0);
}

static void find_exexution_order(sh_t *sh, char ***y,
                                 unsigned short int const cur_pos)
{
    char ***offset = (y[1]) ? (NEXT_CMD(y)) : (PREV_CMD(y, cur_pos));

    if (check_if_exit(sh, (char const * const *)*y) == false) {
        if (y[1]) {
            check_cmd(sh, *offset,
            (char const [2]){PREV_OPT(offset, cur_pos), NEXT_OPT(offset)},
            (char const [2]){INVERSE(offset, y), 0});
        } else {
            check_cmd(sh, *offset,
            (char const [2]){PREV_OPT(offset, cur_pos), NEXT_OPT(offset)},
            (char const [2]){0, INVERSE(offset, y)});
        }
    }
}

static block_t *get_cmd_block(block_t **block, int const last)
{
    if (!(*block)->next) return (*block);
    if ((*block)->next->separator == and && last != 0)
        for (; *block && (*block)->next->separator == and; PREV((*block)));
    if ((*block)->next->separator == or && last == 0)
        for (; *block && (*block)->next->separator == or; PREV((*block)));
    return (*block);
}

void line_interpreter(sh_t *sh)
{
    block_t *current;

    sh->ret = 0;
    for (block_t *block = sh->block; block; PREV(block)) {
        if (!(current = get_cmd_block(&block, sh->last))) return;
        for (char ***y = current->cmd; *y; ++y) {
            find_exexution_order(sh, y, y - current->cmd);
            y = (y[1]) ? (y + 1) : (y);
        }
    }
}
