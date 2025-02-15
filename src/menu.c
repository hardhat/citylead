#include "main.h"
#include "menu.h"

void init_menu(void)
{
    clear_text_tiles(COL_DARK_BLUE);
    draw_text_opaque(4, 4, " City Leader ", COL_WHITE, COL_BLUE);
    render_text(32, 7);
    fill_tilemap(TILE_COLOR_WHITE, 0, 0, tilemap_width, tilemap_height);
    for(int i=0;i<7;i++) {
        draw_tilemap(7+i, 0, 32+i);
    }
    clear_text_tiles(COL_DARK_GREEN);
    draw_text_opaque(4, 4, " Press Start ", COL_WHITE, COL_BLUE);
    render_text(40, 7);
    for(int i=0;i<7;i++) {
        draw_tilemap(7+i, 7, 40+i);
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