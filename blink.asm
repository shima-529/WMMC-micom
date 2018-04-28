.text
.code 16
.syntax unified

@@ Register Macros @@
.equ RCC_BASE, 0x40021000
.equ RCC_AHBENR, RCC_BASE + 0x14

.equ GPIOA_BASE, 0x48000000
.equ GPIOB_BASE, 0x48000400
.equ GPIOA_MODER, GPIOA_BASE + 0x00
.equ GPIOA_ODR, GPIOA_BASE + 0x14
.equ GPIOB_MODER, GPIOB_BASE + 0x00
.equ GPIOB_ODR, GPIOB_BASE + 0x14

.equ SCS_BASE, 0xE000E000
.equ SysTick_BASE, SCS_BASE + 0x10
.equ SysTick_CTRL, SysTick_BASE + 0x00
.equ SysTick_LOAD, SysTick_BASE + 0x04
.equ SysTick_VAL, SysTick_BASE + 0x08

@@ Register Bit Macros @@
.equ RCC_AHBENR_IOAEN, 0x20000
.equ RCC_AHBENR_IOBEN, 0x40000
.equ BIT7, (1 << 7)
.equ MODER_BIT7, (1 << (7*2))
.equ SysTick_CTRL_ENABLE, 1

.global main, code, thumb @ open main to global domain
.type main, %function
main:
	LDR r0, =RCC_AHBENR
	LDR r1, [r0]
	orr r1, r1, #RCC_AHBENR_IOBEN
	str r1, [r0]
	@@ set GPIOB_7 to output
	LDR r0, =GPIOB_MODER
	LDR r1, [r0]
	orr r1, r1, #MODER_BIT7
	bic r1, r1, #(MODER_BIT7 << 1)
	str r1, [r0]

.extern fuck
LEDToggle:
	@@ set GPIOB_7
	LDR r0, =GPIOB_ODR
	ldr r1, [r0]
	eor r1, r1, #BIT7
	str r1, [r0]

	mov r0, #1000
	bl ms_wait
	b LEDToggle

.global ms_wait
.type ms_wait, %function
ms_wait: @ wait for r0 msec.
	ldr r1, =SysTick_VAL
	mov r2, #0
	str r2, [r1]
	ldr r1, =SysTick_LOAD
	mov r2, #(1000 - 1)
	str r2, [r1]
	ldr r1, =SysTick_CTRL
	ldr r2, [r1]
	orr r2, r2, #SysTick_CTRL_ENABLE
	str r2, [r1]
	ldr r1, =SysTick_CTRL
waitForFlag:
	ldr r2, [r1]
	ands r2, r2, (1 << 16)
	beq waitForFlag

	subs r0, r0, #1
	bne waitForFlag
ms_waitEnd: @ if r0 == 0 then
	ldr r1, =SysTick_CTRL
	ldr r2, [r1]
	bic r2, r2, #SysTick_CTRL_ENABLE
	str r2, [r1]
	bx lr

.end
