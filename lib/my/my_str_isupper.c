/*
** EPITECH PROJECT, 2025
** is_str_lower
** File description:
** is str lower
*/

#include <stdio.h>

static int is_upper(char const *str, int i)
{
    if (str[i] >= 'A' && str[i] <= 'Z')
        return 0;
    return 1;
}

int my_str_isupper(char const *str)
{
    int i = 0;

    if (str[i] == '\0')
        return 1;
    for (; str[i] != '\0'; i++){
        if (is_upper(str, i) != 0)
            return 0;
    }
    return 1;
}
