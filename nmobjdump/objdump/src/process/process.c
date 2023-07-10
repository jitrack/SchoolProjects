/*
** EPITECH PROJECT, 2021
** process
** File description:
** process
*/

#include "objdump.h"
#include "include.h"

static bool is_file_valid(file_p file)
{
    if (!(file->content = get_str_from_file_path(file->path))) {
        my_printf(2, "objdump: '%s': No such file\n", file->path);
        return (false);
    }
    file->archi = get_file_architecture(file->content[EI_CLASS]);
    if (strncmp(file->content, ELF_HEADER, (size_t)4) ||
        (file->archi == unknown)) {
        my_printf(2, "objdump: %s: file format not recognized\n", file->path);
        free(file->content);
        return (false);
    }
    return (true);
}

static void display_32bits_file(file_t const *file, objdump_t const *objdump)
{
    Elf32_Ehdr *header = (Elf32_Ehdr *)file->content;
    Elf32_Shdr *shdr = (Elf32_Shdr *)(file->content + header->e_shoff);

    if (objdump->file_header)
        display_32bits_header(header, shdr, file->content);
    else
        putchar('\n');
    if (objdump->full_content)
        display_32bits_content(header, shdr, file->content);
}

static void display_64bits_file(file_t const *file, objdump_t const *objdump)
{
    Elf64_Ehdr *header = (Elf64_Ehdr *)file->content;
    Elf64_Shdr *shdr = (Elf64_Shdr *)(file->content + header->e_shoff);

    if (objdump->file_header)
        display_64bits_header(header, shdr, file->content);
    else
        putchar('\n');
    if (objdump->full_content)
        display_64bits_content(header, shdr, file->content);
}

bool process(file_p files, objdump_p objdump)
{
    for (; files; NEXT(files)) {
        if (!is_file_valid(files)) {
            objdump->error = true;
            continue;
        }
        my_printf(1, "\n%s:     %s", files->path, files->archi == _32bits ?
                "file format elf32-i386\n" : "file format elf64-x86-64\n");
        if (files->archi == _32bits)
            display_32bits_file(files, objdump);
        else
            display_64bits_file(files, objdump);
        free(files->content);
    }
    return (false);
}
