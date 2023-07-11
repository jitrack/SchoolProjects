/*
** EPITECH PROJECT, 2020
** freeif
** File description:
** frees if it exist
*/

#include <stdlib.h>
#include <stddef.h>

void freeif(void *elem)
{
    if (elem != NULL)
        free(elem);
}

void free_2d_array(char **array)
{
    if (array) {
        for (int i = 0; array[i]; ++i)
            freeif(array[i]);
        freeif(array);
    }
}

char ***free_3d_array(char ***array)
{
    if (!array) return (NULL);
    for (int i = 0; array[i]; ++i)
        if (array[i])
            free_2d_array(array[i]);
    freeif(array);
    return (NULL);
}

char ****free_4d_array(char ****array)
{
    if (!array || !*array) return (NULL);
    for (char ****i = array; 1[i]; ++i)
        if (*i) free_3d_array(*i);
    freeif(array);
    return (NULL);
}
