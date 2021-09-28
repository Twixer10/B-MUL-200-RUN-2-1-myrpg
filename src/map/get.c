/*
** EPITECH PROJECT, 2021
** map
** File description:
** get
*/

#include "../../include/rpg.h"

void get_map(mxml_node_t *map, game_t *g)
{
    init_tile_info(map, g);
    mxml_node_t *layer = XMLFE(map, map, "layer", NULL, NULL, MXML_DESCEND);
    g->map.layer = NULL;

    while (layer != NULL) {
        const char *src = mxmlElementGetAttr(layer, "visible");
        l_t tmp;
        tmp.arr = get_layer(layer, g);
        tmp.states.texture = g->map.txtr;
        tmp.visible = get_nbr((src ? "0" : "1"));
        add_layer(&g->map.layer, tmp);
        if (mxmlElementGetAttr(layer, "name"))

        layer = XMLFE(layer, map, "layer", NULL, NULL, MXML_DESCEND);
    }
}

sfVertexArray *get_layer(mxml_node_t *layer, game_t *g)
{
    sfVertexArray *arr = sfVertexArray_create();
    mxml_node_t *chunk = XMLFE(layer, layer, "chunk", NULL, NULL, MXML_DESCEND);

    while (chunk != NULL) {
        get_chunk(chunk, arr, g);
        chunk = XMLFE(chunk, layer, "chunk", NULL, NULL, MXML_DESCEND);
    }
    return (arr);
}

void get_chunk(mxml_node_t *chunk, sfVertexArray *array, game_t *g)
{
    int x = get_nbr(mxmlElementGetAttr(chunk, "x"));
    int y = get_nbr(mxmlElementGetAttr(chunk, "y"));
    const char *csv = mxmlGetOpaque(chunk);
    char **data = my_strtok(remove_chariot(csv), ',');

    get_csv(data, array, MV2F(x, y), g);
}

void get_csv(char **data, sfVertexArray *array, sfVector2f pos, game_t *g)
{
    int a = 0;
    int x = 0;
    int y = 0;
    char *tmp = NULL;

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            tmp = data[(i*16)+j];
            if (tmp && str_cmp(tmp, "0")) {
                a = get_nbr(tmp);
                x = a % g->map.cols;
                y = a / g->map.cols;
                add_vertex(array, MV2F(pos.x+j, pos.y+i),
                           MV2F(x-1, y), g->map.size);
            }
        }
    }
}