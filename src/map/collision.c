/*
** EPITECH PROJECT, 2021
** map
** File description:
** add
*/

#include "../../include/rpg.h"

void init_collision(game_t *g)
{
    int fd = open("./assets/map/collision.csv", O_RDONLY);
    char *map = NULL;
    struct stat st;
    g->map.collision = NULL;
    stat("./assets/map/collision.csv", &st);

    map = malloc(sizeof(char) * (st.st_size + 1));
    read(fd, map, st.st_size);
    map[st.st_size] = '\0';
    g->map.collision = my_strtok(remove_chariot(map), ',');
    close(fd);
}

void check_collision(game_t *g, sfVector2f move) {
    if (g->map.collision[(int) move.x][(int)move.y] == '0') {
        g->player.pos = move;
        g->map.collision[(int)move.x][(int) move.y] = 'P';
        g->map.collision[(int) g->player.pos.x][(int) g->player.pos.y] = '0';
    }
    if (g->map.collision[(int)move.x][(int)move.y] == '2')
        g->player.pos = g->player.pos;
    sfSprite_setPosition(g->player.spr, g->player.pos);
}