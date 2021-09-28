/*
** EPITECH PROJECT, 2021
** B-MUL-200-RUN-2-1-myrpg-thomas.techer
** File description:
** new game
*/

#include "../../include/rpg.h"

void update_background(game_t *g)
{
    sfRenderWindow_display(g->window);
    g->clock.time = sfClock_getElapsedTime(g->clock.clock);
    g->clock.seconds = g->clock.time.microseconds / 1000000.0;
    if (g->clock.seconds > 0.23) {
        move_rect(&g->menu.rect, 329, 1316);
        sfClock_restart(g->clock.clock);
    }
    sfSprite_setTextureRect(g->menu.sprite, g->menu.rect);
    sfRenderWindow_drawSprite(g->window, g->menu.sprite, NULL);
}