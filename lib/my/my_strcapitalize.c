/*
** EPITECH PROJECT, 2025
** strcapitalize
** File description:
** str capitalize
*/

#include <stdio.h>

static char *to_lower(char *str, int i)
{
    if (str[i] >= 'A' && str[i] <= 'Z')
        str[i] += 32;
    return str;
}

static char *to_upper(char *str, int i)
{
    if (str[i] >= 'a' && str[i] <= 'z')
        str[i] -= 32;
    return str;
}

static int is_alpha_num(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
        || (c >= '0' && c <= '9'))
        return 1;
    return 0;
}

static void check_first(char *str, int i, int first_letter)
{
    if (first_letter && (str[i] >= 'a' && str[i] <= 'z'))
        to_upper(str, i);
    else if (!first_letter && (str[i] >= 'A' && str[i] <= 'Z'))
        to_lower(str, i);
}

char *my_strcapitalize(char *str)
{
    int first_letter = 1;

    for (int i = 0; str[i] != '\0'; i++){
        if (is_alpha_num(str[i]) == 0){
            first_letter = 1;
        } else {
            check_first(str, i, first_letter);
            first_letter = 0;
        }
    }
    return str;
}
