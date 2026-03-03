/*
** EPITECH PROJECT, 2026
** G-PSU-200-LIL-2-1-minishell1-4
** File description:
** cd_command
*/

#include "my.h"
#include "shell.h"

char *my_get_home(char **env)
{
    if (!env)
        return NULL;
    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], "HOME=", 5) == 0)
            return &env[i][5];
    }
    return NULL;
}

char *get_cd_path(char **args, char **env, char *prev)
{
    char *path = args[1];

    if (path == NULL || my_strcmp(path, "~") == 0)
        return my_get_home(env);
    if (my_strcmp(path, "-") == 0) {
        if (!prev) {
            my_puterror(": No such file or directory.\n");
            return NULL;
        }
        my_putstr(prev);
        my_putchar('\n');
        return prev;
    }
    return args[1];
}

void exec_builtin_cd(char **args, shell_t *shell)
{
    char *path = get_cd_path(args, shell->env, shell->prev_path);
    char *current = getcwd(NULL, 0);

    if (args[1] && args[2]) {
        my_puterror("cd : Too many arguments.\n");
        shell->status = 1;
        return (free(current));
    }
    if (!path || chdir(path) == -1) {
        if (path && args[1][0] != '-')
            print_cd_path(path);
        shell->status = 1;
        free(current);
    } else {
        if (shell->prev_path)
            free(shell->prev_path);
        shell->prev_path = current;
        shell->status = 0;
    }
}
