#include "main.h"
#include "menu.h"

#define TITLE_TILE 0x20
#define MENU_TILE 0x30

void init_menu(void)
{
    set_font(FONT_PITSTOP);
    clear_text_tiles(COL_DARK_BLUE);
    draw_text_opaque(4, 4, " City Leader ", COL_WHITE, COL_BLUE);
    render_text(TITLE_TILE, 7);
    fill_tilemap(TILE_COLOR_WHITE, 0, 0, tilemap_width, tilemap_height);
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
    render_tilemap(0);
}

void input_menu(uint8_t key, bool down)
{
    if(down && key == INPUT_START)
    {
        set_state(GAME_STATE_GAME);
    }
}

void update_menu(void)
{
}

void draw_menu(void)
{
    //
}