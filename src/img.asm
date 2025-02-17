	.module img
	.optsdcc -mz80

	.area _TEXT

    .globl _fist_tileset
    .globl _fist_palette
    .globl _buildings_tileset
    .globl _buildings_palette
    .globl _top_hat_tileset
    .globl _top_hat_palette

_fist_tileset:
    .dw _fist_tileset_data
_fist_tileset_data:
    .incbin "img/fist.zts"
_fist_palette:
    .dw _fist_palette_data
_fist_palette_data:
    .incbin "img/fist.ztp"

_buildings_tileset:
    .dw _buildings_tileset_data
_buildings_tileset_data:
    .incbin "img/buildings.zts"
_buildings_palette:
    .dw _buildings_palette_data
_buildings_palette_data:
    .incbin "img/buildings.ztp"

_top_hat_tileset:
    .dw _top_hat_tileset_data
_top_hat_tileset_data:
    .incbin "img/top_hat.zts"
_top_hat_palette:
    .dw _top_hat_palette_data
_top_hat_palette_data:
    .incbin "img/top_hat.ztp"
