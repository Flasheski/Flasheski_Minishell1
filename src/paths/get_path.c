/*
** EPITECH PROJECT, 2026
** G-PSU-200-LIL-2-1-minishell1-4
** File description:
** get_path
*/

#include "my.h"
#include "shell.h"

char *get_env_specific(char **env, char *var)
{
    int i = 0;
    int len = my_strlen(var);

    if (env == NULL || var == NULL)
        return NULL;
    while (env[i] != NULL) {
        if (my_strncmp(env[i], var, len) == 0 && env[i][len] == '=')
            return (env[i] + len + 1);
        i++;
    }
    return NULL;
}

char *get_env_with_path(char **env)
{
    int i = 0;

    if (env == NULL)
        return NULL;
    while (env[i] != NULL) {
        if (my_strncmp(env[i], "PATH=", 5) == 0)
            return (env[i] + 5);
        i++;
    }
    return NULL;
}
