/*
** EPITECH PROJECT, 2025
** str is printable
** File description:
** if str is printable
*/

#include "my.h"

static int my_isprintable(char c)
{
    if (c >= 32 && c <= 126)
        return 1;
    return 0;
}

int my_str_isprintable(char const *str)
{
    if (str == NULL)
        return 0;
    if (str[0] == '\0')
        return 1;
    for (int i = 0; str[i] != '\0'; i++){
        if (my_isprintable(str[i]) == 1)
            return 1;
    }
    return 0;
}
