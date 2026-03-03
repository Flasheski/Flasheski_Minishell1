/*
** EPITECH PROJECT, 2025
** G-PSU-100-LIL-1-1-myls-5
** File description:
** my_puterror
*/

#include "my.h"

void my_puterror(char *str)
{
    write(2, str, my_strlen(str));
}
