	.module img
	.optsdcc -mz80

	.area _TEXT

    .globl _fist_tileset
    .globl _fist_palette
    .globl _selection_tileset
    .globl _selection_palette
    .globl _top_hat_tileset
    .globl _top_hat_palette

_fist_tileset:
    .dw _fist_tileset_data
_fist_tileset_data:
    .incbin "img/fist.zts"
_fist_palette:
    .incbin "img/fist.ztp"

_selection_tileset:
    .dw _selection_tileset_data
_selection_tileset_data:
    .incbin "img/selection.zts"
_selection_palette:
    .incbin "img/selection.ztp"

_top_hat_tileset:
    .dw _top_hat_tileset_data
_top_hat_tileset_data:
    .incbin "img/top_hat.zts"
_top_hat_palette:
    .incbin "img/top_hat.ztp"
