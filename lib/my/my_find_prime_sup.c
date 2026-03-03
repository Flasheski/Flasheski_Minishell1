/*
** EPITECH PROJECT, 2025
** my_find_prime_sup
** File description:
** find prime nbr
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    while ((my_is_prime(nb) != 1)){
        nb++;
    }
    return nb;
}
