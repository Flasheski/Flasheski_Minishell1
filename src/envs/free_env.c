/*
** EPITECH PROJECT, 2026
** MINISHELL_1
** File description:
** free_env
*/

#include "shell.h"
#include "my.h"

void free_env(char **env)
{
    if (env == NULL)
        return;
    for (int i = 0; env[i] != NULL; i++)
        free(env[i]);
    free(env);
}
