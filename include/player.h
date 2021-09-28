/*
** EPITECH PROJECT, 2021
** B-MUL-200-RUN-2-1-myrpg-thomas.techer
** File description:
** player
*/

#ifndef PLAYER_H_
#define PLAYER_H_
#include "./rpg.h"

typedef enum player_class_e {
    NO_CLASS,
    RANGER,
    MAGE,
    KNIGHT,
    BERSERKER
} pclass_t;

typedef enum direction_e {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    STOP
} dir_t;

typedef enum animation_e {
    ATTACK,
    MOVE,
    DAMAGE,
    JUMP
}anim_t;

typedef struct player_h {
    pclass_t pclass;
    anim_t t_anim;
    dir_t p_dir;
    int state;
    int sub;
    int life;
    int maxlife;
    char *name;

    sfVector2f pos;
    sfVector2f scale;
    sfTexture *tex;
    sfSprite *spr;

} player_t;

#endif /* !PLAYER_H_ */
