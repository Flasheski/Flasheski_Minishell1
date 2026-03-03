/*
** EPITECH PROJECT, 2025
** my_compute_square_root
** File description:
** compute square root
*/

#include <unistd.h>

int my_compute_square_root(int nb)
{
    int sqr = 1;

    if (nb > 2147483647 || nb < 0)
        return 0;
    if (nb == 1)
        return 1;
    for (; sqr < nb; sqr++){
        if (sqr * sqr == nb)
            return sqr;
    }
    return 0;
}
