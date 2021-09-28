/*
** EPITECH PROJECT, 2021
** B-MUL-200-RUN-2-1-myrpg-thomas.techer
** File description:
** slide_manager
*/

#include "../../include/rpg.h"

slider_t create_slider(int i)
{
    slider_t ss;

    ss.sprite = sfSprite_create();
    ss.value = 100.00;
    ss.pos_min = (V2F) {620, 420 + (i * 200)};
    ss.pos_max = (V2F) {720 + (500), 420 + (i * 220)};
    ss.current = (V2F) {720 + (500), 420 + (i * 220)};
    ss.is_drag = 0;
    sfSprite_setOrigin(ss.sprite, (sfVector2f) {25, 26});
    return (ss);
}

void init_setting(game_t *g)
{
    sfTexture *txt = sfTexture_createFromFile("assets/menu/settin.jpg", NULL);
    g->setting.sprite = sfSprite_create();
    sfSprite_setTexture(g->setting.sprite, txt, 0);
}

void init_slider(game_t *g)
{
    init_setting(g);
    g->state = SETTING;
}

void display_slider(game_t *g)
{
    sfRenderWindow_drawSprite(g->window, g->sliders[0].sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->sliders[1].sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->sliders[2].sprite, NULL);
}

void update_setting(game_t *g)
{
    sfMusic_setVolume(g->music.main_theme, g->sliders[0].value);
    sfRenderWindow_setFramerateLimit(g->window, (int) g->sliders[2].value);
}