/*
** EPITECH PROJECT, 2026
** MINISHELL_1
** File description:
** my_unsetenv
*/

#include "my.h"
#include "shell.h"

void shift_env(char **env, int idx)
{
    for (int j = idx; env[j]; j++)
        env[j] = env[j + 1];
}

void exec_builtin_unsetenv(char **args, shell_t *shell)
{
    int idx = 0;

    if (!args[1]) {
        my_puterror("unsetenv: Too few arguments.\n");
        shell->status = 1;
        return;
    }
    for (int i = 1; args[i]; i++) {
        idx = find_var_idx(shell->env, args[i]);
        if (idx != -1) {
            free(shell->env[idx]);
            shift_env(shell->env, idx);
        }
    }
    shell->status = 0;
}
