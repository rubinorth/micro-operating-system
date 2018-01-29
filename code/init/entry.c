/*
 2018-01-29
 内核的入口函数
 */

#include "console.h"
#include "debug.h"

int kern_entry()
{
	init_debug();
	console_clear();
	printk_color(rc_black, rc_green, "Hello, my kernel!!!\n");
	panic("test");
	
	return 0;
}

