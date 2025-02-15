#include <stdbool.h>
#include <string.h>

#include "main.h"
#include "game.h"

struct Game game;

int cursor_x=0;
int cursor_y=0;

void init_game(void)
{
    fill_tilemap(TILE_COLOR_BLUE, 0, 0, tilemap_width, tilemap_height);
    render_tilemap(0);
    log("Game started.");

    // Clear all districts and set the player in the top left and bottom right corners.
    for(int x=0;x<7;x++)
    {
        for(int y=0;y<7;y++)
        {
            game.districts[x][y].state = DISTRICT_STATE_EMPTY;
            game.districts[x][y].wealth = DISTRICT_WEALTH_POOR;
            game.districts[x][y].population = 0;
            game.districts[x][y].influence = 0;
        }
    }
    game.players[0].state = DISTRICT_STATE_MAYOR;
    game.players[0].money = 1000;
    game.players[0].teritories = 1;
    game.players[1].state = DISTRICT_STATE_MAFIA;
    game.players[1].money = 1000;
    game.players[1].teritories = 1;
    game.turn = 0;
    game.current_player = 0;
    game.districts[0][0].state = DISTRICT_STATE_MAYOR;
    game.districts[6][6].state = DISTRICT_STATE_MAFIA;
}

void input_game(uint8_t key, bool down)
{
    if(!down) return;
    switch(key) {
        case INPUT_START:
            set_state(GAME_STATE_GAMEOVER);
            break;
        case INPUT_UP:
            cursor_y--;
            if(cursor_y<0) cursor_y=6;
            break;
        case INPUT_DOWN:
            cursor_y++;
            if(cursor_y>6) cursor_y=0;
            break;
        case INPUT_LEFT:
            cursor_x--;
            if(cursor_x<0) cursor_x=6;
            break;
        case INPUT_RIGHT:
            cursor_x++;
            if(cursor_x>6) cursor_x=0;
            break;
        default:
            break;
    }
}

void update_game(void)
{

}

void draw_game(void)
{
    // Draw the districts, with 32x32 blocks (2x2 tiles) for each district.
    for(int x=0;x<7;x++)
    {
        for(int y=0;y<7;y++)
        {
            uint8_t color = TILE_COLOR_WHITE;
            if(game.districts[x][y].state == DISTRICT_STATE_MAYOR) color = TILE_COLOR_GREEN;
            if(game.districts[x][y].state == DISTRICT_STATE_MAFIA) color = TILE_COLOR_RED;
            fill_tilemap(color, x*2, y*2, 2, 2);
        }
    }
    render_tilemap(0);
    // Draw the cursor as 4 sprites.
    reset_sprite();
    add_sprite(cursor_x*32, cursor_y*32, TILE_CURSOR);
    add_sprite(cursor_x*32+16, cursor_y*32, TILE_CURSOR+1);
    add_sprite(cursor_x*32, cursor_y*32+16, TILE_CURSOR+2);
    add_sprite(cursor_x*32+16, cursor_y*32+16, TILE_CURSOR+3);
    render_sprites();

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
