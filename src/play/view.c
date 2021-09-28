/*
** EPITECH PROJECT, 2021
** B-MUL-200-RUN-2-1-myrpg-thomas.techer
** File description:
** view
*/

#include "../../include/rpg.h"

void init_views(game_t *g)
{
    g->vhud = sfView_create();
    g->vmap = sfView_create();
    sfView_setSize(g->vmap, MV2F(1920, 1080));
    sfView_zoom(g->vmap, 0.3);
}

void edit_view(game_t *g)
{
    if (g->event.key.code == sfKeyUp) {
        g->player.pos = MV2F(g->player.pos.x, g->player.pos.y-16);
        sfSprite_setPosition(g->player.spr, g->player.pos);
        sfView_move(g->vmap, g->player.pos);
    } if (g->event.key.code == sfKeyDown) {
        g->player.pos = MV2F(g->player.pos.x, g->player.pos.y + 16);
        sfSprite_setPosition(g->player.spr, g->player.pos);
        sfView_move(g->vmap, g->player.pos);
    } if (g->event.key.code == sfKeyLeft) {
        g->player.pos = MV2F(g->player.pos.x-16, g->player.pos.y);
        sfSprite_setPosition(g->player.spr, g->player.pos);
        sfView_move(g->vmap, g->player.pos);
    } if (g->event.key.code == sfKeyRight) {
        g->player.pos = MV2F(g->player.pos.x + 16, g->player.pos.y);
        sfSprite_setPosition(g->player.spr, g->player.pos);
        sfView_move(g->vmap, g->player.pos);
    }
}

void resize_view(game_t *g)
{
    sfView_setCenter(g->vmap, g->player.pos);
    sfRenderWindow_setView(g->window, g->vmap);
    sfRenderWindow_clear(g->window, sfBlack);
    draw_map(g);
    draw_player(g);
    draw_hud(g);
}