/*
** EPITECH PROJECT, 2021
** lib/array
** File description:
** my_str_arr
*/

#include "../../../include/my.h"

int nb_stwa(const char *str)
{
    int i = 0;
    int value = 1;

    while (str[i] != '\0') {
        if (char_is_alpha_num(str[i]) == 0)
            value++;
        i++;
    }
    return (value);
}

int len_stwa(const char *str)
{
    int i = 0;
    int value = 0;

    while (str[i] != '\0' && char_is_alpha_num(str[i]) == 0)
        i++;
    while (str[i] != '\0') {
        if (char_is_alpha_num(str[i]) == 0)
            return (value);
        i++;
        value++;
    }
    return (value);
}

char **stwa(const char *str)
{
    int j = 0;
    int k = 0;
    char **tmp = MALLOC(tmp, (sizeof(char *) * (nb_stwa(str) + 1)), NULL);

    for (int i = 0; str[i] != '\0'; i++) {
        MALLOC(tmp[j], (sizeof(char) * (len_stwa(str + i) + 1)), NULL);
        k = 0;
        while (char_is_alpha_num(str[i]) == 1 && str[i] != '\0')
            tmp[j][k++] = str[i++];
        tmp[j++][k] = '\0';
        if (str[i] == '\0') break;
    }
    return (tmp);
}
