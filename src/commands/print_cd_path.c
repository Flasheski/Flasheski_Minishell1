/*
** EPITECH PROJECT, 2026
** MINISHELL_1
** File description:
** print_cd_path
*/

#include "my.h"
#include "shell.h"

void print_cd_path(char *path)
{
    struct stat st;

    my_puterror(path);
    if (stat(path, &st) == -1)
        my_puterror(": No such file or directory.\n");
    else if (!S_ISDIR(st.st_mode))
        my_puterror(": Not a directory.\n");
    else
        my_puterror(": Permission denied.\n");
}
