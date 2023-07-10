/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "nm.h"
#include <stdlib.h>

static inline void print_usage(void)
{
    puts("Usage: objdump <option(s)> <file(s)>\n  -s, --full-contents      \
    Display the full contents of all sections requested\n  -f, --file-headers\
    Display the contents of the overall file header\n");
}

int main(int const argc, char const * const *argv)
{
    file_p files = NULL;

    if ((files = get_all_files(argv[1] ? argv + 1 :
    (char const * const []){"a.out", NULL}))) {
        process(files);
        free_files_list(files);
    }
    return (0);
}
