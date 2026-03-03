/*
** EPITECH PROJECT, 2026
** MINISHELL_1
** File description:
** signals
*/

#include "shell.h"
#include "my.h"

void sigint_handler(int sig)
{
    (void)sig;
    if (isatty(0)) {
        my_putstr("\n");
        my_putstr("\033[1;35m");
        my_putstr(" $> ");
        my_putstr("\033[0m");
    }
}

void print_signal_error(int sig, int status)
{
    char *end_message = strsignal(sig);

    if (sig == SIGINT)
        return;
    if (sig == SIGFPE)
        my_puterror("Floating exception");
    if (sig == SIGABRT)
        my_puterror("Abort");
    if (sig == SIGILL)
        my_puterror("Illegal instruction");
    if (sig != SIGFPE && sig != SIGABRT && sig != SIGILL && end_message)
        my_puterror(end_message);
    if (WCOREDUMP(status))
        my_puterror(" (core dumped)");
    my_puterror("\n");
}

void check_child_status(int status, shell_t *shell)
{
    int sig = 0;

    if (WIFEXITED(status)) {
        shell->status = WEXITSTATUS(status);
        return;
    }
    if (WIFSIGNALED(status)) {
        sig = WTERMSIG(status);
        print_signal_error(sig, status);
        shell->status = 128 + sig;
    }
}
