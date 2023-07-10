/*
** EPITECH PROJECT, 2021
** display_syms_64bits
** File description:
** display_syms_64bits
*/

#include "nm.h"

static Elf64_Shdr *get_64bits_section_name(Elf64_Shdr const *shdr,
    int const e_shnum, char const *sections_name, char const *name)
{
    Elf64_Shdr *section = NULL;

    for (int i = 0; i < e_shnum; i++) {
        if (shdr[i].sh_size > 0 &&
            !strcmp(sections_name + shdr[i].sh_name, name))
            section = (Elf64_Shdr *)(shdr + i);
    }
    return (section);
}

static sym_p get_all_64bits_syms(Elf64_Ehdr *header, Elf64_Shdr *shdr,
                                char const *content)
{
    char const *sections_name = content + shdr[header->e_shstrndx].sh_offset;
    Elf64_Shdr *symtab = get_64bits_section_name(shdr, header->e_shnum,
                                                sections_name, ".symtab");
    Elf64_Shdr *strtab = get_64bits_section_name(shdr, header->e_shnum,
                                                sections_name, ".strtab");
    Elf64_Sym *sym = NULL;
    char *syms_sections = NULL;
    sym_p syms = NULL;

    if (!symtab || !strtab ||
        !(sym = (Elf64_Sym*)(content + symtab->sh_offset)) ||
        !(syms_sections = (char *)(content + strtab->sh_offset)))
        return (NULL);
    for (size_t i = 0; i <  symtab->sh_size / symtab->sh_entsize; ++i, ++sym) {
        if (sym->st_name > 0 && sym->st_info != STT_FILE &&
            add_sym(&syms, new_sym_p(sym, syms_sections + sym->st_name,
                    _64bits)))
            return (NULL);
    }
    return (syms);
}

bool display_64bits_file_symbols(file_t const *file)
{
    Elf64_Ehdr *header = (Elf64_Ehdr *)file->content;
    Elf64_Shdr *shdr = (Elf64_Shdr *)(file->content + header->e_shoff);
    sym_p syms = get_all_64bits_syms(header, shdr, file->content);
    char type = 0;

    if (!syms) return (true);
    sort_syms_list(syms);
    for (sym_p i = syms; i; NEXT(i)) {
        type = is_lowercase(i->data_64bits->st_info,
                            i->data_64bits->st_shndx,
        get_type_1((shdr + i->data_64bits->st_shndx)->sh_type,
                    (shdr + i->data_64bits->st_shndx)->sh_flags,
                    i->data_64bits->st_shndx, i->data_64bits->st_info));
        if (type == 'w' || type == 'U')
            printf("                 %c %s\n", type, i->name);
        else printf("%016lx %c %s\n", i->data_64bits->st_value,
                    type, i->name);
    }
    free_syms_list(syms);
    return (false);
}
