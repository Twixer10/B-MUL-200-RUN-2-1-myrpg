/*
** EPITECH PROJECT, 2021
** LOOP MENU
** File description:
** INSTANCE OF MENU
*/

#include "../../include/rpg.h"

void update_background(game_t *g)
{
    sfRenderWindow_display(g->window);
    g->clock.time = sfClock_getElapsedTime(g->clock.clock);
    g->clock.seconds = g->clock.time.microseconds / 1000000.0;
    if (g->clock.seconds > 0.23) {
        move_rect(&g->menu.rect, 329, 1316);
        sfClock_restart(g->clock.clock);
    }
    sfSprite_setTextureRect(g->menu.sprite, g->menu.rect);
    sfRenderWindow_drawSprite(g->window, g->menu.sprite, NULL);
}

void annim_btn(game_t *game, button_obj_t *buttons, int k)
{
    for (int i = 0; i < k; i++) {
        if (game->event.mouseMove.x >= buttons[i].upl &&
            game->event.mouseMove.x <= buttons[i].upr &&
            game->event.mouseMove.y >= buttons[i].dwl &&
            game->event.mouseMove.y <= buttons[i].dwr) {
                sfSprite_setTextureRect(buttons[i].button,
                buttons[i].hover);
        } else {
            sfSprite_setTextureRect(buttons[i].button,
            buttons[i].normal);
        }
    }
}

void loop_menu(game_t *game)
{
    update_background(game);
    btn_display_menu(game, 4);
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtKeyPressed)
            dev_inputs(game);
        if (game->event.type == sfEvtMouseButtonPressed)
            btn_sel(game);
        annim_btn(game, game->buttons, 4);
    }
}