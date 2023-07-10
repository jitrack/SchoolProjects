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

#define ELF_HEADER (char const [5]){0x7f , 'E', 'L', 'F', 0}

typedef enum file_archi_e {unknown = -1, _32bits, _64bits} file_archi_t;

typedef struct file_s {
    struct file_s *next;
    struct file_s *prev;
    char const *path;
    char *content;
    file_archi_t archi;
} file_t;

typedef file_t *file_p;

typedef struct sym_s {
    struct sym_s *next;
    struct sym_s *prev;
    char const *name;
    char type;
    Elf64_Sym const *data_64bits;
    Elf32_Sym const *data_32bits;
} sym_t;

typedef sym_t *sym_p;

/* process */
bool process(file_t *files);

/* parser */
file_p get_all_files(char const * const *argv);
void free_files_list(file_p files);
sym_p new_sym_p(void const *sym, char const *name, \
                file_archi_t const file_archi);
bool add_sym(sym_p *files, sym_p sym);
void free_syms_list(sym_p syms);
char is_lowercase(uint8_t const st_info, uint16_t const st_shndx,
                char const type);
char get_type_1(uint32_t const sh_type, uint64_t const sh_flags,
                uint16_t const st_shndx, uint8_t const st_info);
char get_type_2(uint32_t const sh_type, uint64_t const sh_flags);
sym_p sort_syms_list(sym_p syms);
bool display_32bits_file_symbols(file_t const *file);
bool display_64bits_file_symbols(file_t const *file);

UNUSED static inline file_archi_t
get_file_architecture(unsigned char const byte)
{
    return (byte == ELFCLASS32 ? _32bits : byte == ELFCLASS64 ?
    _64bits : unknown);
}

#endif /* __OBJDUMP__ */
