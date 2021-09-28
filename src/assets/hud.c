/*
** EPITECH PROJECT, 2021
** B-MUL-200-RUN-2-1-myrpg-thomas.techer
** File description:
** hud
*/

#include "../../include/rpg.h"

void set_life(game_t *g)
{
    g->ui.life.spr = sfSprite_create();
    sfSprite_setPosition(g->ui.life.spr, (g->ui.life.pos = (V2F){40, 20}));
    sfSprite_setScale(g->ui.life.spr, (g->ui.life.scale = (V2F){4, 4}));
    sfSprite_setTexture(g->ui.life.spr, (g->ui.life.tex =
    sfTexture_createFromFile("./assets/HUD/health_barout.png", NULL)), sfFalse);
    g->ui.s_life.spr = sfSprite_create();
    sfSprite_setPosition(g->ui.s_life.spr, (g->ui.s_life.pos = (V2F){100, 20}));
    sfSprite_setScale(g->ui.s_life.spr, (g->ui.s_life.scale = (V2F){3.9, 3.9}));
    sfSprite_setTexture(g->ui.s_life.spr, (g->ui.s_life.tex =
    sfTexture_createFromFile("./assets/HUD/health_bar.png", NULL)), sfFalse);
    sfSprite_setTextureRect(g->ui.s_life.spr, (IR){0, 0, 50, 30});
    g->player.life = 1000;
}

void disp_drain(game_t *g)
{
    if (sfKeyboard_isKeyPressed(sfKeyF) && g->player.life > 0) {
        int max = g->player.maxlife;
        int pcr = (g->player.life * 100)/max;
        g->player.life -= 10;
        pcr = (pcr * 50)/100;
        if (pcr < 0)
            pcr = 0;
        sfSprite_setTextureRect(g->ui.s_life.spr, (IR){0, 0, pcr, 60});
    }
}

void disp_life(game_t *g)
{
    sfRenderWindow_drawSprite(g->window, g->ui.life.spr, NULL);
    sfRenderWindow_drawSprite(g->window, g->ui.s_life.spr, NULL);
}

void draw_hud(game_t *g)
{
    sfRenderWindow_setView(g->window, g->vhud);
    disp_life(g);
    disp_inventory(g, 6);
}