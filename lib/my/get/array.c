/*
** EPITECH PROJECT, 2021
** lib/get
** File description:
** array
*/

#include "../../../include/my.h"

int array_len(char **array)
{
    int i = 0;

    while (array[i] != NULL)
        i++;
    return (i);
}