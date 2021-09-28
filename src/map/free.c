/*
** EPITECH PROJECT, 2021
** map
** File description:
** free
*/

#include "../../include/rpg.h"

void clear_layer(l_t **list)
{
    l_t *current = *list;
    l_t *next;

    while (current != NULL) {
        next = current->next;
        sfVertexArray_destroy(current->arr);
        free(current);
        current = next;
    }
    *list = NULL;
}

void destroy_map(game_t *g)
{
    clear_layer(&g->map.layer);
    sfTexture_destroy(g->map.txtr);
}