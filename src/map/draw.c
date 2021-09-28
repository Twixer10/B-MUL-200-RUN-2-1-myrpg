/*
** EPITECH PROJECT, 2021
** map
** File description:
** init
*/

#include "../../include/rpg.h"

void draw_map(game_t *g)
{
    l_t *layer = g->map.layer;

    if (layer == NULL || layer->arr == NULL)
        return;
    while (layer != NULL) {
        if (layer->visible)
            sfRenderWindow_drawVertexArray(g->window, layer->arr,
                                           &layer->states);
        layer = layer->next;
    }
}