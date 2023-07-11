/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include "libs.h"
#include "../my_printf/my_printf.h"

#define ISNUM(val) (val >= 48 && val <= 57) ? 1 : 0

int my_strlen_end(char const *str, char const *flag);
int my_strlen(char const *);
int my_strlen_crt(char const *, char const);
int my_strlen_cmp(char const *, char const *);
int my_strlen_flag(char const *, char const *);
int nbr_ln(char const *, char const, int *);
int count_nbr_line(char const * const *);
int my_3d_array_len(char const * const * const *array);

//copy_functions
char *my_strcpy(char *, char const *);
char *str_cpy(char *);
char *str_ncpy(char *, int);
char *my_strcpy_crt(char *, char const *, char const);
char **my_arraycpy(char const * const *);
char *my_strncpy(char const *, int const);
char *my_strcpy_m(char const *);
char *my_strcpy_crt_m(char const *, char const);
void my_memmove(char **, char const);

//strcat
char *my_strcat(char const *, char const *);
char *my_strcat_end_crt(char const *, char const *, char const, char const);
char *my_strcat_crt(char const *, char const *, char const);

//print_functions
int my_printf(char const, char const *, ...);
void my_putchar(char);
void my_putstr(char const *);
void my_putsterr(char const *);
void my_putstr_ch(char const *, int const);
void my_put2str(char const * const *);
char write_file(int const, int const, unsigned char const);

//strcmp
char flag_cmp(char const, char const *);
int str_compare(char *, char *);
int my_strcmp(char const *, char const *);
char strcmp_crt(char const *, char const *, char const);
bool is_there_an_occurence(char const *s1, char const *s2);
short int find_word_in_list(char const *line, char const * const *list,
                            char const *end);

//getnbr
int my_getnbr(char const *str);
int my_getnbr_st(char const *, int);

//array_function
char **create_2darray(int const, ...);
char *my_int_to_array(int);
char **create_and_set_2d_array(int len, ...);

//free_function
void freeif(void *);
char ***free_3d_array(char ***);
char ****free_4d_array(char ****);
void free_2d_array(char **);

//is_thing_function
char is_num(char const *);

//file_handling_function
char *get_next_line(int);
char *str_detect(char const *);

#endif /*MY_H_*/

