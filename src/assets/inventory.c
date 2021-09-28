/*
** EPITECH PROJECT, 2021
** B-MUL-200-RUN-2-1-mydefender-thomas.techer
** File description:
** display_buttons
*/

#include "../../include/rpg.h"

void set_item(game_t *g, int nb)
{
    V2F vp = sfView_getCenter(g->vhud);
    g->ui.item = malloc(sizeof(gui_elem)* nb);
    for (int i = 0; i < nb; i++) {
        g->ui.item[i].spr = sfSprite_create();
        sfSprite_setTexture(g->ui.item[i].spr, (g->ui.item[i].tex =
    sfTexture_createFromFile( "./assets/item/consummable.png", NULL)), sfFalse);
        sfSprite_setPosition(g->ui.item[i].spr,
            (g->ui.item[i].pos = (V2F){vp.x + 146, vp.y - 202}));
        sfSprite_setScale(g->ui.item[i].spr, (V2F){2, 2});
        sfSprite_setTextureRect(g->ui.item[i].spr,
            (g->ui.item->normal = (IR){0, 0, 32, 32}));
        g->ui.item[i].status = NONE;
    }
}

void init_inventory(game_t *g)
{
    V2F vp = sfView_getCenter(g->vhud);
    g->ui.inventory.spr = sfSprite_create();
    sfSprite_setTexture(g->ui.inventory.spr, g->textures.inventory, sfFalse);
    sfSprite_setPosition(g->ui.inventory.spr, (V2F){0, 60});
    sfSprite_setScale(g->ui.inventory.spr, (V2F){0.54, 0.9});
    g->ui.inventory.txt = sfText_create();
    sfText_setFont(g->ui.inventory.txt, (g->ui.inventory.font =
        sfFont_createFromFile("./assets/font/bit_VCR_OSD_MONO.ttf")));
    sfText_setPosition(g->ui.inventory.txt, (V2F){WWTH/2, WHT/2});
    set_item(g, 6);
    set_stow(g, vp);
}

void open_inventory(game_t *g)
{
    if (sfKeyboard_isKeyPressed(sfKeyI)) {
        if (g->sub == INVENTORY) {
            g->sub = SUB_NONE;
            return;
        } else {
            g->sub = INVENTORY;
            return;
        }
    }
}

void disp_inventory(game_t *g, int nb)
{
    if (g->sub == INVENTORY) {
        sfRenderWindow_drawSprite(g->window, g->ui.inventory.spr, NULL);
        sfRenderWindow_drawText(g->window, g->ui.inventory.txt, NULL);
        for (int i = 0; i < nb; i++) {
            sfRenderWindow_drawSprite(g->window, g->ui.item[0].spr, NULL);
        } if (g->ui.s_item[24].tex != NULL)
            sfRenderWindow_drawRectangleShape
                (g->window, g->ui.s_item[24].shape, NULL);
    }
}