/*
** EPITECH PROJECT, 2025
** my_strstr
** File description:
** my_strstr
*/

#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    int idx = my_strlen(to_find);
    int i = 0;

    if (idx == 0)
        return str;
    while (i <= my_strlen(str) - idx) {
        if (my_strncmp(str + i, to_find, idx) == 0)
            return str;
        i++;
    }
    return NULL;
}
