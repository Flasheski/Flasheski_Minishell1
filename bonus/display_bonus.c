/*
** EPITECH PROJECT, 2026
** MINISHELL_1
** File description:
** display_bonus
*/

#include "my.h"
#include "shell.h"

void display_path_prompt(shell_t *shell)
{
    char *cwd = getcwd(NULL, 0);
    char *home = get_env_specific(shell->env, "HOME");
    int idx_len = (home) ? my_strlen(home) : 0;

    if (!isatty(0))
        return free(cwd);
    my_putstr("\033[1;31m[");
    if (cwd && home && my_strncmp(cwd, home, idx_len) == 0) {
        my_putstr("~");
        my_putstr(cwd + idx_len);
    } else if (cwd)
        my_putstr(cwd);
    else
        my_putstr("unknown-location");
    my_putstr("]\033[1;33m $> \033[0m");
    if (cwd)
        free(cwd);
}
