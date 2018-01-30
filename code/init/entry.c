/*
 2018-01-29
 内核的入口函数
 */

#include "gdt.h"
#include "console.h"
#include "debug.h"
#include "idt.h"
#include "timer.h"

int kern_entry()
{
	init_debug();
	init_gdt();
	init_idt();
	
	console_clear();
	printk_color(rc_black, rc_green, "Hello, my kernel!!!\n");
	
	init_timer(200);
	asm volatile("sti");
	return 0;
}

