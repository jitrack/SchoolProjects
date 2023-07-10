/*
** EPITECH PROJECT, 2021
** file_content
** File description:
** file_content
*/

#include "objdump.h"
#include "bitwise.h"

static void display_64bits_line(Elf64_Ehdr const *header,
                                Elf64_Shdr const *shdr)
{
    for (unsigned int i = shdr->sh_offset;
        i < (unsigned int)(shdr->sh_offset + shdr->sh_size); i += 16) {
        printf(" %04x ", (unsigned int)(shdr->sh_addr + i - shdr->sh_offset));
        display_line((unsigned char *)header + i,
            shdr->sh_offset + shdr->sh_size - i);
        printf("\n");
    }
}

static void display_32bits_line(Elf32_Ehdr const *header,
                                Elf32_Shdr const *shdr)
{
    for (unsigned int i = shdr->sh_offset;
        i < (unsigned int)(shdr->sh_offset + shdr->sh_size); i += 16) {
        printf(" %04x ", (unsigned int)(shdr->sh_addr + i - shdr->sh_offset));
        display_line((unsigned char *)header + i,
            shdr->sh_offset + shdr->sh_size - i);
        printf("\n");
    }
}

static bool is_section_displayable(char const *name)
{
    char const *sections_to_skip[] = {".bss", ".shstrtab", ".symtab",
        ".strtab", ".rela.text", ".rela.debug_info", ".rela.debug_aranges",
        ".rela.debug_line", ".rela.eh_frame", ".tbss", "__libc_freeres_ptrs",
        NULL
    };

    if (!name)
        return (true);
    for (char const * const *i = sections_to_skip; *i; ++i) {
        if (!strcmp(*i, name))
            return (true);
    }
    return (false);
}

bool display_64bits_content(Elf64_Ehdr const *header, Elf64_Shdr const *shdr,
                            char const *content)
{
    char const *sections_name = content + shdr[header->e_shstrndx].sh_offset;

    for (int i = 0; i < header->e_shnum; ++i) {
        if (shdr[i].sh_size > 0 &&
            !is_section_displayable(sections_name + shdr[i].sh_name)) {
            my_printf(1, "Contents of section %s:\n",
            sections_name + shdr[i].sh_name);
            display_64bits_line(header, &shdr[i]);
        }
    }
    return (false);
}

bool display_32bits_content(Elf32_Ehdr const *header, Elf32_Shdr const *shdr,
                            char const *content)
{
    char const *sections_name = content + shdr[header->e_shstrndx].sh_offset;

    for (int i = 0; i < header->e_shnum; ++i) {
        if (shdr[i].sh_size > 0 &&
            !is_section_displayable(sections_name + shdr[i].sh_name)) {
            my_printf(1, "Contents of section %s:\n",
            sections_name + shdr[i].sh_name);
            display_32bits_line(header, &shdr[i]);
        }
    }
    return (false);
}
