/*
** EPITECH PROJECT, 2025
** my_putstr
** File description:
** putstr
*/

#include "my.h"

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return 0;
}
