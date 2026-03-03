/*
** EPITECH PROJECT, 2025
** my_put_nbr
** File description:
** put nbr
*/

#include "my.h"

int my_put_nbr(int nb)
{
    int finish = nb % 10;
    int start = nb / 10;

    if (nb < 0){
        my_putchar('-');
        if (nb < - 2147483647 + 1){
            my_put_nbr(- start);
            return my_put_nbr(- finish);
        }
        return my_put_nbr(- nb);
    }
    if (start != 0){
        my_put_nbr(start);
    }
    my_putchar(finish + '0');
    return 0;
}
