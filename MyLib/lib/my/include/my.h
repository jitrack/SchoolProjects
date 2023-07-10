/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include "libs.h"

///////////* array */
unsigned int array_len(void const *start);
char **my_arraycpy(char const * const *);
char **create_and_set_2d_array(unsigned int len, ...);
/////////////////////

///////////* strings */
char *my_strcpy(char *dest, char const *src);
char *my_strcpy_to_crt(char *dest, char const *src, char const n);
char *my_strcpy_m(char const *src);
char *my_strcpy_m_to_crt(char const *src, char const n);

char **str_to_array(char const *str, char const *sptr);

char *my_strcat(char const *s1, char const *s2);
char *my_strcat_to_crt(char const *s1, char const *s2, char const crt);
char *my_strcat_to_crt_with_end(char const *s1, char const *s2,
                                char const crt, char const end);

bool flag_cmp(char const crt, char const *flag);
char my_strcmp(char const *s1, char const *s2);
char strcmp_to_crt(char const *s1, char const *s2, char const crt);
char strcmp_to_flag(char const *s1, char const *s2, char const *flag);
char is_num(char const *str);
char is_alpha(char const *str);

bool skip_string_flag(char const **str, char const *flag,
                     char const end, bool const choice);
bool skip_to_next_word(char const **str, char const *flag, char const end);

bool is_there_an_occurence(char const *s1, char const *s2);
short int find_word_in_list(char const *line, char const * const *list,
                            char const *end);

unsigned int my_strlen(char const *str);
unsigned int my_strlen_to_crt(char const *str, char const end);
unsigned int my_strlen_to_flag(char const *str, char const *flag,
                               bool const my_bool);
unsigned int my_strlen_cmp(char const *str, char const *flag);
unsigned int count_nbr_words(char const *str, char const *sptr);

unsigned int get_end(char const *str, char const *flag);

void my_memmove(char **, char const);
///////////////////////

////*print_functions */
void my_putchar(char const c);
void my_putstr(char const *str);
void my_putstr_ch(char const *str, int const ch);
///////////////////////

////////////* number */
int my_getnbr(char const *str);
char *my_int_to_string(int nb);
///////////////////////

/////* free_function */
void free_if(void *);
///////////////////////

////*file_descriptor */
int get_file_fd(char const *str, unsigned char const rights);
char *get_str_from_file_path(char const *path);
char *get_str_from_file_fd(int const fd);
///////////////////////

char *get_next_line(int);

#endif /*MY_H_*/
