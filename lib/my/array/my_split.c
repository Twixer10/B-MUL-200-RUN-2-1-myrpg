/*
** EPITECH PROJECT, 2021
** lib/array
** File description:
** my_str_arr
*/

#include "../../../include/my.h"

int nb_split(char *str, char op)
{
    int i = 0;
    int value = 1;

    while (str[i] != '\0') {
        if (str[i] == op)
            value++;
        i++;
    }
    return (value);
}

int len_split(char *str, char op)
{
    int i = 0;
    int value = 0;

    while (str[i] != '\0' && str[i] == op)
        i++;
    while (str[i] != '\0') {
        if (str[i] == op)
            return (value);
        i++;
        value++;
    }
    return (value);
}

char **my_split(char *str, char op)
{
    int j = 0;
    int k = 0;
    char **tmp = MALLOC(tmp, (sizeof(char *)*(nb_split(str, op)+1)), NULL);

    for (int i = 0; str[i] != '\0'; i++) {
        tmp[j] = MALLOC(tmp[j], (sizeof(char)*(len_split(str+i, op)+1)), NULL);
        k = 0;
        while (str[i] != op && str[i] != '\0') {
            tmp[j][k] = str[i];
            k++;
            i++;
        }
        tmp[j][k] = '\0';
        j++;
        if (str[i] == '\0')
            break;
    }
    tmp[j] = NULL;
    return (tmp);
}
