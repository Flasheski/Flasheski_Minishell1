/*
** EPITECH PROJECT, 2025
** my_strncat
** File description:
** cat string with n
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int idx = my_strlen(dest);

    while (src[i] != '\0' && i < nb){
        dest[i + idx] = src[i];
        i++;
    }
    dest[i + idx] = '\0';
    return dest;
}
