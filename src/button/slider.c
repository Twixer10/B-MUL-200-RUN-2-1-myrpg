/*
** EPITECH PROJECT, 2021
** LOOP MENU
** File description:
** INSTANCE OF MENU
*/

#include "../../include/rpg.h"

sfFloatRect get_box(sfSprite *sp)
{
    sfFloatRect rect =  sfSprite_getGlobalBounds(sp);
    return (rect);
}

void enable_drag(game_t *game)
{
    sfFloatRect rect;

    for (int i = 0; i <= 2; i++) {
        rect = get_box(game->sliders[i].sprite);
        if ((int) rect.left <= game->event.mouseButton.x &&
            (int) rect.left + (int) rect.width >= game->event.mouseButton.x &&
            (int) rect.top <= game->event.mouseButton.y &&
            (int) rect.top + (int) rect.height >= game->event.mouseButton.y) {
            game->sliders[i].is_drag = 1;
        } else {
            game->sliders[i].is_drag = 0;
        }
    }
}

void disable_drag(game_t *game)
{
    for (int i = 0; i <= 2; i++) {
        game->sliders[i].is_drag = 0;
        game->sliders[i].value = (((int)game->sliders[i].current.x -
                game->sliders[i].pos_min.x) * 100) /(game->sliders[i].pos_max.x
                        - game->sliders[i].pos_min.x);
    }
}

void move_slider(game_t *game)
{
    for (int i = 0; i <= 2; i++) {
        if (game->sliders[i].is_drag == 1) {
            if (game->event.mouseMove.x >= game->sliders[i].pos_min.x &&
                game->event.mouseMove.x <= game->sliders[i].pos_max.x) {
                game->sliders[i].current.x = game->event.mouseMove.x;
                sfSprite_setPosition(game->sliders[i].sprite,
                                     game->sliders[i].current);
            }
        }
    }
}