/*
** EPITECH PROJECT, 2021
** B-MUL-200-RUN-2-1-myrpg-thomas.techer
** File description:
** textboxes
*/

#ifndef TXTBX_H_
#define TXTBX_H_

#define M_FACTION "\n\n\n\n\n\n\t\t\t\t\t\t\t\tHouse Harkonnen\n\n"         \
"\t\tThe Harkonnens are ruled by the wicked Baron, \n"                       \
"\ta strict loyalty to their Duke and follow him with zeal.\n\n"            \
"\t\t\t\t\t\tAccording to Lady Elara, \n"                                    \
"\t\t\tthe only thing human about the Harkonnen\n"                          \
"\t\t\t  is their genetic makeup, as all humanity\n"                        \
"was abandoned long ago in favor of brutality and maliciousness.\n\n"       \
"\t\t\t\t\tThe Baron's Mentat, Hayt De Vries, \n"                            \
"was born from the flesh of a dead man in the Tleilaxu FleshVats.\n\n\n"    \
" Spell:\n\n"                                                               \
"  Death star: Annihilated an area, do 80 damage to 40 energy.\n"

#include "./rpg.h"

typedef struct textbox_h
{
    sfText *text;
    sfFont *urfont;
    sfRectangleShape *box;
    int state;
    char *ucstr;
    char *tmp;
    char ltr;
} textbox_t;

typedef struct info_text_h
{
    sfText *txt;
    sfFont *font;
    sfVector2f pos;
    sfVector2f scale;

    sfClock *clock;

    int active;
    int speed;
    int dir;
} inf_txt_t;

typedef struct basic_text_s
{
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    sfVector2f scale;
} btext_t;

#endif /* !TXTBX_H_ */
