/*
** EPITECH PROJECT, 2021
** display_line
** File description:
** display_line
*/

#include "objdump.h"
#include "bitwise.h"

void display_line(unsigned char const *str, int const size)
{
    for (int i = 0; i < 16; ++i) {
        if (i < size) printf("%02x", str[i]);
        else printf("  ");
        if (!((i + 1) % 4)) printf(" ");
    }
    printf(" ");
    for (int i = 0; i < 16; ++i) {
        if (i < size)
            printf("%c", (str[i] >= 32 && str[i] <= 126) ? str[i] : '.');
        else
            printf(" ");
    }
}