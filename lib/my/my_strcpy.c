/*
** EPITECH PROJECT, 2025
** my_strcpy
** File description:
** my_strcpy
*/

#include <stddef.h>

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (src == NULL)
        return NULL;
    for (; src[i] != '\0'; i++){
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
