/*
** EPITECH PROJECT, 2025
** SETTING UP
** File description:
** my_atoi
*/

#include "my.h"

int my_atoi(char *str)
{
    int result = 0;
    int i = 0;

    for (; str[i] != '\0'; i++)
        result = result * 10 + (str[i] - '0');
    return result;
}
