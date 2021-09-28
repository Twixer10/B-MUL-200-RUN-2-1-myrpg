/*
** EPITECH PROJECT, 2021
** B-MUL-200-RUN-2-1-myrpg-thomas.techer
** File description:
** new game
*/

#include "../../include/rpg.h"

void sub_sel(game_t *g)
{
    init_rshape(&g->newg.mage, (V2F){WWTH/4, WHT}, (V2F){0, 0}, SEL_M);
    init_rshape(&g->newg.knight, (V2F){WWTH/4, WHT}, (V2F){WWTH/4, 0}, SEL_K);
    init_rshape(&g->newg.ranger, (V2F){WWTH/4, WHT}, (V2F){WWTH/4*2, 0}, SEL_R);
    init_rshape(&g->newg.berserk, (V2F){WWTH/4, WHT},
                                    (V2F){WWTH/4*3, 0}, SEL_B);
    init_rshape(&g->newg.active, (V2F){WWTH/4, WHT}, (V2F){0, 0}, SEL_M);
}

void ngset_state(game_t *g)
{
    g->txt.state = NONE;
    g->sub = NAME;
    g->player.pclass = NO_CLASS;
    g->newg.knight.state = NONE;
    g->newg.mage.state = NONE;
    g->newg.ranger.state = NONE;
    g->newg.berserk.state = NONE;
    g->txt.ucstr = NULL;
    g->txt.ltr = '_';
    g->player.tex = NULL;
}

void init_ng(game_t *g)
{
    ngset_state(g);
    init_ngbck(g);
    g->txt.text = sfText_create();
    g->txt.ucstr = malloc(sizeof(char) * 15);
    g->txt.ucstr[0] = '_';
    sfText_setFont(g->txt.text,
        (g->txt.urfont = sfFont_createFromFile("assets/font/Dune2k.ttf")));
    g->txt.box = sfRectangleShape_create();
    sfRectangleShape_setPosition(g->txt.box, (V2F){WWTH/2 - 200, WHT/2});
    sfRectangleShape_setSize(g->txt.box, (V2F){400, 60});
    sfRectangleShape_setFillColor(g->txt.box, sfBlack);
    sfRectangleShape_setOutlineColor(g->txt.box, sfBlack);
    sfRectangleShape_setOutlineThickness(g->txt.box, 1.2);
    sub_sel(g);
    btn_init_ng(g);
    g->state = NEWG;
}

void disp_ng(game_t *g)
{
    if (g->sub == NAME) {
        sfRenderWindow_drawSprite(g->window, g->ng.sprite, 0);
        sfRenderWindow_drawRectangleShape(g->window, g->txt.box, NULL);
        if (g->txt.ucstr[0] != '\0')
            sfRenderWindow_drawText(g->window, g->txt.text, NULL);
        sfRenderWindow_drawSprite(g->window, g->buttons[5].button, NULL);
    } if (g->sub == CLASS) {
        sfRenderWindow_drawRectangleShape(g->window, g->newg.mage.scr, NULL);
        sfRenderWindow_drawRectangleShape(g->window, g->newg.knight.scr, NULL);
        sfRenderWindow_drawRectangleShape(g->window, g->newg.ranger.scr, NULL);
        sfRenderWindow_drawRectangleShape(g->window, g->newg.berserk.scr, NULL);
        sfRenderWindow_drawRectangleShape(g->window, g->newg.active.scr, NULL);
    } if (g->sub == DIFFICULTY)
        disp_btn_ng(g);
}

void loop_new_game(game_t *g)
{
    update_background(g);
    while (sfRenderWindow_pollEvent(g->window, &g->event)) {
        if (g->txt.state == SELECTED && g->sub == NAME
            && g->event.type == sfEvtTextEntered)
            tbox(g);
        if (g->event.type == sfEvtKeyPressed && g->txt.state != SELECTED)
            dev_inputs(g);
        if (sfMouse_isButtonPressed(sfMouseLeft) == TRUE) {
            is_box_sel(g);
            btn_sel(g);
        }
        annim_btn(g, g->buttons, 6);
        is_sel(g);
    }
    disp_ng(g);
}