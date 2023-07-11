/*
** EPITECH PROJECT, 2020
** get_export
** File description:
** get_export
*/

#include "src.h"

static bool fill_environnement_variable_content(char const * const * env,
              char const **line, char **new_line, char **index)
{
    unsigned int offset = offset = my_strlen_crt(*env, '=') + 1;
    unsigned int size = *index - *new_line;
    int len = my_strlen(*env + offset);

    if (size == 0) {
        if (!(*new_line = my_strcpy_m(*env + offset))) return (true);
        *index = *new_line + len;
    } else {
        if (!(*new_line = realloc(*new_line, size + len + 1))) return (true);
        *index = *new_line + size;
        my_strcpy(*index, *env + offset);
        *index += len;
    }
    *line += offset;
    if (!(*new_line = realloc(*new_line, *index - *new_line +
       my_strlen_crt(*line, '$') + 1))) return (true);
    *index = *new_line + len + size;
    return (false);
}

static bool insert_environnement_variable_content(sh_t *sh,
              char const **line, char **new_line, char **index)
{
    char const * const *env = (char const * const *)sh->env;
    char *var_name = NULL;
    int env_var = -1;

    for (; env[1]; ++env) {
        RESET(var_name);
        var_name = my_strcpy_crt_m(*env, '=');
        if (!var_name) return (true);
        if (!is_there_an_occurence(*line + 1, var_name))
            continue;
        else if ((env_var = SEARCH_ENV_VAR(var_name)) != -1)
            break;
    }
    if (env_var == -1) return (true);
    if (fill_environnement_variable_content(env, line, new_line, index))
        return (true);
    freeif(var_name);
    return (false);
}

static char *replace_all_environnement_variable(sh_t *sh, char const *line)
{
    unsigned int end = my_strlen_crt(line, '$');
    char *new_line = malloc((end == 0) ? (0) : (end + 1));
    char *index = new_line;

    if (end && !new_line) return (NULL);
    for (; *line; ++line, ++index) {
        if (*line == '$' && insert_environnement_variable_content(sh,
                                           &line, &new_line, &index))
            return (NULL);
        *index = *line;
    }
    *index = 0;
    return (new_line);
}

bool get_export(sh_t *sh, char *line)
{
    char *name = line;
    char *new_var = NULL;

    return (false);
    if (line[my_strlen(line) - 1] == '\n')
        line[my_strlen(line) - 1] = 0;
    if (!line || !*line) return (true);
    skip_fl((char const **)&line, "=", 0, false);
    if (!(new_var = replace_all_environnement_variable(sh, ++line)))
        return (true);
    skip_fl((char const **)&name, " \t", 0, false);
    skip_fl((char const **)&name, " \t", 0, true);
    name[my_strlen_crt(name, '=')] = 0;
    my_setenv(sh, create_and_set_2d_array(3, "setenv", name, new_var));
    return (false);
}
