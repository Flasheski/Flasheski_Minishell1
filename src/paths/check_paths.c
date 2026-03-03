/*
** EPITECH PROJECT, 2026
** G-PSU-200-LIL-2-1-minishell1-4
** File description:
** check_paths
*/

#include "my.h"
#include "shell.h"

char *build_path(char *dir, char *command)
{
    char *full_path;
    int len = my_strlen(dir) + my_strlen(command) + 2;

    full_path = malloc(sizeof(char) * len);
    if (!full_path)
        return NULL;
    my_strcpy(full_path, dir);
    my_strcat(full_path, "/");
    my_strcat(full_path, command);
    return full_path;
}

char *check_path_with_dirs(char *path_copy, char *command)
{
    char *token;
    char *full_path;

    token = strtok(path_copy, ":");
    while (token != NULL) {
        full_path = build_path(token, command);
        if (full_path != NULL && access(full_path, X_OK) == 0)
            return full_path;
        free(full_path);
        token = strtok(NULL, ":");
    }
    return NULL;
}
