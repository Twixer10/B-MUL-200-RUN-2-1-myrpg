/*
** EPITECH PROJECT, 2021
** B-MUL-200-RUN-2-1-myrpg-thomas.techer
** File description:
** music_manager
*/

#include "../../include/rpg.h"

void init_music(game_t *g)
{
    g->music.main_theme = sfMusic_createFromFile(
        "./assets/music/main_theme.ogg");
}