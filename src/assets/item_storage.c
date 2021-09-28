/*
** EPITECH PROJECT, 2021
** B-MUL-200-RUN-2-1-mydefender-thomas.techer
** File description:
** display_buttons
*/

#include "../../include/rpg.h"

void set_stow(game_t *g, V2F vp)
{
    int x = 146;
    int y = 202;
    int k = 54;
    g->ui.s_item = malloc(sizeof(item_ui) * 26);
    for (int i = 0; i != 26; i++) {
        g->ui.s_item[i].shape = sfRectangleShape_create();
        g->ui.s_item[i].tex = NULL;
        sfRectangleShape_setPosition(g->ui.s_item[i].shape,
            (g->ui.s_item[24].pos = (V2F){vp.x + x, vp.y - y}));
        x += (k + 9);
        if (x >= 350) {
            x = 146;
            y -= 102;
        }
        sfRectangleShape_setSize(g->ui.s_item[i].shape, (V2F){k, k+30});
    }
    sfRectangleShape_setPosition(g->ui.s_item[24].shape,
        (g->ui.s_item[24].pos = (V2F){vp.x -208, vp.y - 170}));
    sfRectangleShape_setSize(g->ui.s_item[24].shape, (V2F){160, 180});
}

void man_org_item(game_t *g, gui_elem item)
{
    for (int i = 0; i != 24; i++) {
        sfVector2i vmp = sfMouse_getPositionRenderWindow(g->window);
        V2F mp = sfRenderWindow_mapPixelToCoords(g->window, vmp, g->vhud);
        sfFloatRect r = sfRectangleShape_getLocalBounds(g->ui.s_item[i].shape);
        V2F ps = sfRectangleShape_getScale(g->ui.s_item[i].shape);
        V2F p = sfRectangleShape_getPosition(g->ui.s_item[i].shape);
        if (mp.x >= p.x && mp.x <= p.x
        + (r.width * ps.x) && mp.y >= p.y && mp.y <= p.y + (r.height * ps.y)) {
            item.pos = p;
            g->ui.s_item[24].tex = NULL;
            item.status = NONE;
            break;
        }
    }
    sfSprite_setPosition(item.spr, item.pos);
}

void select_item(game_t *g, gui_elem item)
{
    V2F mp = RDMPC(g->window, MGPRW(g->window), g->vhud);
    sfFloatRect r = sfSprite_getLocalBounds(item.spr);
    V2F ps = sfSprite_getScale(item.spr);
    V2F p = sfSprite_getPosition(item.spr);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (mp.x >= p.x && mp.x <= p.x + (r.width * ps.x) && mp.y >= p.y &&
        mp.y <= p.y + (r.height * ps.y)) {
            RSSTR(g->ui.s_item[24].shape, item.normal);
            RSST(g->ui.s_item[24].shape, (g->ui.s_item[24].tex = item.tex));
            item.status = SELECTED;
        }
    } if (g->event.type == sfEvtMouseButtonReleased
        && g->event.mouseButton.button == sfMouseLeft) {
        man_org_item(g, item);
        return;
    } else if (item.status == SELECTED) {
        item.pos.x = mp.x - (r.width*1.2);
        item.pos.y = mp.y - (r.height*1.2);
        sfSprite_setPosition(item.spr, item.pos);
    }
}