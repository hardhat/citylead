// Speedway font from https://damieng.com/zx-origins
#ifndef SPEEDWAY_H_
#define SPEEDWAY_H_

#include <stdint.h>

static const uint8_t FONT_SPEEDWAY_BITMAP[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //   
	0x08, 0x08, 0x10, 0x10, 0x00, 0x20, 0x20, 0x00, // ! 
	0x24, 0x24, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, // " 
	0x00, 0x14, 0x7e, 0x28, 0xfc, 0x50, 0x00, 0x00, // # 
	0x08, 0x1e, 0x20, 0x3c, 0x04, 0x78, 0x20, 0x00, // $ 
	0x60, 0xa4, 0xc8, 0x10, 0x26, 0x4a, 0x0c, 0x00, // % 
	0x30, 0x48, 0x50, 0x72, 0x8c, 0x84, 0x7a, 0x00, // & 
	0x10, 0x10, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, // ' 
	0x08, 0x10, 0x20, 0x20, 0x20, 0x10, 0x08, 0x00, // ( 
	0x20, 0x10, 0x08, 0x08, 0x08, 0x10, 0x20, 0x00, // ) 
	0x00, 0x08, 0x08, 0x7e, 0x18, 0x24, 0x00, 0x00, // * 
	0x00, 0x08, 0x08, 0x7e, 0x10, 0x10, 0x00, 0x00, // + 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x20, // , 
	0x00, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x00, // - 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x00, // . 
	0x04, 0x04, 0x08, 0x08, 0x10, 0x10, 0x20, 0x00, // / 
	0x3c, 0x46, 0x4a, 0x92, 0xa4, 0xc4, 0x78, 0x00, // 0 
	0x08, 0x18, 0x08, 0x08, 0x10, 0x10, 0x10, 0x00, // 1 
	0x3c, 0x42, 0x04, 0x18, 0x60, 0x80, 0xfc, 0x00, // 2 
	0x3c, 0x42, 0x02, 0x1c, 0x04, 0x84, 0x78, 0x00, // 3 
	0x10, 0x22, 0x24, 0x44, 0x3e, 0x08, 0x08, 0x00, // 4 
	0x3e, 0x40, 0x40, 0x7c, 0x04, 0x84, 0x78, 0x00, // 5 
	0x3c, 0x40, 0x40, 0x7c, 0x84, 0x84, 0x78, 0x00, // 6 
	0x7e, 0x02, 0x04, 0x04, 0x08, 0x08, 0x10, 0x00, // 7 
	0x3c, 0x42, 0x42, 0x7c, 0x84, 0x84, 0x78, 0x00, // 8 
	0x3c, 0x42, 0x42, 0x7c, 0x04, 0x04, 0x78, 0x00, // 9 
	0x00, 0x00, 0x08, 0x08, 0x00, 0x10, 0x10, 0x00, // : 
	0x00, 0x00, 0x08, 0x08, 0x00, 0x10, 0x10, 0x20, // ; 
	0x00, 0x08, 0x10, 0x20, 0x10, 0x08, 0x00, 0x00, // < 
	0x00, 0x00, 0x7c, 0x00, 0x7c, 0x00, 0x00, 0x00, // = 
	0x00, 0x10, 0x08, 0x04, 0x08, 0x10, 0x00, 0x00, // > 
	0x3c, 0x42, 0x02, 0x0c, 0x00, 0x10, 0x10, 0x00, // ? 
	0x3c, 0x42, 0x4a, 0x54, 0x9c, 0x80, 0x78, 0x00, // @ 
	0x1c, 0x22, 0x42, 0x42, 0xfc, 0x84, 0x84, 0x00, // A 
	0x7c, 0x42, 0x42, 0x7c, 0x84, 0x84, 0xf8, 0x00, // B 
	0x3c, 0x42, 0x42, 0x40, 0x84, 0x84, 0x78, 0x00, // C 
	0x7c, 0x42, 0x42, 0x42, 0x84, 0x84, 0xf8, 0x00, // D 
	0x7e, 0x40, 0x40, 0x78, 0x80, 0x80, 0xfc, 0x00, // E 
	0x7e, 0x40, 0x40, 0x78, 0x80, 0x80, 0x80, 0x00, // F 
	0x3e, 0x40, 0x40, 0x4e, 0x84, 0x84, 0x78, 0x00, // G 
	0x42, 0x42, 0x42, 0x7c, 0x84, 0x84, 0x84, 0x00, // H 
	0x0c, 0x08, 0x08, 0x08, 0x10, 0x10, 0x30, 0x00, // I 
	0x02, 0x02, 0x02, 0x04, 0x04, 0x04, 0x78, 0x00, // J 
	0x42, 0x44, 0x48, 0x70, 0x88, 0x84, 0x82, 0x00, // K 
	0x30, 0x20, 0x20, 0x20, 0x40, 0x40, 0x7e, 0x00, // L 
	0x7e, 0x49, 0x49, 0x49, 0x92, 0x92, 0x92, 0x00, // M 
	0x7c, 0x42, 0x42, 0x42, 0x84, 0x84, 0x84, 0x00, // N 
	0x3c, 0x42, 0x42, 0x44, 0x84, 0x84, 0x78, 0x00, // O 
	0x7c, 0x42, 0x42, 0x5c, 0x80, 0x80, 0x80, 0x00, // P 
	0x3c, 0x42, 0x42, 0x8a, 0x84, 0x84, 0x7a, 0x00, // Q 
	0x7c, 0x42, 0x42, 0x5c, 0x90, 0x88, 0x86, 0x00, // R 
	0x3e, 0x40, 0x40, 0x38, 0x04, 0x04, 0xf8, 0x00, // S 
	0x7f, 0x08, 0x08, 0x10, 0x10, 0x20, 0x20, 0x00, // T 
	0x42, 0x42, 0x42, 0x84, 0x84, 0x84, 0x78, 0x00, // U 
	0x42, 0x42, 0x44, 0x44, 0x48, 0x50, 0x60, 0x00, // V 
	0x49, 0x49, 0x49, 0x92, 0x92, 0x92, 0x7e, 0x00, // W 
	0x42, 0x44, 0x28, 0x10, 0x28, 0x44, 0x84, 0x00, // X 
	0x42, 0x42, 0x24, 0x14, 0x08, 0x10, 0x20, 0x00, // Y 
	0x7c, 0x04, 0x08, 0x10, 0x20, 0x40, 0xfc, 0x00, // Z 
	0x1e, 0x10, 0x10, 0x10, 0x20, 0x20, 0x3c, 0x00, // [ 
	0x20, 0x20, 0x10, 0x10, 0x08, 0x08, 0x04, 0x00, // \ (backslash) 
	0x3c, 0x04, 0x04, 0x08, 0x08, 0x08, 0x78, 0x00, // ] 
	0x10, 0x38, 0x6c, 0xc6, 0x00, 0x00, 0x00, 0x00, // ^ 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, // _ 
	0x3c, 0x42, 0x40, 0x78, 0x80, 0x80, 0xfc, 0x00, // £ 
	0x00, 0x00, 0x3e, 0x02, 0x3c, 0x44, 0x7c, 0x00, // a 
	0x10, 0x20, 0x3e, 0x22, 0x44, 0x44, 0x7c, 0x00, // b 
	0x00, 0x00, 0x3e, 0x22, 0x20, 0x44, 0x7c, 0x00, // c 
	0x01, 0x02, 0x3e, 0x22, 0x44, 0x44, 0x7c, 0x00, // d 
	0x00, 0x00, 0x3e, 0x22, 0x3c, 0x40, 0x7c, 0x00, // e 
	0x0e, 0x08, 0x3c, 0x10, 0x20, 0x20, 0x60, 0x00, // f 
	0x00, 0x00, 0x3e, 0x42, 0x44, 0x7c, 0x08, 0xf8, // g 
	0x10, 0x20, 0x3e, 0x22, 0x44, 0x44, 0x44, 0x00, // h 
	0x08, 0x00, 0x10, 0x10, 0x20, 0x20, 0x20, 0x00, // i 
	0x02, 0x00, 0x04, 0x04, 0x08, 0x08, 0x08, 0x70, // j 
	0x20, 0x22, 0x24, 0x38, 0x44, 0x42, 0x42, 0x00, // k 
	0x18, 0x08, 0x10, 0x10, 0x10, 0x20, 0x20, 0x00, // l 
	0x00, 0x00, 0x7e, 0x49, 0x49, 0x92, 0x92, 0x00, // m 
	0x00, 0x00, 0x3c, 0x22, 0x22, 0x44, 0x44, 0x00, // n 
	0x00, 0x00, 0x3e, 0x22, 0x22, 0x44, 0x7c, 0x00, // o 
	0x00, 0x00, 0x3e, 0x22, 0x22, 0x7c, 0x40, 0x40, // p 
	0x00, 0x00, 0x3e, 0x42, 0x44, 0x7c, 0x08, 0x08, // q 
	0x00, 0x00, 0x3e, 0x22, 0x20, 0x40, 0x40, 0x00, // r 
	0x00, 0x00, 0x1e, 0x20, 0x3c, 0x04, 0x78, 0x00, // s 
	0x08, 0x08, 0x3c, 0x10, 0x20, 0x20, 0x3c, 0x00, // t 
	0x00, 0x00, 0x22, 0x22, 0x22, 0x44, 0x7c, 0x00, // u 
	0x00, 0x00, 0x22, 0x22, 0x24, 0x28, 0x30, 0x00, // v 
	0x00, 0x00, 0x49, 0x49, 0x92, 0x92, 0x7e, 0x00, // w 
	0x00, 0x00, 0x22, 0x24, 0x18, 0x24, 0x44, 0x00, // x 
	0x00, 0x00, 0x22, 0x42, 0x44, 0x7c, 0x08, 0xf8, // y 
	0x00, 0x00, 0x3e, 0x04, 0x18, 0x20, 0x7c, 0x00, // z 
	0x1c, 0x10, 0x20, 0x40, 0x20, 0x20, 0x38, 0x00, // { 
	0x08, 0x08, 0x10, 0x10, 0x20, 0x20, 0x20, 0x00, // | 
	0x1c, 0x04, 0x04, 0x02, 0x04, 0x08, 0x38, 0x00, // } 
	0x34, 0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ~ 
	0x1e, 0x21, 0x5d, 0xa5, 0xa1, 0xba, 0x84, 0x78, // © 
};

#endif
