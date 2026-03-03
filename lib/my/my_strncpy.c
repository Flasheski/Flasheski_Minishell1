/*
** EPITECH PROJECT, 2025
** my_strncpy
** File description:
** my_strncpy
*/

#include <stddef.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; n > i; i++){
        dest[i] = src[i];
    }
    return dest;
}
