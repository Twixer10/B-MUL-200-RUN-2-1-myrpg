/*
** EPITECH PROJECT, 2021
** B-MUL-200-RUN-2-1-myrpg-thomas.techer
** File description:
** player
*/

#include "../../include/rpg.h"

void set_ptex(game_t *g)
{
    if (g->player.pclass == BERSERKER)
        g->player.tex = sfTexture_createFromFile
            ("assets/hero/KNIGHT/fem_elf/basic.png", NULL);
    if (g->player.pclass == MAGE)
        g->player.tex = sfTexture_createFromFile
            ("assets/hero/KNIGHT/fem_elf/basic.png", NULL);
    else {
        if (g->player.pclass == RANGER)
            g->player.tex = sfTexture_createFromFile
                ("assets/hero/KNIGHT/fem_elf/basic.png", NULL);
        if (g->player.pclass == KNIGHT)
            g->player.tex = sfTexture_createFromFile
                ("assets/hero/KNIGHT/fem_elf/basic.png", NULL);
    }
}

void init_player(game_t *g)
{
    g->player.spr = sfSprite_create();
    g->player.p_dir = STOP;
    g->player.t_anim = MOVE;
    g->player.maxlife = 1000;
    g->player.life = 1000;
    set_ptex(g);
    sfSprite_setPosition(g->player.spr, (g->player.pos = (V2F){-1648, -900}));
    sfSprite_setScale(g->player.spr, (g->player.scale = (V2F){0.6, 0.6}));
    sfSprite_setTexture(g->player.spr, g->player.tex, sfFalse);
    sfSprite_setTextureRect(g->player.spr, (IR){0, 0, 32, 32});
}

void mv_dir(game_t *g)
{
    if (g->event.type == sfEvtKeyPressed) {
        if (g->event.key.code == sfKeyUp && g->player.pos.y > 1)
            g->player.pos.y -= 16;
        if (g->event.key.code == sfKeyDown && g->player.pos.y < WHT - 32)
            g->player.pos.y += 16;
        if (g->event.key.code == sfKeyLeft && g->player.pos.x > 1)
            g->player.pos.x -= 16;
        if (g->event.key.code == sfKeyRight && g->player.pos.x < WWTH - 32)
            g->player.pos.x += 16;
    } sfSprite_setPosition(g->player.spr, g->player.pos);
    sfView_move(g->vmap, g->player.pos);
}

void draw_player(game_t *g)
{
    sfRenderWindow_drawSprite(g->window, g->player.spr, NULL);
}