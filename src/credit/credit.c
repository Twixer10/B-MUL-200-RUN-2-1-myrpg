/*
** EPITECH PROJECT, 2021
** B-MUL-200-RUN-2-1-myrpg-thomas.techer
** File description:
** credit
*/

#include "../../include/rpg.h"

void init_credit (game_t *g)
{
    g->c_txt.pos = (V2F){WWTH/3, WHT/4};
    g->c_txt.scale = (V2F){1, 1};
    g->c_txt.speed = 2;
    g->c_txt.active = 1;
    g->c_txt.clock = sfClock_create();
    g->c_txt.txt = sfText_create();
    g->c_txt.font = sfFont_createFromFile("assets/font/Dune2k.ttf");
    sfText_setFont(g->c_txt.txt, g->c_txt.font);
    sfText_setString(g->c_txt.txt, M_FACTION);
    sfText_setPosition(g->c_txt.txt, g->c_txt.pos);
    sfText_setScale(g->c_txt.txt, g->c_txt.scale);
}

void mv_txt(inf_txt_t *txt, int x, int y)
{
    txt->pos.x += (txt->speed * x);
    txt->pos.y += (txt->speed * y);
    sfText_setPosition(txt->txt, txt->pos);
}

void disp_credit(game_t *g)
{
    float seconds = 0;
    sfTime time = sfClock_getElapsedTime(g->c_txt.clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds >= 0.005) {
        mv_txt(&g->c_txt, 0, -1);
        sfClock_restart(g->c_txt.clock);
    }
    sfRenderWindow_drawText(g->window, g->c_txt.txt, NULL);
}

void destroy_credits(game_t *g)
{
    sfText_destroy(g->c_txt.txt);
    sfClock_destroy(g->c_txt.clock);
}

void loop_credit(game_t *g)
{
    update_background(g);
    while (sfRenderWindow_pollEvent(g->window, &g->event)) {
        if (g->event.type == sfEvtKeyPressed) {
            destroy_credits(g);
            dev_inputs(g);
            return;
        }
    }
    disp_credit(g);
}