/*
** EPITECH PROJECT, 2021
** B-MUL-200-RUN-2-1-myrpg-thomas.techer
** File description:
** button_manager
*/

#include "../../include/rpg.h"

button_obj_t new_btn(game_t *g, sfVector2f p, sfIntRect n, sfIntRect h)
{
    button_obj_t btn;

    btn.button = sfSprite_create();
    sfSprite_setTexture(btn.button, g->textures.btn_texture, TRUE);
    btn.pos = p;
    btn.normal = n;
    btn.hover = h;
    sfSprite_setTextureRect(btn.button, btn.normal);
    sfSprite_move(btn.button, btn.pos);
    btn.upl = p.x;
    btn.upr = p.x + n.width;
    btn.dwl = p.y;
    btn.dwr = p.y + n.height;
    return (btn);
}

void btn_init_menu(game_t *g)
{
    g->buttons = malloc(sizeof(button_obj_t) * 6);
    g->buttons[0] = new_btn(g, (V2F){WWTH/2-440, WHT/2 - 80},
    (IR) {0, 69*3, 220, 69}, (IR) {220, 69*3, 220, 69});
    g->buttons[1] = new_btn(g, (V2F){WWTH/2-440, WHT/2},
    (IR) {0, 69*4, 220, 69}, (IR) {220, 69*4, 220, 69});
    g->buttons[2] = new_btn(g, (V2F){WWTH/2-440, WHT/2 + 80},
    (IR) {0, 69, 220, 69}, (IR) {220, 69, 220, 69});
    g->buttons[3] = new_btn(g, (V2F){WWTH/2-440, WHT/2 + 160},
    (IR) {0, 69*2, 220, 69}, (IR) {220, 69*2, 220, 69});
    g->buttons[4] = new_btn(g, MV2F(WWTH/2-110, WHT-150),
                            (IR) {0, 0, 220, 69}, (IR) {220, 0, 220, 69});
    g->buttons[5] = new_btn(g, MV2F(WWTH/2-110, WHT/2+75),
                            (IR) {0, 564+69, 220, 69},
                            (IR) {220, 564+69, 220, 69});
}

void btn_init_ng(game_t *g)
{
    g->newg.diff = malloc(sizeof(button_obj_t) * 3);

    g->newg.diff[0] = new_btn(g, (V2F){WWTH/2-110, WHT/2 - 80},
    (IR) {0, 69*5, 220, 69}, (IR) {220, 69*5, 220, 73});

    g->newg.diff[1] = new_btn(g, (V2F){WWTH/2-110, WHT/2},
    (IR) {0, (69*5 + 73), 220, 69}, (IR) {220, (69*5) + 73, 220, 73});

    g->newg.diff[2] = new_btn(g, (V2F){WWTH/2-110, WHT/2  + 80},
    (IR) {0, (69*5) + 146, 220, 69}, (IR) {220, (69*5) + 146, 220, 73});

}

void btn_display_menu(game_t *g, int x)
{
    for (int i = 0; i != x; i++)
        sfRenderWindow_drawSprite(g->window, g->buttons[i].button, NULL);
}

void free_btn(button_obj_t *btn, int x)
{
    for (int i = 0; i != x; i++)
        sfSprite_destroy(btn[i].button);
}