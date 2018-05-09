# PORT4
.equ PORT4_PDR, 0x0008C004
.equ PORT4_PODR, 0x0008C024

# CMT
.equ CMT_CMSTR0, 0x00088000
.equ CMT0_CMCR, 0x00088002
.equ CMT0_CMCNT, 0x00088004
.equ CMT0_CMCOR, 0x00088006

# SYSTEM
.equ SYSTEM_SCKCR3, 0x00080026
.equ SYSTEM_MOSCCR, 0x00080032
.equ SYSTEM_HOCOCR, 0x00080036
.equ SYSTEM_HOCOCR, 0x00080037
.equ SYSTEM_HOCOWTCR2, 0x000800A9
.equ SYSTEM_PRCR, 0x000803FE
.equ SYSTEM_MSTPCRA, 0x00080010

# ICU
.equ VECTNUM_CMT0_CMI0, 28
.equ IPRNUM_CMT0_CMI0, 4
.equ IERNUM_CMT0_CMI0, 0x03
.equ ICU_CMT0_IR, (0x00087000 + VECTNUM_CMT0_CMI0)
.equ ICU_CMT0_CMI0_IPR, (0x00087300 + IPRNUM_CMT0_CMI0)
.equ ICU_CMT0_CMI0_IER, (0x00087200 + IERNUM_CMT0_CMI0)

.text
.global _main
.type _main, %function
_main:
	bsr clock_init
	mov.l #PORT4_PDR, r1
	mov.l #1, r2
	mov.b r2, [r1]

loop:
	mov.l #1000, r3
	bsr ms_wait
	bsr blink
	bra loop

.type blink, %function
blink:
	mov.l #PORT4_PODR, r1
	mov.b [r1], r2
	xor #1, r2
	mov.b r2, [r1]
	rts

.type en_protect, %function
# enable register write protection
en_protect:
	mov.l #SYSTEM_PRCR, r1
	mov.l #0xA500, r2
	mov.w r2, [r1]
	rts

.type dis_protect, %function
# disable register write protection
dis_protect:
	mov.l #SYSTEM_PRCR, r1
	mov.l #0xA50B, r2
	mov.w r2, [r1]
	rts

.type clock_init, %function
clock_init:
	bsr dis_protect
	mov.l #SYSTEM_HOCOWTCR2, r1
	mov.l #14h, r2
	mov.b r2, [r1]

	mov.l #SYSTEM_HOCOCR, r1
	mov.l #0, r2
	mov.b r2, [r1]

	mov.l #SYSTEM_SCKCR3, r1
	mov.l #0x0100, r2
	mov.w r2, [r1]
	bsr en_protect
	rts

.global ms_wait
.type ms_wait, %function
ms_wait: ; arg: r3
	bsr dis_protect
	# disable module stop
	mov.l #SYSTEM_MSTPCRA, r1
	mov.l [r1], r2
	bclr #15, r2
	mov.l r2, [r1]
	bsr en_protect

	# set count constant for 1msec
	mov.l #CMT0_CMCOR, r1
	mov.l #(2000 - 1), r2
	mov.w r2, [r1]

	# enable interrupt
	mov.l #CMT0_CMCR, r1
	mov.w [r1], r2
	bset #6, r2
	mov.w r2, [r1]

	# set IPR & IER
	mov.l #ICU_CMT0_CMI0_IPR, r1
	mov.l #1, r2
	mov.b r2, [r1]
	mov.l #ICU_CMT0_CMI0_IER, r1
	mov.l #(1 << 4), r2
	mov.b r2, [r1]
	; rts

	# count start
	mov.l #CMT_CMSTR0, r1
	mov.l #1, r2
	mov.w r2, [r1]

	mov.l #0, r4 ; r4: counter
ms_cmp:
	cmp r3, r4
	bne outLoop

	# count stop
	mov.l #CMT_CMSTR0, r1
	mov.l #0, r2
	mov.l r2, [r1]
	rts

outLoop:
	# clear counts
	mov.l #CMT0_CMCNT, r1
	mov.l #0, r2
	mov.w r2, [r1]

	# clear IR
	mov.l #ICU_CMT0_IR, r1
	mov.l #0, r2
	mov.b r2, [r1]

inLoop:
	mov.l #ICU_CMT0_IR, r1
	mov.b [r1], r2
	tst #1, r2 ; r2 & 1 == 0 ?
	bz inLoop
	add #1, r4
	bra ms_cmp
