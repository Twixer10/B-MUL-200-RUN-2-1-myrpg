/*
** EPITECH PROJECT, 2021
** lib/get
** File description:
** number
*/

#include "../../../include/my.h"

int get_nbr_char(char str)
{
    if (str >= '0' && str <= '9' )
        return (str - 48);
    else
        return (0);
}

int get_nbr(char const *str)
{
    int i = 0;
    int nbr = 0;

    if (str[0] == '-' || str[0] == '\0')
        i = i + 1;
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        nbr = nbr * 10 + get_nbr_char(str[i]);
        i = i + 1;
    }
    if (str[0] == '-')
        return (nbr * -1);
    else
        return (nbr);
}

char *get_only_nbr(char *str)
{
    int i = 0;
    int j = 0;
    char *news = MALLOC(news, (sizeof(char) * (str_len(str) + 1)), NULL);

    while (str[i] != '\0') {
        if ((str[i] >= '0' && str[i] <= '9' )) {
            news[j] = str[i];
            j = j + 1;
        }
        i = i + 1;
    }
    return (news);
}

int get_nbr_from_ptn(char **s)
{
    int	rtn = 0;

    while (**s >= 48 && **s <= 57) {
        rtn = rtn * 10;
        rtn = rtn + (**s - '0');
        (*s)++;
    }
    return (rtn);
}