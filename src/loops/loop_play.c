/*
** EPITECH PROJECT, 2021
** B-MUL-200-RUN-2-1-myrpg-thomas.techer
** File description:
** loop_play
*/

#include "../../include/rpg.h"

void init_play_loop(game_t *g)
{
    init_player(g);
    init_views(g);
    set_life(g);
    init_inventory(g);
    generate_map(g);
    sfRenderWindow_clear(g->window, sfBlack);
    g->state = PLAY;
    return;
}

void disp_play(game_t *g)
{
    g->clock.time = sfClock_getElapsedTime(g->clock.clock);
    g->clock.seconds = g->clock.time.microseconds / 1000000.0;
    resize_view(g);
}

void leave(game_t *g)
{
    dev_inputs(g);
}

void loop_play(game_t *game)
{
    sfRenderWindow_display(game->window);
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtKeyPressed) {
            leave(game);
            edit_view(game);
        }
        if (game->event.type == sfEvtMouseButtonPressed)
            btn_sel(game);
        select_item(game, game->ui.item[0]);
    }
    disp_play(game);
}