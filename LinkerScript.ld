/* NOTE: Only for C, not for C++ */

/* References:
 * http://www.ertl.jp/~takayuki/readings/c/no09.html
 * https://www.computex.co.jp/article/use_gcc_1.htm
 * http://nsaito-nmiri.hateblo.jp/entry/2015/05/22/201534
 */

ENTRY(Reset_Handler) /* The symbol which MCU goes into immediately after reset */

/* symbols used either in or outside of this script */
_estack = 0x20003000; /* the end address of stack */

MEMORY { /* memory command defining memory area */
	RAM (xrw): ORIGIN = 0x20000000, LENGTH = 12K /* executable & readable & writable */
	ROM (xrw): ORIGIN = 0x08000000, LENGTH = 64K /* flash rom area */
}

SECTIONS {
	.isr_vector : {
		. = ALIGN(4);
		KEEP(*(.isr_vector)) /* vector array. '*' outside of () means 'any object file'. */
		/* KEEP() does not allow unused symbols into garbage collections. */
		. = ALIGN(4);
	} > ROM /* the function pointer is written on ROM. */
	
	.text : { /* program area */
		. = ALIGN(4);
		*(.text)
		*(.text*)
		. = ALIGN(4);
	} > ROM
	
	.rodata : { /* constant value */
		. = ALIGN(4);
		*(.rodata)
		*(.rodata*)
		. = ALIGN(4);
	} > ROM
	
	_sidata = LOADADDR(.data); /* LOADADDR() returns the address on ROM(AT>ROM), whereas ADDR() RAM(>RAM). */
	.data : { /* variables with its initial value */
		. = ALIGN(4);
		_sdata = .;
		*(.data)
		*(.data*)
		. = ALIGN(4);
		_edata = .;
	} > RAM AT > ROM 
	
	. = ALIGN(4);
	.bss : { /* variables without the initial value */
		_sbss = .;
		*(.bss)
		*(.bss*)
		. = ALIGN(4);
		_ebss = .;
	} > RAM
	
	. = ALIGN(8);
	PROVIDE(end = .); /* weak definition */
	
	/DISCARD/ : { /* Sections written in this block is not programmed. */
		*(.init)
		*(.fini)
	}
}