/*
** EPITECH PROJECT, 2026
** G-PSU-200-LIL-2-1-minishell1-4
** File description:
** handle_command
*/

#include "my.h"
#include "shell.h"

int check_builtins(char **args, shell_t *shell)
{
    if (my_strcmp(args[0], "exit") == 0)
        return 0;
    if (my_strcmp(args[0], "cd") == 0) {
        exec_builtin_cd(args, shell);
        return 1;
    }
    if (my_strcmp(args[0], "env") == 0) {
        exec_builtin_env(shell->env, &shell->status);
        return 1;
    }
    if (my_strcmp(args[0], "setenv") == 0) {
        exec_builtin_setenv(args, shell);
        return 1;
    }
    if (my_strcmp(args[0], "unsetenv") == 0) {
        exec_builtin_unsetenv(args, shell);
        return 1;
    }
    return -1;
}

int handle_command(char **args, shell_t *shell)
{
    int ret_builtin = 0;

    if (args == NULL || args[0] == NULL)
        return 1;
    ret_builtin = check_builtins(args, shell);
    if (ret_builtin != -1)
        return ret_builtin;
    shell->status = execute_command(args, shell->env, shell);
    return 1;
}
