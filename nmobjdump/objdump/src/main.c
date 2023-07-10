/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "objdump.h"
#include <stdlib.h>

static inline void print_usage(void)
{
    puts("Usage: objdump <option(s)> <file(s)>\n  -s, --full-contents      \
    Display the full contents of all sections requested\n  -f, --file-headers  \
    Display the contents of the overall file header\n");
}

static void get_flags(char const * const *argv, objdump_p objdump)
{
    for (; *argv; ++argv) {
        if (!strcmp(*argv, "-f") || !strcmp(*argv, "--file-headers")) {
            objdump->file_header = true;
        } else if (!strcmp(*argv, "-s") || !strcmp(*argv, "--full_contents")) {
            objdump->full_content = true;
        } else if (!strcmp(*argv, "-fs")) {
            objdump->full_content = true;
            objdump->file_header = true;
        }
    }
    if (!objdump->file_header && !objdump->full_content) {
        objdump->file_header = true;
        objdump->full_content = true;
    }
}

int main(int const argc, char const * const *argv)
{
    objdump_t objdump = {.file_header = false,
    .full_content = false, .error = false};
    file_p files = NULL;

    if (argv[1])
        get_flags(argv, &objdump);
    if ((files = get_all_files(argv[1] ? argv + 1 :
    (char const * const []){"a.out", NULL}))) {
        process(files, &objdump);
        free_files_list(files);
    }
    return (objdump.error ? 84 : 0);
}
