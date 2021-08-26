#include "idt.h"
#include "keyboard.h"
#include "vga.h"
#include "log.h"
#include "io.h"

extern void* isr_stub_table[];

IDT idt;
IDTD idtd;

/**
 * \brief General Protection fault handler
 * 
 */
static __attribute__((interrupt)) void pfh(void* frame){
    vos("Page Fault", VCLR, VCLK);
    for(;;);
}

/**
 * \brief General Protection fault handler
 * 
 */
static __attribute__((interrupt)) void gfh(void* frame){
    vos("General Protection Fault", VCLR, VCLK);
    for(;;);
}

static inline void idten(IDTE* restrict i, void* restrict isr, u8 flags) {
	i->offset0 = (_Ptr)isr & 0xFFFF;
	i->offset1 = (_Ptr)isr >> 16;
	i->selector = 0x08;
	i->type = flags&0x0F;
	i->storage = flags&0x10 >> 4;
	i->dpl = flags&0x60 >> 5;
	i->present = flags&0x80 >> 7;
	i->zero = 0;
}

void idtl() {
	log('I','0');
	idtd.base = (_Ptr)&idt[0];
    idtd.limit = (u16)sizeof(IDTE) * 256 - 1;
	
	log('I','1');
	for (u8 i = 0; i < 32; i++) {
		idten(&idt[i], &isr_stub_table[i], 0x8E);
	}

	log('I','2');
	IDTE* gf = (IDTE*)(idtd.base + 0xD * sizeof(IDTE));
	idten(gf, gfh, IDTIG);

	log('I','3');
	IDTE* pf = (IDTE*)(idtd.base + 0xE * sizeof(IDTE));
	idten(pf, pfh, IDTIG);

	log('I','4');
	IDTE* k = (IDTE*)(idtd.base + 0x21 * sizeof(IDTE));
	idten(k, kh, IDTIG);

	log('I','5');
	__asm__ volatile ("lidt %0" : : "memory"(idtd)); // load the new IDT
	log('I','6');
	prm();
    ob(P1D, 0b11111101);
    ob(P2D, 0b11111111);
	log('I','7');
	__asm__ volatile ("sti"); // set the interrupt flag
	log('I','E');
}
