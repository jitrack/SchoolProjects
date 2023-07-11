/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** create include file
*/

#ifndef SRC_H_
#define SRC_H_

#pragma GCC diagnostic ignored "-Wchar-subscripts"
#pragma GCC diagnostic ignored "-Wunused-parameter"

#include "lib.h"

enum fdpipe{read_, write_};
enum io{in, out};
enum into{quote_e = 0};
enum separator{comma, and, or, end};

/* start_minishell */
sh_t init_shell(char const * const *, char const *);

/* error_handling */
bool check_right(char const *path, int const mode);
bool check_path_right(char const *path, char const *str);
int error_start(int const, char const * const *);

/* get_cmd */
char ***create_3d_array(char const **);
char ***init_3d_array(char ****x, int nb_cmd);
char *clean_input(char *);
char get_cmd(sh_t *);
char **get_command_between_redirection(char const *,
                                       char const *, char const *);
bool add_command_block(block_t **block, char ***cmd, char const separtor);
void reverse_list(block_t **block);
void free_node(block_t *block);
void free_cmd_list(block_t **block);
char check_redirection_operators_syntaxe(char const *str);

char pipe_operator(char const *str);
char chevron_operator(char const *str);

/* interpret_cmd */
int create_new_process(sh_t *sh, char const[2], char const[2]);
void line_interpreter(sh_t *);
char check_if_redirection(sh_t *sh, char ****cmd, int const nbr);

/* builtin */
int search_environnement_var(char const *, char const * const *);
int my_setenv(sh_t *, char **);
char setenv_check(char **, sh_t *);
int my_unsetenv(sh_t *, char **);
int disp_env(sh_t *, char **);
int cd(sh_t *, char **);
int my_echo(sh_t *, char **);

/* 42shrc */
bool get_alias(sh_t *sh, char *line);
bool get_export(sh_t *sh, char *line);
bool parse_42shrc_file(sh_t *sh, char const *path);
char *fill_allias_in_input(sh_t *sh, char *input);

/* utilities */
void home_tile_replace(char **, char const * const *);
char *get_pwd(void);
char *str_detect_fd(int const);
bool skip_fl(char const **, char const *, char const, bool const);
bool skip_flag(char const **, char const *, char const, bool const);
int strcmp_quote(char const *, char const *);
void print_ch(char const *, int );
int crt_count(char const *, char const *, int const);
bool check_next_caracters(char const *, char const *, char const *);
char *search_env_var_content(sh_t *, char const *, bool const);
bool is_end(char const *str, char const *flag, char const *end);

/* Redirections */
char create_pipe(sh_t *sh, char const [2], char const [2]);
void handle_std_flow(int (*)[2], char const,
                    char const, char const);
void prepare_for_next_redirection(sh_t *, char const [2], char const [2]);
char init_redirection(sh_t *, char const[2], char const[2]);
char my_pipe(int (*)[2], char const * const *, char const, char const);
char right_chevron(int (*)[2], char const * const *, char const, char const);
char double_right_chevron(int (*)[2], char const * const *, char const,
                        char const);
char left_chevron(int (*)[2], char const * const *, char const, char const);
char double_left_chevron(int (*)[2], char const * const *, char const,
                        char const);

/* signal */
void catch_all_signal(void);
void signal_handler(int);
void fork_status_handling(sh_t *sh, int status);
void signal_handling(int);

/* end_of_programm */
void free_shell(sh_t *);
bool check_if_exit(sh_t *sh, char const * const *i);

#endif /*SRC_H_*/
