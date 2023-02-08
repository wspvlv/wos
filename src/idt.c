#include <idt.h>
#include <term.h>
#include <pic.h>
#include <keyboard.h>



#define PIC_REMAP_OFFSET        0x20



IdtE idt[256];
IdtD idtr = { sizeof(idt)-1, idt };
IrqH irqhs[16];
IsrH isrhs[256];



void __attribute__((cdecl)) isrh(Regs* regs) {
	if (isrhs[regs->interrupt] != NULL)
		isrhs[regs->interrupt](regs);
	else if (regs->interrupt >= 32)
		ps("Unhandled Interrupt");
	else
		ps("Panik");
}

void isri() {
	idtl(&idtr);

	for (U16l i = 0; i < 256; i++) {
		idtOffset(idt[i], isr[i]);
		idt[i].selector = 0x08;
		idt[i].reserved0 = 0;
		idt[i].type = 0xE;
		idt[i].reserved1 = 0;
		idt[i].privilege = 0;
		idt[i].present = 1;
	}
}

void isrr(U8l interrupt, IsrH handler) {
	isrhs[interrupt] = handler;
	idt[interrupt].present = 1;
}

void irqh(Regs* regs) {
	U8f irq = regs->interrupt - PIC_REMAP_OFFSET;

	if (irqhs[irq] == NULL)
		ps("Unhandled IRQ\n\r");
	else irqhs[irq](regs);

	eoi(irq);
}

void timerHandler() {}

void irqi() {
	picc(PIC_REMAP_OFFSET, PIC_REMAP_OFFSET+8);

	irqhs[0] = timerHandler;
	irqhs[1] = keyboardHandler;

	for (U8f i = 0; i < 16; i++)
		isrr(PIC_REMAP_OFFSET + i, irqh);

	sti();
}
