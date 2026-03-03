/*
** EPITECH PROJECT, 2025
** my_getnbr
** File description:
** get number
*/

#include <string.h>

int my_getnbr(char const *str)
{
    int signe = 1;
    long number = 0;

    while (*str == '-' || *str == '+'){
        if (*str == '-'){
            signe *= -1;
        }
        str++;
    }
    for (; (*str >= '0') == (*str <= '9'); str++){
        number = number * 10 + (*str - '0');
        if (number > 2147483647 && signe == 1)
            return 0;
        if (-number < -2147483648 && signe == -1)
            return 0;
    }
    return number * signe;
}
