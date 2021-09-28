/*
** EPITECH PROJECT, 2021
** B-MUL-200-RUN-2-1-myrpg-thomas.techer
** File description:
** ng_class
*/

#include "../../include/rpg.h"

int is_in_rect(sfRectangleShape *rshape, game_t *g)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(g->window);
    V2F rpos = sfRectangleShape_getPosition(rshape);
    V2F rsize = sfRectangleShape_getSize(rshape);
    V2F sp = sfRectangleShape_getPosition(g->newg.active.scr);
    V2F ss = sfRectangleShape_getSize(g->newg.active.scr);

    if (m.x >= sp.x && m.x <= sp.x + ss.x
        && m.y >= sp.y && m.y <= sp.y + ss.y)
        return 1;
    if (m.x >= rpos.x && m.x <= rpos.x + rsize.x
        && m.y >= rpos.y && m.y <= rpos.y + rsize.y)
        return 2;
    else
        return 0;
}

void check_click(game_t *g)
{
    if (g->newg.mage.state == SELECTED)
        g->player.pclass = MAGE;
    if (g->newg.knight.state == SELECTED)
        g->player.pclass = KNIGHT;
    if (g->newg.ranger.state == SELECTED)
        g->player.pclass = RANGER;
    if (g->newg.berserk.state == SELECTED)
        g->player.pclass = BERSERKER;
    if (g->player.pclass != NO_CLASS)
        g->sub = DIFFICULTY;
}

void show_sel(actscr_t *sel, V2F pos, game_t *g)
{
    if (is_in_rect(sel->scr, g) == 2) {
        g->newg.active.pos = pos;
        g->newg.active.size = (V2F){(1.5 * WWTH/4), WHT};
        sfRectangleShape_setPosition(g->newg.active.scr, g->newg.active.pos);
        sfRectangleShape_setSize(g->newg.active.scr, g->newg.active.size);
        sfRectangleShape_setTexture(g->newg.active.scr, sel->tex, sfTrue);
        sel->state = SELECTED;
    } else if (sel->state == SELECTED && is_in_rect(sel->scr, g) != 1){
        sel->state = NONE;
        sfRectangleShape_setPosition(g->newg.active.scr, g->newg.active.pos);
        sfRectangleShape_setSize(g->newg.active.scr, g->newg.active.size);
    }
}

void is_sel(game_t *g)
{
    if (g->sub == CLASS) {
        if (g->event.type == sfEvtMouseMoved) {
            show_sel(&g->newg.berserk, (V2F){WWTH/4*(3 -0.5), 0}, g);
            show_sel(&g->newg.ranger, (V2F){WWTH/4*2, 0}, g);
            show_sel(&g->newg.knight, (V2F){WWTH/4, 0}, g);
            show_sel(&g->newg.mage, (V2F){0, 0}, g);
        } if (g->event.type == sfEvtMouseButtonPressed) {
            if (sfMouse_isButtonPressed(sfMouseLeft))
                check_click(g);
        }
    }
}

void disp_btn_ng(game_t *g)
{
    annim_btn(g, g->newg.diff, 3);
    sfRenderWindow_drawSprite(g->window, g->newg.diff[EASY].button, NULL);
    sfRenderWindow_drawSprite(g->window, g->newg.diff[NORMAL].button, NULL);
    sfRenderWindow_drawSprite(g->window, g->newg.diff[HEROIC].button, NULL);
}