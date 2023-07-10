/*
** EPITECH PROJECT, 2020
** bitwise_lib
** File description:
** bitwise_lib
*/

#ifndef BITWISE_LIB_
#define BITWISE_LIB_

#include <stddef.h>
#include <stdio.h>
#include <stdint.h>

////* with offstet */
#define BIT(a, b) (a & (1 << b))
#define TOGGLE(a, b) (a ^= (1 << b))
#define SET_BIT(a, b) (a |= (1 << b))
#define CLEAR_BIT(a, b) (a &= ~(1 << b))
/////////////////////

/* without offstet */
#define BIT_WO(a, b) (a & b)
#define TOGGLE_WO(a, b) (a ^= b)
#define SET_BIT_WO(a, b) (a |= b)
#define CLEAR_BIT_WO(a, b) (a &= ~b)
/////////////////////

#endif /* BITWISE_LIB_ */
