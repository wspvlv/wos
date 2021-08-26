#include "vga.h"
#include "gdt.h"
#include "idt.h"
#include "io.h"
#include "keyboard.h"
#include "log.h"



void kernel() {
	log('K','O');
	vb = (Ve*)0xB8000;
	/* This strings signifies the kernel was loaded sucessfully*/
	vos("Welcome to wOS!", VCLW, VCLK);	/* Greet user */
	
	log('K','G');
	gdtl();								/* Load GDT */
	
	log('K','I');
	idtl();
	
	log('K','L');
	for(;;);

	log('K','E');
}
