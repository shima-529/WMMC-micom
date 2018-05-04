; defined in linker script
.extern _istack
.extern _ustack
.extern _sdata
.extern _sidata
.extern _edata
; defined in source file
.extern _main

.text
.global _start
.type _start, %function
_start:
	mvtc #_istack, isp ; write address
	mvtc #_ustack, usp
	mvtc #_srvectors, intb ; interrupt table register
	; mvtc #100h, fpsw ; unused for RX220

	; clear all RAM area
	mov #0, r1
	mov #0, r2
	mov #_istack, r3
	sstr.b ; memset 0

	; copy .text to ram
	mov #_sdata, r1
	mov #_sidata, r2
	mov #_edata, r3
	sub #_sdata, r3 ; r3 == _edata - _sdata
	smovf

	mov.l #(1 << 16), r1 ; allow interrupts
	or #(1 << 17), r1 ; use USP for stack

	; goto user-mode
	or #(1 << 20), r1
	mvtc r1, bpsw
	mvfc pc, r1
	add #10, r1
	mvtc r1, bpc
	rtfi
ToMain:
	bra _main

InfLoop:
	bra InfLoop
