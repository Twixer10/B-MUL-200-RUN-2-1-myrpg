/*
** EPITECH PROJECT, 2021
** B-MUL-200-RUN-2-1-myrpg-thomas.techer
** File description:
** free_manager
*/

#include "../../include/rpg.h"

void first_free(game_t *g)
{
    sfClock_destroy(g->clock.clock);
    sfSprite_destroy(g->menu.sprite);
    sfMusic_stop(g->music.main_theme);
    sfMusic_destroy(g->music.main_theme);
    sfTexture_destroy(g->textures.menu_background);
    sfRenderWindow_destroy(g->window);
}

void newg_free(game_t *g)
{
    sfText_destroy(g->txt.text);
    free_btn(g->newg.diff, 3);
    sfRectangleShape_destroy(g->txt.box);
    sfRectangleShape_destroy(g->newg.active.scr);
    sfRectangleShape_destroy(g->newg.mage.scr);
    sfRectangleShape_destroy(g->newg.knight.scr);
    sfRectangleShape_destroy(g->newg.ranger.scr);
    sfRectangleShape_destroy(g->newg.berserk.scr);
}

void inventory_free(game_t *g, int nb)
{
    sfSprite_destroy(g->ui.inventory.spr);
    for (int i = 0; i != 26; i++) {
        if (i < nb)
            sfSprite_destroy(g->ui.item[i].spr);
        sfRectangleShape_destroy(g->ui.s_item[i].shape);
    }
}

void free_play(game_t *g)
{
    inventory_free(g, 6);
    sfSprite_destroy(g->player.spr);
    sfTexture_destroy(g->player.tex);
    sfView_destroy(g->vhud);
    sfView_destroy(g->vmap);
}