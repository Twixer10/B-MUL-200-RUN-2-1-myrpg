/*
** EPITECH PROJECT, 2021
** B-MUL-200-RUN-2-1-myrpg-thomas.techer
** File description:
** textbox
*/

#include "../../include/rpg.h"

void is_box_sel(game_t *g)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(g->window);
    sfFloatRect I = sfRectangleShape_getGlobalBounds(g->txt.box);
    if (g->sub == NAME && m.x < I.width + WWTH/2 - 200 && m.x > WWTH/2 - 200
        && m.y < I.height + WHT/2 && m.y > WHT/2) {
        g->txt.state = SELECTED;
        sfText_setColor(g->txt.text, sfBlack);
        sfRectangleShape_setFillColor(g->txt.box, sfWhite);
    } else if (g->sub == NAME || m.x > I.width + WWTH/2 - 200
        || m.x < WWTH/2 - 200 || m.y > I.height + WHT/2 || m.y < WHT/2
            || g->event.text.unicode == ESCAPE_KEY) {
        g->txt.state = NONE;
        sfText_setColor(g->txt.text, sfWhite);
        sfRectangleShape_setFillColor(g->txt.box, sfBlack);
    }
}

void text_ent(game_t *g, char *tmp)
{
    if (g->event.text.unicode < 128) {
        g->txt.ltr = g->event.text.unicode;
        for (int i = 0; tmp[i] != '\0'; i++) {
            if (g->event.text.unicode == DELETE_KEY
                && tmp[i] == '_' && i > 0 && i < 14 + 1) {
                tmp[i-1] = '_';
                tmp[i] = ' ';
                break;
            } if (tmp[i] == '_'  && i < 14 && i >= 0
                  && g->event.text.unicode != DELETE_KEY) {
                if (g->event.text.unicode == ESCAPE_KEY)
                    is_box_sel(g);
                else {
                    tmp[i] = g->txt.ltr;
                    tmp[i+1] = '_';
                } break;
            }
        }
    }
}

char *text_entered(game_t *g)
{
    char *tmp = g->txt.ucstr;

    text_ent(g, tmp);
    return (g->txt.ucstr = tmp);
}

void tbox(game_t *g)
{
    if (g->txt.ucstr  == NULL)
        g->txt.ucstr[0] = '_';
    sfText_setPosition(g->txt.text, (V2F){WWTH/2 - 160, WHT/2});
    sfText_setScale(g->txt.text, (V2F) {1, 1});
    text_entered(g);
    if (g->txt.ucstr != NULL)
        sfText_setString(g->txt.text, g->txt.ucstr);
    g->player.name = g->txt.ucstr;
}
