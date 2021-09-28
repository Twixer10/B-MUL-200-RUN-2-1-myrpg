/*
** EPITECH PROJECT, 2021
** map
** File description:
** init
*/

#include "../../include/rpg.h"

void init_tile_info(mxml_node_t *map, game_t *g)
{
    const char *w = mxmlElementGetAttr(map, "tilewidth");
    const char *h = mxmlElementGetAttr(map, "tileheight");
    mxml_node_t *tile = XMLFE(map, map, "tileset", NULL, NULL, MXML_DESCEND);
    const char *gid = mxmlElementGetAttr(tile, "firstgid");
    const char *cols = mxmlElementGetAttr(tile, "columns");
    mxml_node_t *image = XMLFE(tile, tile, "image", NULL, NULL, MXML_DESCEND);
    const char *src = mxmlElementGetAttr(image, "source");
    char *path = NULL;

    g->map.size = MV2F(get_nbr(w), get_nbr(h));
    g->map.gid = get_nbr(gid);
    g->map.cols = get_nbr(cols);
    my_asprintf(&path, "./assets/map/%s", src);
    g->map.txtr = sfTexture_createFromFile(path, NULL);
    g->map.collision = malloc(sizeof(char *));
    free(path);
}

void generate_map(game_t *g)
{
    FILE *fp;
    fp = fopen("./assets/map/tst.tmx", "r");
    mxml_node_t *tree = mxmlLoadFile(NULL, fp, MXML_OPAQUE_CALLBACK);
    fclose(fp);
    mxml_node_t *node = XMLFE(tree, tree, "map", NULL, NULL, MXML_DESCEND);

    if (!tree || !node)
        return;
    get_map(node, g);
    mxmlDelete(node);
    mxmlDelete(tree);
}