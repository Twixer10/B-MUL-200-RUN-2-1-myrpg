/*
** EPITECH PROJECT, 2021
** lib/char
** File description:
** check_char
*/

#include "../../../include/my.h"

int char_is_op(char c, char op)
{
    if (c != op)
        return (FALSE);
    else
        return (TRUE);
}

int char_is_chariot(char c, char cn)
{
    if ((c == '\\' && cn == 'n') || (c == '\\' && cn == 't') ||
    (c == '\\' && cn == 'r'))
        return (1);
    else
        return (0);
}

int char_is_alpha_num(char c)
{
    if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') ||
    (c >= 'a' && c <= 'z'))
        return (1);
    else
        return (0);
}