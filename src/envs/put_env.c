/*
** EPITECH PROJECT, 2026
** MINISHELL_1
** File description:
** put_env
*/

#include "shell.h"
#include "my.h"

char **copy_env(char **env)
{
    int i = 0;
    char **new_env = NULL;

    while (env[i])
        i++;
    new_env = malloc(sizeof(char *) * (i + 1));
    if (!new_env)
        return NULL;
    for (int j = 0; j < i; j++)
        new_env[j] = my_strdup(env[j]);
    new_env[i] = NULL;
    return new_env;
}

void exec_builtin_env(char **env, int *status)
{
    if (env == NULL) {
        *status = 0;
        return;
    }
    for (int i = 0; env[i]; i++) {
        my_putstr(env[i]);
        my_putchar('\n');
    }
    *status = 0;
}
