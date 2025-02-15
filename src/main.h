#ifndef MAIN_H
#define MAIN_H

#include<stdint.h>

enum GAME_STATE
{
    GAME_STATE_MENU,
    GAME_STATE_GAME,
    GAME_STATE_GAMEOVER
};

enum INPUT
{
    INPUT_UP,
    INPUT_DOWN,
    INPUT_LEFT,
    INPUT_RIGHT,
    INPUT_A,
    INPUT_B,
    INPUT_X,
    INPUT_Y,
    INPUT_START,
    INPUT_SELECT,
    INPUT_L,
    INPUT_R,
    MAX_INPUT
};

enum {
    COL_BLACK         = 0x0,
    COL_DARK_BLUE     = 0x1,
    COL_DARK_GREEN    = 0x2,
    COL_DARK_CYAN     = 0x3,
    COL_DARK_RED      = 0x4,
    COL_DARK_MAGENTA  = 0x5,
    COL_BROWN         = 0x6,
    COL_LIGHT_GRAY    = 0x7,
    COL_DARK_GRAY     = 0x8,
    COL_BLUE          = 0x9,
    COL_GREEN         = 0xa,
    COL_CYAN          = 0xb,
    COL_RED           = 0xc,
    COL_MAGENTA       = 0xd,
    COL_YELLOW        = 0xe,
    COL_WHITE         = 0xf,
};

enum TILE_COLORS
{
    TILE_COLOR_BLACK = 0,
    TILE_COLOR_WHITE = 1,
    TILE_COLOR_RED = 2,
    TILE_COLOR_GREEN = 3,
    TILE_COLOR_BLUE = 4,
    TILE_CURSOR = 5,    // This is 4 tiles in a 2x2 square
};

enum FONT_FACE
{
    FONT_PITSTOP,
    FONT_SPEEDWAY,
    FONT_SPEEDWAY_BOLD,
};

extern uint8_t tilemap_width;
extern uint8_t tilemap_height;

void set_state(enum GAME_STATE state);

void set_palette_rgb(uint8_t index, uint8_t r, uint8_t g, uint8_t b);
void set_palette(uint8_t index, uint16_t color);
void fill_tileset(uint8_t tile, uint8_t color);
void draw_tilemap(uint16_t x, uint8_t y, uint8_t tile);
void draw_tilemap_array(uint16_t x, uint8_t y, uint8_t *tile, uint8_t count);
void fill_tilemap(uint8_t tile,uint16_t x, uint8_t y, uint8_t w, uint8_t h);
void render_tilemap(uint8_t layer);
void reset_sprite(void);
void add_sprite(uint16_t x, uint8_t y, uint8_t sprite);
void render_sprites(void);

#define MAX_TEXT_TILES 16
void clear_text_tiles(uint8_t color);
void set_font(enum FONT_FACE font);
void draw_text_pixel(uint16_t x, uint8_t y, uint8_t color);
void draw_text(uint16_t x, uint8_t y, const char *text, uint8_t color);
void draw_text_opaque(uint16_t x, uint8_t y, const char *text, uint8_t fg, uint8_t bg);
void render_text(uint8_t tile, uint8_t tile_count);

void log(const char *message);
void logf(const char *format, ...);

#endif
