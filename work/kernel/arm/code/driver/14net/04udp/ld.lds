SECTIONS
{
	. = 0x50000000;
	.text : {*(.text);}

	. = ALIGN(4);
	.data : {*(.data);}

	. = ALIGN(4);
	.bss : {*(.bss);}
}
