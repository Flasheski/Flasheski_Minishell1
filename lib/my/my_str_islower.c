/*
** EPITECH PROJECT, 2025
** is_str_lower
** File description:
** is str lower
*/

#include <stdio.h>

static int is_lower(char const *str, int i)
{
    if (str[i] >= 'a' && str[i] <= 'z')
        return 0;
    return 1;
}

int my_str_islower(char const *str)
{
    int i = 0;

    if (str[i] == '\0')
        return 1;
    for (; str[i] != '\0'; i++){
        if (is_lower(str, i) != 0)
            return 0;
    }
    return 1;
}
