/*
** EPITECH PROJECT, 2025
** my_compute_power_rec
** File description:
** power recursive
*/

#include <unistd.h>

int my_compute_power_rec(int nb, int p)
{
    int answer_rec = 1;

    if (p < 0)
        return 0;
    if (p == 0)
        return 1;
    for (; p >= 1; p--){
        return nb * my_compute_power_rec(nb, p - 1);
        if (answer_rec < -2147483648 + 1 || answer_rec > 2147483647)
            return 0;
    }
    return answer_rec;
}
