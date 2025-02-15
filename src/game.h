#ifndef GAME_H
#define GAME_H

#include<stdbool.h>
#include<stdint.h>

enum DISTRICT_STATE
{
    DISTRICT_STATE_EMPTY,
    DISTRICT_STATE_MAFIA,
    DISTRICT_STATE_MAYOR
};

enum DISTRICT_WEALTH
{
    DISTRICT_WEALTH_POOR,
    DISTRICT_WEALTH_MIDDLE,
    DISTRICT_WEALTH_RICH
};

#define DISTRICT_INFLUENCE 3

// Game is a 7x7 grid of districts, tracking pupulation and influence
struct District
{
    enum DISTRICT_STATE state;  // Must have DISTRICT_INFLUENCE influence to claim it for income.
    enum DISTRICT_WEALTH wealth;    // Affects population income
    uint16_t population;
    int16_t influence;  // Negative for mafia don, positive for mayor};
};

struct Player
{
    enum DISTRICT_STATE state;  // Must have DISTRICT_INFLUENCE influence to claim it for income.
    uint16_t money;
    int16_t teritories; // Must have 70% or more of the districts to win.
};

struct Game
{
    struct District districts[7][7];
    struct Player players[2];
    uint8_t turn;
    uint8_t current_player;
};
extern struct Game game;

void init_game(void);
void input_game(uint8_t key, bool down);
void update_game(void);
void draw_game(void);

void init_gameover(void);
void input_gameover(uint8_t key, bool down);
void update_gameover(void);
void draw_gameover(void);

#endif