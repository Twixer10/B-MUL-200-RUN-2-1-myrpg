/*
** EPITECH PROJECT, 2021
** lib/alloc
** File description:
** free
*/

#include "../../../include/my.h"

void delete_string(char **bin)
{
    if (*bin == NULL)
        return;
    free(*bin);
    *bin = NULL;
}

void delete_array(char ***bin)
{
    int i = 0;

    while ((*bin)[i]) {
        delete_string(&(*bin)[i]);
        i++;
    }
    free(*bin);
    *bin = NULL;
}