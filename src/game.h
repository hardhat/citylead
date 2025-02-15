#ifndef GAME_H
#define GAME_H

#include<stdbool.h>
#include<stdint.h>

void init_game(void);
void input_game(uint8_t key, bool down);
void update_game(void);
void draw_game(void);

void init_gameover(void);
void input_gameover(uint8_t key, bool down);
void update_gameover(void);
void draw_gameover(void);

#endif