/*
** EPITECH PROJECT, 2021
** RPG_H_
** File description:
** no desc found
*/

#ifndef RPG_H_
#define RPG_H_
#include "./my.h"
#include "./button.h"
#include "./textboxes.h"
#include "./music.h"
#include "./menu.h"
#include "./new_game.h"
#include "./player.h"
#include "../lib/mxml/mxml.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define IR sfIntRect
#define V2F sfVector2f
#define MV2F(x, y)  (sfVector2f){x, y}
#define XMLFE(a, b, c, d, e , f)    mxmlFindElement(a, b, c, d, e, f)
#define MGPRW(x)    sfMouse_getPositionRenderWindow(x)
#define RDMPC(x, y, z)   sfRenderWindow_mapPixelToCoords(x, y, z)
#define RSSTR(x, y)     sfRectangleShape_setTextureRect(x, y)
#define RSST(x, y)   sfRectangleShape_setTexture(x, y, sfFalse)
#define WHT 1080
#define WWTH 1920
#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

typedef enum game_state_h {
    MENU,
    PLAY,
    EVT_PLAY,
    NEWG,
    EVT_NEWG,
    LOADG,
    EVT_LOADG,
    SETTING,
    EVT_SETTING,
    NEW,
    LOAD
} game_state_t;

typedef enum game_sub_h {
    NAME,
    CLASS,
    DIFFICULTY,
    SUB_NONE,
    INVENTORY
} game_sub_t;

typedef struct clock_manager_h
{
    sfClock *clock;
    sfTime time;
    float seconds;
} my_clock_t;


typedef struct textures_manager_h
{
    sfTexture *menu_background;
    sfTexture *btn_texture;
    sfTexture *inventory;
    sfTexture *slider;
    sfTexture *hud_name;
    sfTexture *setting;
} all_textures_t;

typedef struct layer_s
{
    sfVertexArray *arr;
    sfRenderStates states;
    _Bool visible;
    struct layer_s *next;
} l_t;

typedef struct map_manager_s
{
    l_t *layer;
    sfVector2f size;
    int cols;
    int gid;
    char **collision;
    sfTexture *txtr;
} map_t;

typedef struct game_manager_h
{
    sfRenderWindow *window;
    sfEvent event;
    game_state_t state;
    difficulty_t difficulty;
    game_sub_t sub;
    my_clock_t clock;
    all_textures_t textures;
    menu_t menu;
    newg_t newg;
    music_t music;
    button_obj_t *buttons;
    textbox_t txt;
    inf_txt_t c_txt;
    player_t player;
    gui ui;
    sfView *vhud;
    sfView *vmap;
    map_t map;
    slider_t *sliders;
    menu_t setting;
    menu_t name;
    menu_t ng;
    load_t loading;
} game_t;

void load_assets(game_t *game);
void init_windows(game_t *game);
void update_texture(sfSprite **sprite, sfTexture *texture);
void update_background(game_t *g);
void display_background(game_t *game);
void init_buttons(game_t *game);
void display_menu(game_t *game);
void create_text(sfText *text, char *str, int size, sfFont *font);
void init_music(game_t *g);
void move_rect(sfIntRect *rect, int offset, int max_value);
void init_rshape(actscr_t *selclass, V2F size, V2F pos, char *path);
void btn_init_menu(game_t *g);
void btn_display_menu(game_t *g, int x);
void first_free(game_t *g);
sfFloatRect get_box(sfSprite *sp);
void annim_btn(game_t *game, button_obj_t *buttons, int k);
void init_ngbck(game_t *g);
void init_collision(game_t *g);
void check_collision(game_t *g, sfVector2f move);

//FREE
void inventory_free(game_t *g, int nb);
void free_play(game_t *g);

//  CREDIT
void init_credit(game_t *g);

// VIEW
void init_views(game_t *g);
void resize_view(game_t *g);
void draw_hud(game_t *g);
void edit_view(game_t *g);

