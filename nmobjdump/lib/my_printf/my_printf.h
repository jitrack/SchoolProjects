/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** create include file
*/

#ifndef _PRINTF_
#define _PRINTF_
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

unsigned int my_printf(unsigned char const, char const *, ...);
int pf_putchar(va_list const, unsigned char const);
int pf_print_ch(va_list const, unsigned char const);
int pf_putstr(va_list const, unsigned char const);
int pf_put_int_nbr(va_list const, unsigned char const);
int pf_put_gfloat_nbr(va_list const ls, unsigned char const ch);
int pf_put_float_nbr(va_list const ls, unsigned char const ch);
void my_ptc(char const c, unsigned char const ch);
int count_nbr_printf(int nb, int size, int *len);

#endif /*_PRINTF_*/
