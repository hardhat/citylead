#include <stdbool.h>
#include <string.h>

#include "main.h"
#include "game.h"

struct Game game;

void init_game(void)
{
    fill_tilemap(TILE_COLOR_RED, 0, 0, tilemap_width, tilemap_height);
    render_tilemap(0);
    log("Game started.");
}

void input_game(uint8_t key, bool down)
{
    if(down && key == INPUT_START)
    {
        set_state(GAME_STATE_GAMEOVER);
    }
}

void update_game(void)
{
}

void draw_game(void)
{
    const char *giant_go[8] = {
        "  ######   #######  ",
        " ##    ## ##     ## ",
        " ##       ##     ## ",
        " ##       ##     ## ",
        " ##  #### ##     ## ",
        " ##    ## ##     ## ",
        "  ######   #######  ",
        "                                             "
    };
    int width=strlen(giant_go[0]);
    for(int x=0;x<width;x++)
    {
        for(int y=0;y<8;y++)
        {
            draw_tilemap(x, y, giant_go[y][x]==32?TILE_COLOR_BLACK:TILE_COLOR_WHITE);
        }
    }
    render_tilemap(0);
}

void init_gameover(void)
{
    fill_tilemap(TILE_COLOR_GREEN, 0, 0, tilemap_width, tilemap_height);
    render_tilemap(0);
    log("Game over.");
}

void input_gameover(uint8_t key, bool down)
{
    if(down && key == INPUT_START)
    {
        set_state(GAME_STATE_MENU);
    }
}

void update_gameover(void)
{
}

void draw_gameover(void)
{
    //
}
