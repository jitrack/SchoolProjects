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

int my_printf(char const, char const *, ...);
int pf_putchar(va_list, int);
int pf_print_ch(va_list, int);
int pf_putstr(va_list, int);
int pf_put_nbr(va_list, int);
static int (*fl_fct[4])(va_list, int)__attribute__((unused)) =
{&pf_put_nbr, &pf_putchar, &pf_putstr, &pf_print_ch};

#endif /*_PRINTF_*/
