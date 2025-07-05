#include "main.h"
#include "menu.h"
#include "game.h"

#define TITLE_TILE 0x80
#define MENU_TILE 0x90
#define CHOICE_TILE 0xA0

#define MAX_CHOICE_TIMER 4

int choice=0;
int choice_timer=MAX_CHOICE_TIMER;
int choice_color=COL_RED;   // Selected color, which rotates

void init_menu(void)
{
    set_font(FONT_PITSTOP);
    clear_text_tiles(COL_DARK_BLUE);
    draw_text_opaque(4, 4, " City Leader ", COL_WHITE, COL_BLUE);
    render_text(TITLE_TILE, 7);
    //fill_tilemap(TILE_COLOR_WHITE, 0, 0, tilemap_width, tilemap_height);
    for(int j=0;j<15;j++)
    {
        for(int i=0;i<20;i++)
        {
            draw_tilemap(i, j, TILE_COLOR_WHITE+(j%2)*2+(i%2));
        }
    }
    for(int i=0;i<7;i++) {
        draw_tilemap(7+i, 0, TITLE_TILE+i);
    }
    clear_text_tiles(COL_DARK_GREEN);
    set_font(FONT_SPEEDWAY_BOLD);
    draw_text_opaque(4, 4, " Press Start ", COL_WHITE, COL_BLUE);
    render_text(MENU_TILE, 7);
    for(int i=0;i<7;i++) {
        draw_tilemap(7+i, 7, MENU_TILE+i);
    }
    set_font(FONT_SPEEDWAY);
    draw_text(0,0,"Play as Mayor",COL_RED);
    draw_text(0,8,"Play as Mafia",COL_LIGHT_GRAY);
    render_text(CHOICE_TILE, 7);
    for(int i=0;i<7;i++) {
        draw_tilemap(7+i, 9, CHOICE_TILE+i);
    }
    render_tilemap(0);
}

void input_menu(uint8_t key, bool down)
{
    if(down && key == INPUT_START)
    {
        if(choice==0) game.players[0].state=DISTRICT_STATE_MAYOR;
        else game.players[0].state=DISTRICT_STATE_MAFIA;
        set_state(GAME_STATE_GAME);
    }
    if(down && key == INPUT_UP)
    {
        choice--;
        if(choice<0) choice=1;
    }
    if(down && key == INPUT_DOWN)
    {
        choice++;
        if(choice>1) choice=0;
    }
}

void update_menu(void)
{
    choice_timer--;
    if(choice_timer==0)
    {
        choice_timer=MAX_CHOICE_TIMER;
        choice_color=(choice_color==COL_RED)?COL_LIGHT_GRAY:COL_RED;
    }
}

void draw_menu(void)
{
    clear_text_tiles(COL_WHITE);
    set_font(FONT_SPEEDWAY_BOLD);
    draw_text(0,choice==0?0:8,">",COL_RED);
    set_font(choice==0?FONT_SPEEDWAY_BOLD:FONT_SPEEDWAY);
    draw_text(8,0,"Play as Mayor",choice==0?choice_color:COL_DARK_RED);
    set_font(choice==1?FONT_SPEEDWAY_BOLD:FONT_SPEEDWAY);
    draw_text(8,8,"Play as Mafia",choice==1?choice_color:COL_DARK_RED);
    render_text(CHOICE_TILE, 7);
    render_tilemap(0);
}