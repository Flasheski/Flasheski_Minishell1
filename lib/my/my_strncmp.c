/*
** EPITECH PROJECT, 2025
** my_strncmp
** File description:
** compare strings with n
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (n == 0)
        return 0;
    for (; i < n && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]; i++);
    if (i == n)
        return 0;
    return (s1[i] - s2[i]);
}
