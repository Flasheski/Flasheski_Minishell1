/*
** EPITECH PROJECT, 2025
** my_revstr
** File description:
** reverse a string
*/

static int size(char const *str)
{
    int count = 0;

    for (char const *width = str; *width != '\0'; width++)
        count++;
    return count;
}

char *my_revstr(char *str)
{
    int s = 0;
    int end;
    char tmp;

    end = size(str) - 1;
    for (; s < end; s++){
        tmp = str[s];
        str[s] = str[end];
        str[end] = tmp;
        end--;
    }
    return str;
}
