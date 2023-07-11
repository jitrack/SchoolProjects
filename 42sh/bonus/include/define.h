/*
** EPITECH PROJECT, 2020
** define
** File description:
** define
*/

#define UNUSED __attribute__((unused))
#define INLINE __attribute__((always_inline))

#define CLEAN_INPUT_FLAG ("\t ;")
#define REDIRECTION_OPERATORS ("|<>")
#define CRT_TO_SKIP ("\t ")

#define NB_BUILTIN_FCT 5
#define NB_42SHRC_FCT 2

/* error_return */
#define PIPE_SYNTAXE_ERROR -1
#define CHEVRON_SYNTAXE_ERROR -2

/* specific return */
#define THERE_IS_A_COMMAND (1)
#define NO_COMMAND (0)
#define THERE_IS_OR -5

/* create_new_process */
#define COMMAND_NOT_FOUND (2)
#define SUCCESS (1)

/* signal code */
#define DIVIDE_BY_ZERO (8)
#define SEGV (11)
#define SEGV_CORE_DUMP (10)

/* error_message */
#define SETENV_BAD_NAME ("setenv: Variable name must begin with a letter.\n")
#define SETENV_ARG_ERROR ("setenv: Too many arguments.\n")
#define UNSETENV_ARG_ERROR ("unsetenv: Too few arguments.\n")

#define LET(a) ((a > 'A' && a < 'Z') || (a > 'a' && a < 'z') ?  \
                (1) : (0))
#define IS_LOCAL(a, b) (((*a == '.' && *b == '/') || *a == '/') ? \
                (true) : (false))
#define INVERSE(off, original) ((original != off) ? (1) : (0))
#define NEGATIVE(nb) (0 - nb)

#define RESET(thing) do {if (thing) free(thing); thing = NULL;} while(0)

/////////////////////////execve local bin/////////////////////////////////
#define LOCAL_EXEC(cmd, env) ((((*cmd)[0] == '/') ? (*cmd) : \
    (my_strcat((*env)[search_environnement_var ("PWD", \
    (char const * const *)*env)] + 4, *cmd + 1))))
#define GET_PATH_ENV(sh) ((!sh->bin_path) ? (sh->bin_path_backup) : \
        (sh->bin_path))
#define SEARCH_ENV_VAR(var) (search_environnement_var(var, \
        (char const * const *)sh->env))
//////////////////////////////////////////////////////////////////////////

/* linked_list */
#define NEXT_OPT(y) ((!*(y + 1)) ? (-1) : (y[1][0][0] > 2 && *(y + 3)) ? \
                    (y[3][0][0]) : (y[1][0][0]))
#define PREV_OPT(y, nb) ((nb == 0) ? (-1) : ((*(y - 1))[0][0]))
#define NEXT_CMD(y) ((NEXT_OPT(y) > 2) ? (y + 2) : (y))
#define PREV_CMD(y, nb) ((PREV_OPT(y, nb) > 2) ? (y - 2) : (y))
#define PREV(thing) thing = thing->prev
#define NEXT(thing) thing = thing->next
#define ADD_NODE(new, target) new->next = target; target = new

/* bitwise */
#define BIT(a, b) (a & (1 << b))
#define BITT(a, b) (a & b)
#define TOGGLE(a, b) (a ^= (1 << b))
#define CLEAR_BIT(a, b) (a &= ~(1 << b))
#define SET_BIT(a, b) (a |= b)
#define TOGGLE_BOOL(a) (a = ((a == false) ? (true) : (false)))
