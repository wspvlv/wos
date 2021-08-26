#include "idt.h"
#include "keyboard.h"
#include "vga.h"
#include "log.h"
#include "io.h"

IDT __attribute__((aligned(0x1000))) idt;
IDTD idtd;

// /**
//  * \brief General Protection fault handler
//  * 
//  */
// static __attribute__((interrupt)) void pfh(void* frame){
//     vos("Page Fault", VCLR, VCLK);
//     for(;;);
// }

// /**
//  * \brief General Protection fault handler
//  * 
//  */
// static __attribute__((interrupt)) void gfh(void* frame){
//     vos("General Protection Fault", VCLR, VCLK);
//     for(;;);
// }

void xh() {
	vos("Exception!", VCLR, VCLK);
	for (;;);
}

void idten(IDTE* i, void* isr, u8 flags) {
	i->offset0 = (_Ptr)isr & 0xFFFF;
	i->offset1 = (_Ptr)isr >> 16;
	i->selector = 0x08;
	i->type = flags&0b00001111;
	i->storage = flags&0b00010000 >> 4;
	i->dpl = flags&0b01100000 >> 5;
	i->present = flags&0b10000000 >> 7;
	i->zero = 0;
}

void idtl() {
	log('I','0');
	idtd.base = (_Ptr)&idt;
    idtd.limit = (u16)sizeof(IDTE) * 256 - 1;
	
	log('I','1');
	for (u8 i = 0; i < 32; i++) {
		idten(&idt[i], &isr_stub_table[i], 0x8E);
	}

/* 	log('I','2');
	IDTE* gf = (IDTE*)(idtd.base + 0xD * sizeof(IDTE));
	idten(gf, gfh, IDTIG);

	log('I','3');
	IDTE* pf = (IDTE*)(idtd.base + 0xE * sizeof(IDTE));
	idten(pf, pfh, IDTIG);

	log('I','4');
	IDTE* k = (IDTE*)(idtd.base + 0x21 * sizeof(IDTE));
	idten(k, kh, IDTIG); */

	log('I','5');
	__asm__ volatile("lidt %0" : : "m" (idtd) : "memory");
	log('I','6');
	/* prm();
    ob(P1D, 0b11111101);
    ob(P2D, 0b11111111); */
	log('I','7');
	__asm__ volatile ("sti");
	log('I','E');
}
