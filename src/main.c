/*
** EPITECH PROJECT, 2026
** G-PSU-200-LIL-2-1-minishell1-4
** File description:
** main
*/

#include "my.h"
#include "shell.h"

int shell_loop(shell_t *shell)
{
    char **args = NULL;
    char *line = NULL;
    size_t len = 0;
    int run = 1;

    signal(SIGINT, sigint_handler);
    while (run) {
        display_path_prompt(shell);
        if (getline(&line, &len, stdin) == -1)
            break;
        args = parse_command(line);
        if (args && args[0])
            run = handle_command(args, shell);
        free(args);
    }
    free(line);
    return shell->status;
}

int main(int argc, char **argv, char **env)
{
    shell_t shell = {copy_env(env), NULL, 0};
    int status = 0;

    (void)argc;
    (void)argv;
    status = shell_loop(&shell);
    if (shell.prev_path)
        free(shell.prev_path);
    return status;
}
