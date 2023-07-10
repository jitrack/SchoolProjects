/*
** EPITECH PROJECT, 2021
** include
** File description:
** include
*/

#ifndef __INCLUDE__
#define __INCLUDE__

#include <stdbool.h>

char *get_str_from_file_path(char const *path);

bool check_extensions(char const *s, char const *ext);
int find_last_of(char const *s, char const crt);
char *my_strcat(char const *s1, char const *s2);
unsigned int my_strlen(char const *str);
unsigned int list_len(void *start);
int find_first_not_of(char const *s, char const crt);

#endif /* __INCLUDE__ */
