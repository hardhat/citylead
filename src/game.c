
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "main.h"
#include "game.h"

struct Game game;

int cursor_x=0;
int cursor_y=0;
bool held[MAX_INPUT];

void init_game(void)
{
    fill_tilemap(TILE_COLOR_BLUE, 0, 0, tilemap_width, tilemap_height);
    render_tilemap(0);
    log("Game started.");
    set_font(FONT_PITSTOP);

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
    game.districts[0][0].population = 100;
    game.districts[0][0].wealth = DISTRICT_WEALTH_RICH;
    game.districts[0][0].influence = DISTRICT_INFLUENCE;
    game.districts[6][6].state = DISTRICT_STATE_MAFIA;
    game.districts[6][6].population = 100;
    game.districts[6][6].wealth = DISTRICT_WEALTH_RICH;
    game.districts[6][6].influence = -DISTRICT_INFLUENCE;
}

void input_game(uint8_t key, bool down)
{
    held[key] = down;
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
    static int timer=0;
    int held_count=0;
    for(int i=0;i<MAX_INPUT;i++)
        if(held[i]) held_count++;
    if(held_count>1) timer=6; // Only allow one key at a time.

    if(timer==0) {
        // Draw the districts, with 32x32 blocks (2x2 tiles) for each district.
        for(int x=0;x<7;x++)
        {
            for(int y=0;y<7;y++)
            {
                uint8_t color = TILE_COLOR_WHITE;
                if(game.districts[x][y].state == DISTRICT_STATE_MAYOR) color = TILE_COLOR_GREEN;
                if(game.districts[x][y].state == DISTRICT_STATE_MAFIA) color = TILE_COLOR_RED;
                if(color==TILE_COLOR_WHITE) {
                    //fill_tilemap(color, x*2, y*2, 2, 2);
                    draw_tilemap(x*2, y*2, color);
                    draw_tilemap(x*2+1, y*2, color+1);
                    draw_tilemap(x*2, y*2+1, color+2);
                    draw_tilemap(x*2+1, y*2+1, color+3);
                } else {
                    for(int i=0;i<2;i++)
                        for(int j=0;j<2;j++)
                            draw_tilemap(x*2+i, y*2+j, color+i+j*2);
                }
            }
        }
        render_tilemap(0);

        // Show the stats for the current tile under the cursor, on the right.
        char buffer[64];
        struct District *district = &game.districts[cursor_x][cursor_y];
        sprintf(buffer, "District %d,%d", cursor_x, cursor_y);
        clear_text_tiles(COL_DARK_BLUE);
        draw_text(1, 0, buffer, COL_YELLOW);
        sprintf(buffer, "State: %s", district->state==DISTRICT_STATE_EMPTY?"Empty":district->state==DISTRICT_STATE_MAYOR?"Mayor":"Mafia");
        draw_text(1, 8, buffer, COL_WHITE);
        render_text(0x80, 6);
        for(int i=0;i<6;i++)
            draw_tilemap(14+i, 0, 0x80+i);
        clear_text_tiles(COL_DARK_BLUE);
        sprintf(buffer, "$$$: %s", district->wealth==DISTRICT_WEALTH_POOR?"Poor":district->wealth==DISTRICT_WEALTH_MIDDLE?"Middle":"Rich");
        draw_text(1, 0, buffer, COL_WHITE);
        sprintf(buffer, "Pop: %d", district->population);
        draw_text(1, 8, buffer, COL_WHITE);
        render_text(0x86, 6);
        for(int i=0;i<6;i++)
            draw_tilemap(14+i, 1, 0x86+i);
        clear_text_tiles(COL_DARK_BLUE);
        sprintf(buffer, "Inf: %d", district->influence);
        draw_text(1, 0, buffer, COL_WHITE);
        sprintf(buffer, "Turn: %d", game.turn);
        draw_text(1, 8, buffer, COL_WHITE);
        render_text(0x8c, 6);
        for(int i=0;i<6;i++)
            draw_tilemap(14+i, 2, 0x8c+i);

        // Draw player stats at the bottom.
        clear_text_tiles(COL_DARK_BLUE);
        sprintf(buffer, "Player %s", game.current_player==0?"Mayor":"Mafia");
        draw_text(1, 0, buffer, COL_YELLOW);
        sprintf(buffer, "$$$: %d", game.players[game.current_player].money);
        draw_text(1, 8, buffer, COL_WHITE);
        render_text(0x92, 6);
        for(int i=0;i<6;i++)
            draw_tilemap(14+i, 4, 0x92+i);
        clear_text_tiles(COL_DARK_BLUE);
        sprintf(buffer, "Terr: %d", game.players[game.current_player].teritories);
        draw_text(1, 0, buffer, COL_WHITE);
        sprintf(buffer, "Turn: %d", game.turn);
        draw_text(1, 8, buffer, COL_WHITE);
        render_text(0x98, 6);
        for(int i=0;i<6;i++)
            draw_tilemap(14+i, 5, 0x98+i);

        timer=30;
    } else {
        timer--;
    }           
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
    for(int j=0;j<15;j++)
    {
        for(int i=0;i<20;i++)
        {
            draw_tilemap(i, j, TILE_COLOR_WHITE+(j%2)*2+(i%2));
        }
    }
    char buffer[64];
    clear_text_tiles(COL_DARK_RED);
    sprintf(buffer, "Game over.");
    draw_text(4, 4, buffer, COL_RED);
    render_text(0x80, 7);
    for(int i=0;i<6;i++)
        draw_tilemap(7+i, 6, 0x80+i);
    render_tilemap(0);
    clear_sprites();
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
