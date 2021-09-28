/*
** EPITECH PROJECT, 2021
** B-MUL-200-RUN-2-1-myrpg-thomas.techer
** File description:
** menu
*/

#ifndef MENU_H_
#define MENU_H_
#include "./rpg.h"

typedef struct menu_h
{
    sfSprite *sprite;
    sfIntRect rect;
} menu_t;

typedef struct loading_h
{
    sfSprite *sprite;
    sfIntRect rect;
    sfClock *clock;
    sfTime time;
    float seconds;
} load_t;

#endif /* !MENU_H_ */
