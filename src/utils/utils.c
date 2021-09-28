/*
** EPITECH PROJECT, 2021
** B-MUL-200-RUN-2-1-mydefender-thomas.techer
** File description:
** utils
*/

#include "../../include/rpg.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left == max_value)
        rect->left = 0;
}

void dev_inputs(game_t *g)
{
    if (g->event.key.code == sfKeyM && g->state != MENU)
        g->state = MENU;
    if (g->event.key.code == sfKeyQ)
        sfRenderWindow_close(g->window);
    if (g->event.key.code == sfKeyQ)
        sfRenderWindow_close(g->window);
    if (g->event.key.code == sfKeyEnter && g->state == NEWG)
        g->sub = CLASS;
    if (g->state == PLAY) {
        open_inventory(g);
        disp_drain(g);
    }
}

void init_rshape(actscr_t *selclass, V2F size, V2F pos, char *path)
{
    selclass->scr = sfRectangleShape_create();
    selclass->pos = pos;
    selclass->size = size;
    sfRectangleShape_setPosition(selclass->scr, selclass->pos);
    sfRectangleShape_setSize(selclass->scr, selclass->size);
    selclass->tex = sfTexture_createFromFile(path, NULL);
    sfRectangleShape_setTexture(selclass->scr, selclass->tex, sfFalse);
}

int is_button_sel(game_t *g, button_obj_t *btn, int x)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(g->window);

    for (int i = 0; i != x; i++) {
        if (m.x >= btn[i].upl && m.x <= btn[i].upr
            && m.y >= btn[i].dwl && m.y <= btn[i].dwr)
            return i;
    }
    return -1;
}