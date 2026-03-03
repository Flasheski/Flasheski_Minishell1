/*
** EPITECH PROJECT, 2026
** G-PSU-200-LIL-2-1-minishell1-4
** File description:
** parse_command
*/

#include "my.h"
#include "shell.h"

char **parse_command(char *line)
{
    char **args;
    char *token;
    int i = 0;

    args = malloc(sizeof(char *) * 64);
    if (!args)
        return NULL;
    token = strtok(line, " \t\n");
    while (token != NULL && i < 63) {
        args[i] = token;
        token = strtok(NULL, " \t\n");
        i++;
    }
    args[i] = NULL;
    return args;
}
