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
    TILE_COLOR_WHITE = 1, // 1-4 are white
    TILE_COLOR_RED = 5, // 5-8 are red
    TILE_COLOR_GREEN = 9, // 9-12 are green
    TILE_COLOR_BLUE = 13,
    TILE_CURSOR = 14,    // This is 4 tiles in a 2x2 square
};

#define PAL_RED 32  // index for red palette
#define PAL_GREEN 48    // index for green palette
#define PAL_WHITE 64 // index for white palette

enum FONT_FACE
{
    FONT_PITSTOP,
    FONT_SPEEDWAY,
    FONT_SPEEDWAY_BOLD,
};

extern uint8_t tilemap_width;
extern uint8_t tilemap_height;

/// @brief Set the game state for the game main loop.
/// @param  state the game state to set.
void set_state(enum GAME_STATE state);

/// @brief immediately sets a palette color.
/// @param index palette entry to set, 0-255.
/// @param r red component of the color, 0-255.
/// @param g green component of the color, 0-255.
/// @param b blue component of the color, 0-255.
/// @note The color is converted to 565 format (5 bits red, 6 bits green, 5 bits blue).
void set_palette_rgb(uint8_t index, uint8_t r, uint8_t g, uint8_t b);
/// @brief immediately sets a palette color.
/// @param index palette entry to set, 0-255.
/// @param color 565 color value to set the palette entry to.
void set_palette(uint8_t index, uint16_t color);
/// @brief File a tile in the tileset with a specific color.
/// @param tile the tile id from 0-255 to fill with the color.
/// @param color the palette index to fill the tile with, 0-255.
void fill_tileset(uint8_t tile, uint8_t color);
/// @brief draws a tile on on the off screen layer at the specified position.
/// @param x offset from the top left corner in tiles, 0-79 for the 16x16 tile.
/// @param y offset from the top left corner in tiles, 0-15 for the 16x16 tile.
/// @param tile the tile id from the tileset to draw, which must be in the tileset.
void draw_tilemap(uint16_t x, uint8_t y, uint8_t tile);
/// @brief Draws an array of tiles on the off screen tilemap at the specified position.
/// @param x top left position of the layer 
/// @param y top left position of the layer
/// @param tile pointer to an array of tile ids from the tileset to draw, which must be in the tileset.
/// @param count number of tiles to draw in the array, which must be less than or equal to 80.
void draw_tilemap_array(uint16_t x, uint8_t y, uint8_t *tile, uint8_t count);
/// @brief Fills a rectangular area of the off screen tilemap with a specific tile.
/// @param tile tile id from the tileset to fill the area with.
/// @param x position in tiles 0-79 for the 16x16 tile.
/// @param y position in tiles 0-15 for the 16x16 tile.
/// @param w tile count across (1-80)
/// @param h tile count down (1-16)
void fill_tilemap(uint8_t tile,uint16_t x, uint8_t y, uint8_t w, uint8_t h);
/// @brief  Renders the tilemap for a specific layer.
/// @param layer layer to render, 0 for the first layer, 1 for the second layer, etc.
/// @note The tilemap is rendered in a single pass, so it should be called after
void render_tilemap(uint8_t layer);
/// @brief Clear the off screen sprite buffer to be rendered later.  Fully zeros the buffer, and sets the current count to 0.
void reset_sprite(void);
/// @brief Adds a sprite to the sprite buffer to be rendered later.
/// @param x pixel position - 16 of the sprite, anchored to the top left corner.
/// @param y pixel position - 16 of the sprite, anchored to the top left corner.
/// @param sprite tile number of the sprite to render, which must be in the tileset.
/// @note all sprites are 16x16 pixels and the position is the top left corner of the sprite.
void add_sprite(uint16_t x, uint8_t y, uint8_t sprite);
/// @brief Renders all sprites in the sprite buffer to the screen.
void render_sprites(void);
/// @brief Clears all sprites by resetting the sprites, the rendering the empty sprites
void clear_sprites(void);

#define MAX_TEXT_TILES 16
/// @brief Set the offscreen text tiles to a specific color.
/// @note Each text tile is 16x16 pixels.  And there are 16 of them.  The fonts are 8x8, so 2x2 tiles.
/// @param color palette index for the text tiles.
void clear_text_tiles(uint8_t color);
/// @brief Set the font to be used for text rendering
void set_font(enum FONT_FACE font);
/// @brief Draw a single pixel in the offscreen text tilemap.
/// @param x horizontal values 0-255 with clipping, with 0 being the left.
/// @param y vertical values 0-15, with 0 being the top.
/// @param color palette index for the pixel.
void draw_text_pixel(uint16_t x, uint8_t y, uint8_t color);
/// @brief Draw a character in the offscreen text tilemap.
/// @param x horizontal values 0-255 with clipping, with 0 being the left.
/// @param y vertical values 0-15, with 0 being the top.
/// @param c character to draw, which must be in the font.
/// @param color palette index for the character.
void draw_text(uint16_t x, uint8_t y, const char *text, uint8_t color);
/// @brief Draw a character in the offscreen text tilemap with a background color.
/// @param x horizontal values 0-255 with clipping, with 0 being the left.
/// @param y vertical values 0-15, with 0 being the top.
/// @param c character to draw, which must be in the font.
/// @param fg palette index for the character.
/// @param bg palette index for the background.
void draw_text_opaque(uint16_t x, uint8_t y, const char *text, uint8_t fg, uint8_t bg);
/// @brief Renders the text tiles to the screen from the offscreen buffer.
/// @param tile tile id to start rendering from, which must be in the tileset.
/// @param tile_count number of tiles to render, which must be less than or equal to 16.
void render_text(uint8_t tile, uint8_t tile_count);

/// @brief Log to the serial port.
/// @param message the message to log.
void log(const char *message);
/// @brief Log to the serial port with a format string.
/// @param format the format string to use.
/// @param ... the arguments to the format string.
void logf(const char *format, ...);

#endif
