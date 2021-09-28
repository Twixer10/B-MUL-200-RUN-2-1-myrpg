/*
** EPITECH PROJECT, 2021
** Windows manager
** File description:
** Manage all windows
*/

#include "../../include/rpg.h"

void init_windows(game_t *g)
{
    g->sub = 0;
    g->state = MENU;
    g->window = sfRenderWindow_create((sfVideoMode) {WWTH, WHT, 32},
    "MY RPG", sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(g->window, 60);
    g->clock.clock = sfClock_create();
    g->menu.sprite = sfSprite_create();
    sfMusic_play(g->music.main_theme);
    sfMusic_setLoop(g->music.main_theme, TRUE);
    sfMusic_setVolume(g->music.main_theme, 100.0);
    sfMusic_setPitch(g->music.main_theme, 0.8);
    sfSprite_setTexture(g->menu.sprite, g->textures.menu_background, TRUE);
    g->menu.rect = (sfIntRect) {0, 0, 329, 222};
    sfSprite_scale(g->menu.sprite, (sfVector2f) {5.835866261, 4.864864865});
}

void update_texture(sfSprite **sprite, sfTexture *texture)
{
    sfSprite_setTexture(*(sprite), texture, TRUE);
}