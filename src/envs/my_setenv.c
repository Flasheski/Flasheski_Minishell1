/*
** EPITECH PROJECT, 2026
** MINISHELL_1
** File description:
** my_setenv
*/

#include "my.h"
#include "shell.h"

static int my_is_alphanumeric(char *str)
{
    if (!((str[0] >= 'a' && str[0] <= 'z') ||
            (str[0] >= 'A' && str[0] <= 'Z'))) {
        my_puterror("setenv: Variable name must begin with a letter.\n");
        return 0;
    }
    for (int i = 0; str[i]; i++) {
        if (!((str[i] >= 'a' && str[i] <= 'z') ||
                (str[i] >= 'A' && str[i] <= 'Z') ||
                (str[i] >= '0' && str[i] <= '9') || str[i] == '_')) {
            my_puterror("setenv: Variable name");
            my_puterror(" must contain alphanumeric characters.\n");
            return 0;
        }
    }
    return 1;
}

char *create_env_line(char *name, char *value)
{
    int len = my_strlen(name) + (value ? my_strlen(value) : 0) + 2;
    char *new_line = malloc(sizeof(char) * len);

    if (!new_line)
        return NULL;
    my_strcpy(new_line, name);
    my_strcat(new_line, "=");
    if (value)
        my_strcat(new_line, value);
    return new_line;
}

int find_var_idx(char **env, char *name)
{
    int len = my_strlen(name);

    for (int i = 0; env && env[i]; i++) {
        if (my_strncmp(env[i], name, len) == 0 && env[i][len] == '=')
            return i;
    }
    return -1;
}

char **add_to_env(char **env, char *new_line)
{
    int i = 0;
    char **new_env = NULL;

    while (env && env[i])
        i++;
    new_env = malloc(sizeof(char *) * (i + 2));
    if (!new_env)
        return NULL;
    for (int j = 0; j < i; j++)
        new_env[j] = env[j];
    new_env[i] = new_line;
    new_env[i + 1] = NULL;
    return new_env;
}

void update_env(shell_t *shell, char *name, char *value)
{
    int idx = find_var_idx(shell->env, name);
    char *line = create_env_line(name, value);
    char **old_env = NULL;

    if (idx != -1) {
        free(shell->env[idx]);
        shell->env[idx] = line;
    } else {
        old_env = shell->env;
        shell->env = add_to_env(shell->env, line);
        free(old_env);
    }
}

void exec_builtin_setenv(char **args, shell_t *shell)
{
    if (!args[1]) {
        exec_builtin_env(shell->env, &shell->status);
        return;
    }
    if (args[1] && args[2] && args[3]) {
        my_puterror("setenv: Too many arguments.\n");
        shell->status = 1;
        return;
    }
    if (!my_is_alphanumeric(args[1])) {
        shell->status = 1;
        return;
    }
    update_env(shell, args[1], args[2]);
    shell->status = 0;
}
