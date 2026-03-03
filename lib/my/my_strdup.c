/*
** EPITECH PROJECT, 2025
** G-PSU-100-LIL-1-1-myls-5
** File description:
** my_strdup
*/

#include "my.h"

char *my_strdup(char const *src)
{
    char *idx = malloc(my_strlen(src) + 1);

    if (idx == NULL)
        return NULL;
    my_strcpy(idx, src);
    return idx;
}
