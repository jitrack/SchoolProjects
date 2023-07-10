/*
** EPITECH PROJECT, 2021
** include
** File description:
** include
*/

#ifndef __OBJDUMP__
#define __OBJDUMP__

#include <elf.h>
#include <stdbool.h>
#include "../../lib/my_printf/my_printf.h"

#define UNUSED __attribute__((unused))

#define TOGGLE_BOOL(a) (a = (!a))

#define PREV(thing) thing = thing->prev
#define NEXT(thing) thing = thing->next
#define LINK_PREV_NEXT(thing) ((thing->prev) ? \
    (thing->prev->next = thing->next) : (thing))
#define LINK_NEXT_PREV(thing) ((thing->next) ? \
    (thing->next->prev = thing->prev) : (thing))
#define ADD_NODE(new, target) new->next = target; target = new

#define ELF_HEADER (char const [5]){0x7f, 'E', 'L', 'F', 0}

typedef enum file_archi_e {unknown = -1, _32bits, _64bits} file_archi_t;

typedef struct file_s {
    struct file_s *next;
    struct file_s *prev;
    char const *path;
    char *content;
    file_archi_t archi;
} file_t;

typedef file_t *file_p;

typedef struct objdump_s {
    bool file_header;
    bool full_content;
    bool error;
} objdump_t;

typedef objdump_t *objdump_p;

bool process(file_t *files, objdump_p objdump);
bool display_32bits_content(Elf32_Ehdr const *header, Elf32_Shdr const *shdr,
                            char const *content);
bool display_64bits_content(Elf64_Ehdr const *header, Elf64_Shdr const *shdr,
                            char const *content);
bool display_64bits_header(Elf64_Ehdr const *header, Elf64_Shdr const *shdr,
                            char const *content);
bool display_32bits_header(Elf32_Ehdr const *header, Elf32_Shdr const *shdr,
                            char const *content);
void display_line(unsigned char const *str, int const size);

file_p get_all_files(char const * const *argv);
void free_files_list(file_p files);

UNUSED static inline file_archi_t
get_file_architecture(unsigned char const byte)
{
    return (byte == ELFCLASS32 ?
    _32bits : byte == ELFCLASS64 ?
    _64bits : unknown);
}

#endif /* __OBJDUMP__ */
