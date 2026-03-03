/*
** EPITECH PROJECT, 2026
** G-PSU-200-LIL-2-1-minishell1-4
** File description:
** exec
*/

#include "my.h"
#include "shell.h"
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

int is_invalid_bin(char *path, shell_t *shell)
{
    struct stat s;

    if (stat(path, &s) == -1)
        return 0;
    if (S_ISDIR(s.st_mode)) {
        my_puterror(path);
        my_puterror(": Permission denied.\n");
        shell->status = 1;
        return 1;
    }
    return 0;
}

void handle_exec_error(char *path, shell_t *shell)
{
    my_puterror(path);
    if (errno == ENOEXEC) {
        my_puterror(": Exec format error. Wrong Architecture.\n");
        shell->status = 1;
    } else {
        my_puterror(": Permission denied.\n");
        shell->status = 1;
    }
    exit(ERROR_EXIT);
}

void run_process(char *path, char **args, char **env, shell_t *shell)
{
    pid_t pid = fork();
    int status = 0;

    if (pid == 0) {
        if (execve(path, args, env) == -1)
            handle_exec_error(path, shell);
    } else {
        waitpid(pid, &status, 0);
        check_child_status(status, shell);
    }
}

int execute_command(char **args, char **env, shell_t *shell)
{
    char *path = find_command(args[0], env);

    if (!path) {
        my_puterror(args[0]);
        my_puterror(": Command not found.\n");
        shell->status = 1;
        return 1;
    }
    if (is_invalid_bin(path, shell)) {
        free(path);
        return 1;
    }
    run_process(path, args, env, shell);
    free(path);
    return shell->status;
}
