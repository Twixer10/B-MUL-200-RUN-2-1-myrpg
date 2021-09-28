/*
** EPITECH PROJECT, 2021
** LOOP MENU
** File description:
** INSTANCE OF MENU
*/

#include "../../include/rpg.h"

void init_ngbck(game_t *g) {
    g->textures.hud_name = sfTexture_createFromFile("assets/menu/hud_name.png",
                                                    NULL);
    g->ng.sprite = sfSprite_create();
    sfSprite_setTexture(g->ng.sprite, g->textures.hud_name, 0);
    g->ng.rect = (IR) {0, 0, 800, 430};
    sfSprite_setTextureRect(g->ng.sprite, g->ng.rect);
    sfSprite_setPosition(g->ng.sprite, MV2F(WHT / 2 + 25, WWTH / 6));
}