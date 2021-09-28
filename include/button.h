/*
** EPITECH PROJECT, 2021
** BUTTON MANAGER
** File description:
** button
*/

#ifndef BUTTON_H_
#define BUTTON_H_
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum buttons_h
{
    BPLAY,
    BCREDIT,
    BSETTINGS,
    BQUIT,
    BTN_NORMAL,
    BTN_HOVER,
    BPAUSE,
    BCANCEL
} btn_enum_t;

typedef enum difficulty_h
{
    EASY,
    NORMAL,
    HEROIC,
    LEGENDARY
} difficulty_t;

typedef struct button_obj_h
{
    sfSprite *button;
    sfIntRect normal;
    sfIntRect hover;
    sfVector2f pos;
    int upl;
    int upr;
    int dwl;
    int dwr;
} button_obj_t;

typedef struct ui_elem
{
    sfSprite *spr;
    sfIntRect normal;
    sfIntRect hover;
    sfVector2f pos;
    sfVector2f scale;
    sfTexture *tex;
    sfText *txt;
    sfFont *font;
    int upl;
    int upr;
    int dwl;
    int dwr;
    int status;

} gui_elem;

typedef struct ui_inventory_t
{
    sfRectangleShape *shape;
    sfIntRect normal;
    sfIntRect hover;
    sfVector2f pos;
    sfVector2f scale;
    sfTexture *tex;
    sfText *txt;
    sfFont *font;
    int upl;
    int upr;
    int dwl;
    int dwr;
    int status;
} item_ui;

typedef struct gameplay_ui
{
    gui_elem inventory;
    item_ui *s_item;
    gui_elem *item;
    gui_elem mana;
    gui_elem s_mana;
    gui_elem s_life;
    gui_elem life;
}gui;

typedef struct my_slider_h
{
    sfSprite *sprite;
    sfVector2f pos_min;
    sfVector2f pos_max;
    sfVector2f current;
    float value;
    int is_drag;
} slider_t;

#endif /* !BUTTON_H_ */