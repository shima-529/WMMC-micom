ENTRY(_start)

MEMORY {
	RAM(rwx) : ORIGIN = 0x00000000, LENGTH = 16K
	ROM(rwx) : ORIGIN = 0xFFFC0000, LENGTH = 256K
}

SECTIONS {

	/* .text 0xFFFC0000 : AT (0xFFFC0000) { */
	.text : {
		_stext = .;
		*(.text)
		*(.text*)
		. = ALIGN(4);
		_etext = .;
	} > ROM

	.rodata : {
		. = ALIGN(4);
		*(.rodata)
		*(.rodata*)
		. = ALIGN(4);
	} > ROM

	_sidata = LOADADDR(.data);
	.data : {
		. = ALIGN(4);
		_sdata = .;
		*(.data)
		*(.data*)
		. = ALIGN(4);
		_edata = .;
	} > RAM AT > ROM

	.rvectors : {
		_srvectors = .;
		KEEP(*(.rvectors))
	} > ROM

	.fvectors 0xFFFFFF80 : AT(0xFFFFFF80) {
		_sfvectors = .;
		KEEP(*(.fvectors))
	} > ROM

	. = ALIGN(4);
	_end = .;

	.bss : {
		. = ALIGN(4);
		_sbss = .;
		*(.bss)
		*(.bss*)
		. = ALIGN(4);
		_ebss = .;
	} > RAM

	.istack 0x100 : AT(0x100) {
		. = ALIGN(4);
		_istack = .;
		*(.istack)
	} > RAM

	.ustack 0x300 : AT(0x300) {
		. = ALIGN(4);
		_ustack = .;
		*(.ustack)
	} > RAM

	/DISCARD/ : {
		*(.init)
		*(.fini)
	}
}
