#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>

#include<zos_sys.h>
#include<zos_keyboard.h>
#include<zos_vfs.h>
#include<zos_video.h>
#include<zvb_hardware.h>
#include<zvb_gfx.h>
#include<zvb_sprite.h>
#include<zvb_sound.h>

#include "Pitstop.h"
#include "Speedway.h"
#include "Speedway Bold.h"

#include "main.h"
#include "menu.h"
#include "game.h"

enum GAME_STATE game_state = GAME_STATE_MENU;

gfx_context ctx;

bool pressed = true;
bool quit = false;

int sprite_count=0;
gfx_sprite sprites[128];

// The drawing surface is 16 tiles with 16x16 pixels each
uint8_t text_tiles[256*16];
uint8_t *font = FONT_PITSTOP_BITMAP;

uint8_t tilemap0[20*15];
uint8_t tilemap1[20*15];
uint8_t tilemap_width=20;
uint8_t tilemap_height=15;

zos_dev_t ser;

void log(const char *message)
{
    size_t size=strlen(message);

    write(ser, message, &size);
    size=2;
    write(ser, "\r\n", &size);
}

void logf(const char *format, ...)
{
    char buffer[256];
    va_list args;
    va_start(args, format);
    vsprintf(buffer, format, args);
    va_end(args);
    log(buffer);
}

void set_state(enum GAME_STATE state)
{

    switch(state)
    {
        case GAME_STATE_MENU:
            init_menu();
            break;
        case GAME_STATE_GAME:
            init_game();
            break;
        case GAME_STATE_GAMEOVER:
            init_gameover();
            break;
    }
    logf("Setting state to %d.", state);
    game_state = state;
}

uint8_t handle_input(uint8_t key)
{
    switch(key)
    {
        case KB_ESC:
        case KB_KEY_Q:
            quit = true;
            return 0;
        case KB_KEY_W:
        case KB_UP_ARROW:
            return INPUT_UP;
        case KB_KEY_S:
        case KB_DOWN_ARROW:
            return INPUT_DOWN;
        case KB_KEY_A:
        case KB_LEFT_ARROW:
            return INPUT_LEFT;
        case KB_KEY_D:
        case KB_RIGHT_ARROW:
            return INPUT_RIGHT;
        case KB_KEY_V:
        case KB_KEY_SPACE:
            return INPUT_A;
        case KB_KEY_BACKSPACE:
        case KB_KEY_B:
            return INPUT_B;
        case KB_KEY_COMMA:
        case KB_KEY_X:
            return INPUT_X;
        case KB_KEY_PERIOD:
        case KB_KEY_Y:
            return INPUT_Y;
        case KB_KEY_ENTER:
        case KB_KEY_E:
            return INPUT_START;
        case KB_KEY_TAB:
            return INPUT_SELECT;
        case KB_KEY_LEFT_BRACKET:
        case KB_KEY_L:
            return INPUT_L;
        case KB_KEY_RIGHT_BRACKET:
        case KB_KEY_R:
            return INPUT_R;
        default:
            return 0;
    }
}

void init(void)
{
    gfx_initialize(ZVB_CTRL_VID_MODE_GFX_320_8BIT, &ctx);
    zvb_sound_initialize(1);
    gfx_tileset_add_color_tile(&ctx, 0, TEXT_COLOR_BLACK);
    gfx_tileset_add_color_tile(&ctx, 1, TEXT_COLOR_WHITE);
    gfx_tileset_add_color_tile(&ctx, 2, TEXT_COLOR_RED);
    gfx_tileset_add_color_tile(&ctx, 3, TEXT_COLOR_GREEN);
    gfx_tileset_add_color_tile(&ctx, 4, TEXT_COLOR_BLUE);

    ser = open("#SER0",O_WRONLY);
    if (ser < 0) {
        printf("Failed to open serial port\n");
	exit(1);
    }
    /* Initialize the keyboard by setting it to raw and non-blocking */
    void* arg = (void*) (KB_READ_NON_BLOCK | KB_MODE_RAW);
    ioctl(DEV_STDIN, KB_CMD_SET_MODE, arg);

    log("Initialized.");
}

void set_palette(uint8_t index, uint16_t color)
{
    gfx_palette_load(&ctx, &color, 1, index);
}

void set_palette_rgb(uint8_t index, uint8_t r, uint8_t g, uint8_t b)
{
    uint16_t color = RGB888_TO_RGB565(r, g, b);
    gfx_palette_load(&ctx, &color, 1, index);
}

void fill_tileset(uint8_t tile, uint8_t color)
{
    gfx_tileset_add_color_tile(&ctx, tile, color);
}

void clear_text_tiles(uint8_t color)
{
    memset(text_tiles, color, sizeof(text_tiles));
}

void set_font(enum FONT_FACE face)
{
    switch(face)
    {
        case FONT_PITSTOP:
            font = FONT_PITSTOP_BITMAP;
            break;
        case FONT_SPEEDWAY:
            font = FONT_SPEEDWAY_BITMAP;
            break;
        case FONT_SPEEDWAY_BOLD:
            font = FONT_SPEEDWAY_BOLD_BITMAP;
            break;
    }
}

