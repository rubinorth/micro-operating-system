/*
 2018-01-29
 内核的入口函数
 */

#include "gdt.h"
#include "console.h"
#include "debug.h"
#include "idt.h"
#include "timer.h"
#include "pmm.h"

int kern_entry()
{
	init_debug();
	init_gdt();
	init_idt();
	
	console_clear();
	printk_color(rc_black, rc_green, "Hello, my kernel!!!\n");
	
	init_timer(200);
	
	printk("kernel in memory start: 0x%08X\n", kern_start);
	printk("kernel in memory end: 0x%08X\n", kern_end);
	printk("kernel in memory used: %d KB\n\n", (kern_end - kern_start + 1023) / 1024);
	show_memory_map();
	
	init_pmm();

	printk_color(rc_black, rc_red, "\nThe Count of Physical Memory Page is: %u\n\n", phy_page_count);

	uint32_t allc_addr = NULL;
	printk_color(rc_black, rc_light_brown , "Test Physical Memory Alloc :\n");
	for(int i=0;i<5;i++){
		allc_addr = pmm_alloc_page();
		printk_color(rc_black, rc_light_brown , "Alloc Physical Addr: 0x%08X\n", allc_addr);
	}
	
	return 0;
}

