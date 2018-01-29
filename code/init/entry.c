/*
 2018-01-29
 内核的入口函数
 */

#include "console.h"

int kern_entry(multiboot_t *mboot_ptr)
{
	console_clear();
	console_write_color("Hello, my kernel!!!\n", rc_black, rc_green);
	
	return 0;
}

