/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** sokoban
*/

#ifndef SOKOBAN_H_
    #define SOKOBAN_H_

    #include <ncurses.h>

    #define TEXT_MESSAGE "Size of the screen is too small"
    #define K_UP key == KEY_UP
    #define K_DOWN key == KEY_DOWN
    #define K_LEFT key == KEY_LEFT
    #define K_RIGHT key == KEY_RIGHT
    #define BOX(a, b) on_box(*boxes, (*env).player.x + a, (*env).player.y + b)
    #define P(a, b, c) (*env).map[(*env).player.y + a][(*env).player.x + b] == c
    #define BOX2(a, b) on_box(*boxes, env.player.x + a, env.player.y + b) == 0
    #define PLAYER(a, b) env.map[env.player.y + a][env.player.x + b] != '#'
    #define BOX_X(d) ((*boxes)[i]).x == env.player.x + d
    #define BOX_Y(d) ((*boxes)[i]).y == env.player.y + d

typedef struct pos_s {
    int x;
    int y;
} pos_t;

typedef struct env_s {
    pos player;
    int player_moves;
    int map_length;
    int map_width;
    int win;
    int lose;
    char **map;
} env_t;

char **get_map(char *);
pos *setup_boxes(char ***);
pos where_player(char ***);
void print_game(env, pos *);
env manage_event(int, env, pos **);
int error_handling_map(char *);
pos place_player(pos, char ***, int, int);
void move_player(env *, pos **, pos, int);
int detect_win(env, pos *);
int detect_lose(env, pos *);
void print_advert(void);
void print_tutorial(void);
env setup_env(char *);
int setup_windows(char **);
void print_endgame(env , pos *, WINDOW *);
void add_holes(env, pos **, int *, int);

#endif /* !SOKOBAN_H_ */