/*
** EPITECH PROJECT, 2020
** shell
** File description:
** shell
*/

#ifndef SHELL_
#define SHELL_

typedef struct alias_s
{
    struct alias_s *next;
    char *shortcut;
    char *entire_cmd;
} alias_t;

typedef struct block_s
{
    struct block_s *next;
    struct block_s *prev;
    unsigned char separator;
    char ***cmd;
} block_t;

typedef struct sh_s
{
    alias_t *alias;
    block_t *block;
    char **instruction_42shrc;
    char **env;
    char *pwd;
    char *bin_path_backup;
    char *bin_path;
    unsigned char current_fd : 1;
    unsigned char old_fd : 1;
    char **cur_cmd;
    int fd[2][2];
    unsigned char ret;
    bool is_exit;
    bool next_or_prev;
    int last;
    bool isatty;
}sh_t;

#endif /*SHELL_*/
