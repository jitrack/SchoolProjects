/*
** EPITECH PROJECT, 2019
** check_fct
** File description:
** check-fct
*/

#include "include/my.h"

int open_fl(char const *str)
{
    if (str == NULL) return (-1);
    return (open(str, O_RDONLY, S_IROTH));
}

char *str_detect_path(char const *path)
{
    char *str;
    int fd = open_fl(path);
    struct stat info;

    if (fd == -1) return (NULL);
    fstat(fd, &info);
    str = malloc(sizeof(char) * (info.st_size + 1));
    if (!str) return (NULL);
    str[info.st_size] = '\0';
    read(fd, str, info.st_size);
    close(fd);
    return (str);
}

char *str_detect_fd(int const fd)
{
    char *str;
    struct stat info;
    int len = 10;

    if (fd == -1) return (NULL);
    str = malloc(sizeof(char) * (len + 1));
    if (!str) return (NULL);
    str[len] = '\0';
    read(fd, str, len);
    close(fd);
    return (str);
}
