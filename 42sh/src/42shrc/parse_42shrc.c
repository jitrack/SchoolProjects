/*
** EPITECH PROJECT, 2020
** parse_42shrc
** File description:
** parse_42shrc
*/

#include "src.h"

bool parse_42shrc_file(sh_t *sh, char const *path)
{
    bool (*parsing_42shrc_instruction[2])(sh_t *sh, char *line) =
        {&get_alias, &get_export};
    FILE *file = fopen(".42shrc", "r");
    size_t size = 0;
    char *line = NULL;
    char pos UNUSED = -1;

    if (!file) return (true);
    while (getline(&line, &size, file) != -1) {
        if (*line == '\n' || is_end(line, " \t" , "\n\0")) continue;
        if ((pos = find_word_in_list(line,
            (char const * const *)sh->instruction_42shrc, " \t")) == -1 ||
            parsing_42shrc_instruction[pos](sh, line)) {
            my_printf(2, "[42shrc] error: %s", line);
            return (true);
        }
        line = NULL;
    }
    fclose(file);
    return (false);
}