void draw_text_pixel(uint16_t x, uint8_t y,uint8_t color)
{
    int offset = (x/16)*256+y*16+(x%16);
    if(offset<0 || offset>=256*16) return;  // Clip
    text_tiles[offset] = color;
}

void draw_text_char(uint16_t x, uint8_t y, uint8_t c, uint8_t color)
{
    for(uint8_t i=0;i<8;i++)
    {
        uint8_t mask = 1<<(7-i);
        for(uint8_t j=0;j<8;j++)
        {
            if(font[(c-32)*8+j] & (1<<(7-j)))
                draw_text_pixel(x+i, y+j, color);
        }
    }
}

void draw_text(uint16_t x, uint8_t y, const char *text, uint8_t color)
{
    for(int i=0;i<strlen(text);i++)
    {
        uint8_t c = text[i];
        if(c<32 || c>127) c=32;
        draw_text_char(x+i*8, y, c, color);
    }
}

void draw_text_opaque(uint16_t x, uint8_t y, const char *text, uint8_t fg, uint8_t bg)
{
    for(int i=0;i<strlen(text);i++)
    {
        uint8_t c = text[i];
        if(c<32 || c>127) c=32;
        for(int j=0;j<8;j++)
        {
            for(int k=0;k<8;k++)
            {
                uint8_t mask = 1<<(7-k);
                if(font[(c-32)*8+j] & mask)
                    draw_text_pixel(x+i*8+k, y+j, fg);
                else
                    draw_text_pixel(x+i*8+k, y+j, bg);
            }
        }
    }
}

void render_text(uint8_t tile, uint8_t tile_count)
{
    uint16_t from = tile*256;
    gfx_tileset_options options = {0,from,0,0};
    gfx_tileset_load(&ctx, text_tiles, tile_count*256, &options);
}

void draw_tilemap(uint16_t x, uint8_t y, uint8_t tile)
{
    tilemap0[y*tilemap_width+x] = tile;}

void draw_tilemap_array(uint16_t x, uint8_t y, uint8_t *tile, uint8_t count)
{
    for(int i=0;i<count;i++)
    {
        tilemap0[y*tilemap_width+x+i] = tile[i];
    }
}

void fill_tilemap(uint8_t tile,uint16_t x, uint8_t y, uint8_t w, uint8_t h)
{
    for(int i=0;i<w;i++)
    {
        for(int j=0;j<h;j++)
        {
            tilemap0[(y+j)*tilemap_width+x+i] = tile;
        }
    }
}

void render_tilemap(uint8_t layer)
{
    for(int y=0;y<tilemap_height;y++)
    {
        gfx_tilemap_load(&ctx, tilemap0+y*tilemap_width, tilemap_width, layer, 0, y);
    }
}

void reset_sprite(void)
{
    sprite_count=0;
    memset(sprites, 0, sizeof(sprites));
}

void add_sprite(uint16_t x, uint8_t y, uint8_t sprite)
{
    if(sprite_count >= 128) return;
    sprites[sprite_count].x = x;
    sprites[sprite_count].y = y;
    sprites[sprite_count].tile = sprite;
    sprites[sprite_count].flags = 0;
    sprite_count++;
}

void render_sprites(void)
{
    gfx_sprite_render_array(&ctx, 0, sprites, sprite_count);
}

void process_input(void)
{
    unsigned char keys[32];
    int size;

    do {
        size=32;
        read(DEV_STDIN, &keys, &size);
        for(int i=0;i<size;i++) {
            char key = keys[i];
           logf("Processing input key %02x.", key);
           if(key == KB_RELEASED) {
                pressed = false;
            } else {
                uint8_t input = handle_input(key);
                switch(game_state)
                {
                    case GAME_STATE_MENU:
                        input_menu(input, pressed);
                        break;
                    case GAME_STATE_GAME:
                        input_game(input, pressed);
                        break;
                    case GAME_STATE_GAMEOVER:
                        input_gameover(input, pressed);
                        break;
                }

                pressed=true;
            }
        }
    } while(size>0);
}

int main(void)
{
    init();

    fill_tilemap(TILE_COLOR_BLACK, 0, 0, tilemap_width, tilemap_height);
    render_tilemap(0);
    render_tilemap(1);
    set_state(GAME_STATE_MENU);

    while(!quit)
    {
        process_input();

        gfx_wait_end_vblank(&ctx);
        switch(game_state)
        {
            case GAME_STATE_MENU:
                update_menu();
                break;
            case GAME_STATE_GAME:
                update_game();
                break;
            case GAME_STATE_GAMEOVER:
                update_gameover();
                break;
        }
        gfx_wait_vblank(&ctx);
        switch(game_state) {
            case GAME_STATE_MENU:
                draw_menu();
                break;
            case GAME_STATE_GAME:
                draw_game();
                break;
            case GAME_STATE_GAMEOVER:
                draw_gameover();
                break;
        }
    }
    log("Quitting.");

    zvb_sound_reset();
    ioctl(DEV_STDOUT, CMD_RESET_SCREEN, NULL);
    printf("Exiting...\n");

    printf("Goodbye!\n");
    close(ser);

    exit(0);

    return 0;
}
