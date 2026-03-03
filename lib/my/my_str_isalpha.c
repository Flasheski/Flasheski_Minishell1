/*
** EPITECH PROJECT, 2025
** strisalpha
** File description:
** str alpha
*/

#include <stdio.h>

static int check_alpha(char const *str, int i)
{
    if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        return 0;
    return 1;
}

int my_str_isalpha(char const *str)
{
    int i = 0;

    if (str[i] == '\0')
        return 1;
    for (; str[i] != '\0'; i++){
        if (check_alpha(str, i) != 0)
            return 0;
    }
    return 1;
}
