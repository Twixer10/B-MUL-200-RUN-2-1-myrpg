/*
** EPITECH PROJECT, 2021
** LOOP MENU
** File description:
** INSTANCE OF MENU
*/

#include "../../include/rpg.h"

void display_setting(game_t *game)
{
    sfRenderWindow_display(game->window);
    sfRenderWindow_drawSprite(game->window, game->setting.sprite, NULL);
    display_slider(game);
    sfRenderWindow_drawSprite(game->window, game->buttons[4].button, NULL);
}

void loop_setting(game_t *game)
{
    display_setting(game);
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtKeyPressed)
            if (game->event.key.code == sfKeyQ)
                sfRenderWindow_close(game->window);
        if (game->event.type == sfEvtMouseMoved)
            move_slider(game);
        if (game->event.type == sfEvtMouseButtonPressed) {
            enable_drag(game);
            btn_sel(game);
        }
        if (game->event.type == sfEvtMouseButtonReleased)
            disable_drag(game);
        annim_btn(game, game->buttons, 5);
        update_setting(game);
    }
}