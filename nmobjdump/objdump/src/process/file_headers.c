/*
** EPITECH PROJECT, 2021
** File_headers
** File description:
** File_headers
*/

#include <stdlib.h>
#include <string.h>
#include <elf.h>

#include "objdump.h"
#include "printf.h"
#include "flags.h"
#include "include.h"

static inline void display_flag(char *s, bool *first)
{
    char *flag_to_print = *first ? s : my_strcat(", \0", s);

    my_printf(1, "%s", flag_to_print);
    if (!(*first))
        free(flag_to_print);
    *first = false;
}

static void display_header_infos(unsigned int const flags,
        unsigned int const e_type, int const start_address)
{
    bool first = true;

    printf(", flags 0x%08x:\n", flags);
    if (e_type == ET_REL)
        display_flag("HAS_RELOC", &first);
    if (e_type == ET_EXEC)
        display_flag("EXEC_P", &first);
    if (flags & HAS_SYMS)
        display_flag("HAS_SYMS", &first);
    if (e_type == ET_DYN)
        display_flag("DYNAMIC", &first);
    if (flags & D_PAGED)
        display_flag("D_PAGED", &first);
    printf("\nstart address 0x%016x\n\n", start_address);
}

bool display_64bits_header(Elf64_Ehdr const *header, Elf64_Shdr const *shdr,
                            char const *content)
{
    unsigned int flags = BFD_NO_FLAGS;

    my_printf(1, "architecture: i386:x86-64");
    flags |= header->e_type == ET_REL ? HAS_RELOC :
        header->e_type == ET_EXEC ? EXEC_P : 0;
    for (unsigned int i = 0; i < header->e_shnum && !(flags & HAS_SYMS); ++i) {
        if (shdr[i].sh_type != SHT_SYMTAB || shdr[i].sh_type != SHT_DYNAMIC)
            flags |= HAS_SYMS;
    }
    if (header->e_type == ET_DYN)
        flags |= DYNAMIC;
    if (header->e_phnum != 0)
        flags |= D_PAGED;
    display_header_infos(flags, header->e_type, header->e_entry);
    return (false);
}

bool display_32bits_header(Elf32_Ehdr const *header, Elf32_Shdr const *shdr,
                            char const *content)
{
    unsigned int flags = BFD_NO_FLAGS;

    my_printf(1, "architecture: i386");
    flags |= header->e_type == ET_REL ? HAS_RELOC :
        header->e_type == ET_EXEC ? EXEC_P : 0;
    for (int i = 0; i < header->e_shnum && !(flags & HAS_SYMS); ++i) {
        if (shdr[i].sh_type != SHT_SYMTAB || shdr[i].sh_type != SHT_DYNAMIC)
            flags |= HAS_SYMS;
    }
    if (header->e_type == ET_DYN)
        flags |= DYNAMIC;
    if (header->e_phnum != 0)
        flags |= D_PAGED;
    display_header_infos(flags, header->e_type, header->e_entry);
    return (false);
}

