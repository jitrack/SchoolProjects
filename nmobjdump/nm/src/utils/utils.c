/*
** EPITECH PROJECT, 2021
** utils
** File description:
** utils
*/

#include "nm.h"

char get_type_2(uint32_t const sh_type, uint64_t const sh_flags)
{
    if ((sh_type == SHT_PROGBITS && (sh_flags == SHF_ALLOC ||
        sh_flags == (SHF_MERGE | SHF_ALLOC))) ||
        (sh_type == SHT_NOTE && sh_flags == SHF_ALLOC))
        return ('R');
    else if (((sh_type == SHT_PROGBITS || sh_type == 14) &&
            (sh_flags == (SHF_ALLOC | SHF_WRITE) || sh_flags == 1027)) ||
            (sh_type == SHT_DYNAMIC && sh_flags == (SHF_ALLOC | SHF_WRITE)))
        return ('D');
    else if ((sh_type == SHT_PROGBITS &&
            sh_flags == (SHF_ALLOC | SHF_EXECINSTR)) ||
            sh_type == SHT_INIT_ARRAY || sh_type == SHT_FINI_ARRAY)
        return ('T');
    return ('?');
}

char get_type_1(uint32_t const sh_type, uint64_t const sh_flags,
                uint16_t const st_shndx, uint8_t const st_info)
{
    if (ELF64_ST_BIND(st_info) == STB_WEAK)
        return (ELF64_ST_TYPE(st_info) == STT_OBJECT ? 'V' : 'W');
    else if (st_shndx == SHN_UNDEF) return ('U');
    else if (st_shndx == SHN_ABS) return ('A');
    else if (st_shndx == SHN_COMMON) return ('C');
    else if (sh_type == SHT_NOBITS && sh_flags == (SHF_ALLOC | SHF_WRITE))
        return ('B');
    return (get_type_2(sh_type, sh_flags));
}

char is_lowercase(uint8_t const st_info, uint16_t const st_shndx,
                    char const type)
{
    return ((ELF64_ST_BIND(st_info) == STB_LOCAL && type ||
            ((type == 'W' || type == 'V') && st_shndx == SHN_UNDEF))
            ? type + 32 : type);
}
