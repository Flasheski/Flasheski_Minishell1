/*
** EPITECH PROJECT, 2025
** my_swap
** File description:
** swap
*/

#include <stdio.h>

void my_swap(int *a, int *b)
{
    int dir = *b;

    *b = *a;
    *a = dir;
}
