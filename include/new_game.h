/*
** EPITECH PROJECT, 2021
** B-MUL-200-RUN-2-1-myrpg-thomas.techer
** File description:
** new_game
*/

#ifndef NEW_GAME_H_
#define NEW_GAME_H_
#include "./rpg.h"

#define SEL_M "assets/HUD/class_sel/mage.jpg"
#define SEL_K "assets/HUD/class_sel/knightwolf.jpg"
#define SEL_R "assets/HUD/class_sel/fantasy-archer.jpg"
#define SEL_B "assets/HUD/class_sel/presminos.jpg"

typedef enum state_e {
    NONE,
    SELECTED
} state_t;

typedef struct actscr_screen_h {
    sfRectangleShape *scr;
    sfTexture *tex;
    sfVector2f pos;
    sfVector2f size;
    state_t state;
} actscr_t;

typedef struct new_game_h {
    actscr_t mage;
    actscr_t knight;
    actscr_t ranger;
    actscr_t berserk;
    actscr_t active;
    button_obj_t *diff;
} newg_t;

#endif /* !NEW_GAME_H_ */