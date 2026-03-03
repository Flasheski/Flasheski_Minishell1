/*
** EPITECH PROJECT, 2025
** my_strlen
** File description:
** length of a string
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int number = 0;

    if (str == NULL)
        return 0;
    while (str[number] != '\0') {
        number++;
    }
    return number;
}
