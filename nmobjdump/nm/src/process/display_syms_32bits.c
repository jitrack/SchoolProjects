/*
** EPITECH PROJECT, 2021
** display_syms_64bits
** File description:
** display_syms_64bits
*/

#include "nm.h"

static Elf32_Shdr *get_32bits_section_name(Elf32_Shdr const *shdr,
    int const e_shnum, char const *sections_name, char const *name)
{
    Elf32_Shdr *section = NULL;

    for (int i = 0; i < e_shnum; i++) {
        if (shdr[i].sh_size > 0 &&
            !strcmp(sections_name + shdr[i].sh_name, name))
            section = (Elf32_Shdr *)(shdr + i);
    }
    return (section);
}

static sym_p get_all_32bits_syms(Elf32_Ehdr *header, Elf32_Shdr *shdr,
                                char const *content)
{
    char const *sections_name = content + shdr[header->e_shstrndx].sh_offset;
    Elf32_Shdr *symtab = get_32bits_section_name(shdr, header->e_shnum,
                                                sections_name, ".symtab");
    Elf32_Shdr *strtab = get_32bits_section_name(shdr, header->e_shnum,
                                                sections_name, ".strtab");
    Elf32_Sym *sym = NULL;
    char *syms_sections = NULL;
    sym_p syms = NULL;

    if (!symtab || !strtab ||
        !(sym = (Elf32_Sym*)(content + symtab->sh_offset)) ||
        !(syms_sections = (char *)(content + strtab->sh_offset)))
        return (NULL);
    for (size_t i = 0; i <  symtab->sh_size / symtab->sh_entsize; ++i, ++sym) {
        if (sym->st_name > 0 && sym->st_info != STT_FILE &&
            add_sym(&syms, new_sym_p(sym, syms_sections +
            sym->st_name, _32bits)))
            return (NULL);
    }
    return (syms);
}

bool display_32bits_file_symbols(file_t const *file)
{
    Elf32_Ehdr *header = (Elf32_Ehdr *)file->content;
    Elf32_Shdr *shdr = (Elf32_Shdr *)(file->content + header->e_shoff);
    sym_p syms = get_all_32bits_syms(header, shdr, file->content);
    char type = 0;

    if (!syms) return (true);
    sort_syms_list(syms);
    for (sym_p i; i; NEXT(i)) {
        type = is_lowercase(i->data_32bits->st_info,
                            i->data_32bits->st_shndx,
        get_type_1((shdr + i->data_32bits->st_shndx)->sh_type,
                (shdr + i->data_32bits->st_shndx)->sh_flags,
                i->data_32bits->st_shndx, i->data_32bits->st_info));
        if (type == 'w' || type == 'U')
            printf("                 %c %s\n", type, i->name);
        else printf("%016x %c %s\n", i->data_32bits->st_value,
                    type, i->name);
    }
    free_syms_list(syms);
    return (false);
}
