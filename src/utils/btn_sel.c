/*
** EPITECH PROJECT, 2021
** B-MUL-200-RUN-2-1-myrpg-thomas.techer
** File description:
** btn_sel
*/

#include "../../include/rpg.h"

void sel_menu(game_t *g)
{
    int x = is_button_sel(g, g->buttons, 6);

    if (x == 0)
        g->state = EVT_NEWG;
    if (x == 1)
        g->state = EVT_NEWG;
    if (x == 2)
        g->state = EVT_SETTING;
    if (x == 3)
        sfRenderWindow_close(g->window);
    if (x == 4)
        g->state = MENU;
    if (x == 5)
        g->sub = CLASS;
}

void sel_newg(game_t *g)
{
    int x = is_button_sel(g, g->newg.diff, 3);

    if (g->sub == DIFFICULTY) {
        if (x == 0 )
            g->difficulty = EASY;
        if (x == 1 )
            g->difficulty = NORMAL;
        if (x == 2 )
            g->difficulty = HEROIC;
        if ((x == 0) | (x == 1) | (x == 2))
            g->state = EVT_PLAY;
    }
}

void btn_sel(game_t *g)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (g->state == MENU || g->state == SETTING || (g->state == NEWG &&
        g->sub == NAME))
            sel_menu(g);
        if (g->state == NEWG)
            sel_newg(g);
    }
}