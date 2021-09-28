/*
** EPITECH PROJECT, 2021
** map
** File description:
** add
*/

#include "../../include/rpg.h"

void add_vertex(sfVertexArray *arr, sfVector2f pa, sfVector2f pb, sfVector2f s)
{
    pa.x *= s.x;
    pb.x *= s.x;
    pa.y *= s.y;
    pb.y *= s.y;
    sfVertex a = {pa, sfWhite, pb};
    sfVertex b = {MV2F(pa.x+s.x, pa.y), sfWhite, MV2F(pb.x+s.x, pb.y)};
    sfVertex c = {MV2F(pa.x+s.x, pa.y+s.y), sfWhite, MV2F(pb.x+s.x, pb.y+s.y)};
    sfVertex d = {MV2F(pa.x, pa.y+s.y), sfWhite, MV2F(pb.x, pb.y+s.y)};
    sfVertexArray_append(arr, a);
    sfVertexArray_append(arr, b);
    sfVertexArray_append(arr, c);
    sfVertexArray_append(arr, d);
}

void add_layer(l_t **list, l_t elem)
{
    l_t *l = my_calloc(1, sizeof(l_t));

    if (elem.arr != NULL)
        sfVertexArray_setPrimitiveType(elem.arr, sfQuads);
    l->arr = elem.arr;
    l->states.texture = elem.states.texture;
    l->visible = elem.visible;
    l->states.transform = sfTransform_Identity;
    l->states.blendMode = sfBlendAlpha;
    l->next = NULL;
    if (*list != NULL) {
        l_t *current = *list;
        while (current->next != NULL)
            current = current->next;
        current->next = l;
    } else
        *list = l;
}