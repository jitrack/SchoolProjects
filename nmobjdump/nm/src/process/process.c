/*
** EPITECH PROJECT, 2021
** process
** File description:
** process
*/

#include "nm.h"
#include "include.h"

static bool is_file_valid(file_p file)
{
    if (!(file->content = get_str_from_file_path(file->path))) {
        my_printf(2, "nm: '%s': No such file\n", file->path);
        return (false);
    }
    file->archi = get_file_architecture(file->content[EI_CLASS]);
    if (strncmp(file->content, ELF_HEADER, (size_t)4) ||
        (file->archi == unknown)) {
        my_printf(2, "nm: %s: file format not recognized\n", file->path);
        free(file->content);
        return (false);
    }
    return (true);
}

static sym_t const *get_greatest_sym(sym_t const *syms)
{
    sym_t const *greatest = syms;
    int greatest_st = find_first_not_of(greatest->name, '_');
    int name_st = 0;
    int diff = 0;

    for (; syms; NEXT(syms)) {
        name_st = find_first_not_of(syms->name, '_');
        diff = strcasecmp(greatest->name + (greatest_st < 0 ? 0 : greatest_st),
                        syms->name + (name_st < 0 ? 0 : name_st));
        if (!diff && strcasecmp(greatest->name, syms->name) > 0) {
            greatest = syms;
            greatest_st = find_first_not_of(greatest->name, '_');
        } else if (diff > 0) {
            greatest = syms;
            greatest_st = find_first_not_of(greatest->name, '_');
        }
    }
    return (greatest);
}

sym_p sort_syms_list(sym_p syms)
{
    sym_p sorted_list = NULL;
    sym_t *greatest = NULL;

    while (syms) {
        greatest = get_greatest_sym(syms);
        if (greatest == syms) {
            LINK_NEXT_PREV(syms);
            syms = greatest->next;
        } else{
            LINK_NEXT_PREV(greatest);
            LINK_PREV_NEXT(greatest);
        }
        add_sym(&sorted_list, greatest);
    }
    return (sorted_list);
}

bool process(file_p files)
{
    bool error = false;
    bool const multiple_files = list_len(files) > 1;

    for (; files; NEXT(files)) {
        if (!is_file_valid(files)) {
            error = true;
            continue;
        }
        if (multiple_files)
            my_printf(1, "\n%s:\n", files->path);
        if (files->archi == _32bits)
            error = display_32bits_file_symbols(files);
        else
            error = display_64bits_file_symbols(files);
        free(files->content);
    }
    return (error);
}
