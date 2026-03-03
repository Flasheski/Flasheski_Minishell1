/*
** EPITECH PROJECT, 2025
** my_str_to_word_array
** File description:
** str to word array
*/

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

static int my_is_alphanum(char c)
{
    if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z')){
        return 1;
    }
    return 0;
}

static int count_words(char const *str)
{
    int count = 0;
    int word = 0;

    for (int i = 0; str[i] != '\0'; i++){
        if (my_is_alphanum(str[i]) == 0 && !word){
            count++;
            word = 1;
        }
        if (!my_is_alphanum(str[i]))
            word = 0;
    }
    return count;
}

int search_next(char const *str, int i)
{
    for (; str[i] != '\0'; i++){
        if (my_is_alphanum(str[i]))
            return i;
    }
    return i;
}

int my_strword(char const *str, int idx)
{
    int number = 0;

    while (str[number] != '\0' && my_is_alphanum(str[idx])) {
        number++;
        idx++;
    }
    return number;
}

char **my_str_to_word_array(char const *str)
{
    char **dest = malloc(sizeof(char *) * count_words(str) + 1);
    int i = search_next(str, 0);
    int compteur = 0;
    int second = 0;

    while (str[i] != '\0'){
        dest[compteur] = malloc(sizeof(char) * my_strword(str, i) + 1);
        while (my_is_alphanum(str[i]) == 1){
            dest[compteur][second] = str[i];
            i++;
            second++;
        }
        i = search_next(str, i);
        dest[compteur][second] = '\0';
        compteur += 1;
        second = 0;
    }
    dest[compteur] = NULL;
    return dest;
}
