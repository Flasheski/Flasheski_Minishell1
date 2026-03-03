/*
** EPITECH PROJECT, 2025
** strisalpha
** File description:
** str alpha
*/

#include <stdio.h>

int my_str_isnum(char const *str)
{
    int i = 0;

    if (str[i] == '\0')
        return 1;
    for (; str[i] != '\0'; i++){
        if (!((str[i] >= '0' && str[i] <= '9')))
            return 0;
    }
    return 1;
}
