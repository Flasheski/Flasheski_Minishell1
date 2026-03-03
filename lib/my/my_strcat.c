/*
** EPITECH PROJECT, 2025
** my_strcat
** File description:
** cat a string
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int idx = my_strlen(dest);

    while (src[i] != '\0'){
        dest[i + idx] = src[i];
        i++;
    }
    dest[i + idx] = '\0';
    return dest;
}
