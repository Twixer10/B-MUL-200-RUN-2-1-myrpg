/*
** EPITECH PROJECT, 2021
** assets manager
** File description:
** manage asset
*/

#include "../../include/rpg.h"

void load_assets(game_t *g)
{
    g->textures.menu_background = sfTexture_createFromFile(
        "./assets/menu/main.png", NULL);
    g->textures.btn_texture = sfTexture_createFromFile(
        "./assets/buttons/button.png", NULL);
    g->textures.inventory = sfTexture_createFromFile(
        "./assets/HUD/UI_inventory.png", NULL);
    g->textures.slider = sfTexture_createFromFile(
        "./assets/menu/sliders.png", NULL);
    g->sliders = malloc(sizeof(slider_t) * 3);
    for (int i = 0; i <= 2; i++) {
        g->sliders[i] = create_slider(i);
        sfSprite_setTexture(g->sliders[i].sprite, g->textures.slider, TRUE);
        sfSprite_move(g->sliders[i].sprite, g->sliders[i].pos_max);
    }
    init_music(g);
}