// PLAYER
void init_player(game_t *g);
void mv_dir(game_t *g);
void draw_player(game_t *g);

// UI_HUD
void set_life(game_t *g);
void disp_life(game_t *g);
void disp_drain(game_t *g);

// INVENTORY
void disp_inventory(game_t *g, int nb);
void open_inventory(game_t *g);
void init_inventory(game_t *g);
void set_stow(game_t *g, V2F vp);
void select_item(game_t *g, gui_elem item);
//TEXTBOX
void tbox(game_t *g);
void is_box_sel(game_t *g);
//NEWGAME
void init_ng(game_t *g);
void show_sel(actscr_t *sel, V2F pos, game_t *g);
void btn_init_ng(game_t *g);
void is_sel(game_t *g);
void disp_btn_ng(game_t *g);
//BTN
int is_button_sel(game_t *g, button_obj_t *btn, int x);
void free_btn(button_obj_t *btn, int x);
void btn_sel(game_t *g);
slider_t create_slider(int i);
void init_slider(game_t *g);
void display_slider(game_t *g);
void update_setting(game_t *g);
void update_background(game_t *g);
sfFloatRect get_box(sfSprite *sp);
void enable_drag(game_t *game);
void disable_drag(game_t *game);
void move_slider(game_t *game);
button_obj_t new_btn(game_t *g, sfVector2f p, sfIntRect n, sfIntRect h);
//LOOP INTERFACE
void loop_menu(game_t *game);
void loop_credit(game_t *g);
void loop_new_game(game_t *g);
void loop_play(game_t *game);
void loop_map(game_t *game);
void loop_setting(game_t *game);
//PLAY
void init_play_loop(game_t *g);
void init_map_loop(game_t *g);
void loading_screen(game_t *g);
//loading
void wait_loading(game_t *g);
void init_loading(game_t *g);
//DEV
void dev_inputs(game_t *g);
//init
void init_tile_info(mxml_node_t *map, game_t *g);
void generate_map(game_t *g);
//draw
void draw_map(game_t *g);
//get
void get_map(mxml_node_t *map, game_t *g);
sfVertexArray *get_layer(mxml_node_t *layer, game_t *g);
void get_chunk(mxml_node_t *chunk, sfVertexArray *array, game_t *g);
void get_csv(char **data, sfVertexArray *array, sfVector2f pos, game_t *g);
//add
void add_vertex(sfVertexArray *arr, sfVector2f pa, sfVector2f pb, sfVector2f s);
void add_layer(l_t **list, l_t elem);
//free
void clear_layer(l_t **list);
void destroy_map(game_t *g);

#define HELP_MESSAGE "My_RPG: The Simulator of Hiking in the sky !\n" \
    "Usage:\n" \
    "    './my_rpg' to start the game.\n\n" \
    "Description:\n" \
    "    My_RPG: Role Playing Game\n" \
    "    RPG.. What is it ?\n" \
    "    Is a game in which players assume the roles of characters in a" \
    "fictional setting.\n" \
    "    Players take responsibility for acting out" \
    "these roles within a narrative, either through literal acting," \
    "or through a process of structured decision-making regarding" \
    "character development.\n" \
    "    Actions taken within many games succeed or fail according to" \
    " a formal system of rules and guidelines.\n\n" \
    "How to play:\n" \
    "    Write your username, choose your class and the difficulity.\n" \
    "    Fly on our map to discover this world !\n\n" \
    "Some difficulties:\n" \
    "    Many.. many.. many pseudo code to build a nice map..\n"      \
    "    Too many time just for discorver sfVertexArray for particle and map" \
    ", sfThread (loading), sfView, Tiled and libXml/regex (libxml, libxml2," \
    "mxml), a save system.\n\n" \
    "What we have done ?\n" \
    "Setting, Write name, Choose Class, Difficulty, Map, Inventory [i]"  \
    "in play state, take damage [f] and [q] to leave.\n\n" \
    "Enjoy and Be lenient !\n"

#endif /* !RPG_H_ */
