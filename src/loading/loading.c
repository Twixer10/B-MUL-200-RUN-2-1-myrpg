/*
** EPITECH PROJECT, 2021
** B-MUL-200-RUN-2-1-myrpg-thomas.techer
** File description:
** new game
*/

#include "../../include/rpg.h"

void wait_loading(game_t *g)
{
    init_player(g);
    init_views(g);
    set_life(g);
    init_inventory(g);
    generate_map(g);
    sfSleep(g->loading.time.microseconds * 3000000.0);
}

void init_loading(game_t *g)
{
    sfTexture *ldn = sfTexture_createFromFile("assets/HUD/loading.png", NULL);
    g->loading.sprite = sfSprite_create();
    g->loading.rect = (sfIntRect) {0, 0, 720, 90};
    sfSprite_setTexture(g->loading.sprite, ldn, 0);
    sfSprite_scale(g->loading.sprite, MV2F(2, 2);
    sfSprite_setTextureRect(g->loading.sprite, g->loading.rect);
    g->loading.clock = sfClock_create();
    g->loading.time = sfClock_getElapsedTime(g->loading.clock);
    g->loading.seconds = g->loading.time.microseconds  / 1000000.0;
    g->state = LOADG;
}

void loading_screen(game_t *g)
{
    sfThread *loading = sfThread_create(&wait_loading, g);

    sfRenderWindow_display(g->window);
    sfRenderWindow_clear(g->window, sfBlack);
    sfThread_launch(loading);
    if (g->loading.seconds > 0.23) {
        move_rect(&g->loading.rect, 90, 720);
        sfClock_restart(g->loading.clock);
    }
    sfRenderWindow_drawSprite(g->window, g->loading.sprite, NULL);
    sfThread_wait(loading);
    sfThread_terminate(loading);
    g->state = PLAY;
}