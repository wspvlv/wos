#include <pic.h>
#include <term.h>



void picc(U8l pic1, U8l pic2) {
	outb(PIC1CMD, ICW1CW4|ICW1INIT);	iowait();
	outb(PIC2CMD, ICW1CW4|ICW1INIT);	iowait();
	outb(PIC1DATA, pic1);				iowait();
	outb(PIC2DATA, pic2);				iowait();
	outb(PIC1DATA, 4);					iowait();
	outb(PIC2DATA, 2);					iowait();
	outb(PIC1DATA, ICW48086/* |ICW4EOI */);	iowait();
	outb(PIC2DATA, ICW48086/* |ICW4EOI */);	iowait();
	outb(PIC1DATA, 0);					iowait();
	outb(PIC2DATA, 0);					iowait();
	/* Set the scan code set to 1 */
/* 	outb(0x60, 0xF0);	iowait();
	outb(0x60, 1);		iowait();
	if (inb(0x60) != 0xFA) ps("Could not set the scan code\r\n"); */
	/* U8l i, c;
	for (i = 0, c = 0; i == 0xFE && c < 3; c++, i = inb(0x60)) {
		outb(0x60, 0xF0);	iowait();
		outb(0x60, 1);		iowait();
	}
	if (i != 0xFA) ps("Could not set the scan code\r\n"); */
	/* Enable scanning */
	outb(0x60, 0xF4);	iowait();
	if (inb(0x60) != 0xFA) ps("Could not enable scanning\r\n");
	/* for (i = 0, c = 0; i == 0xFE && c < 3; c++, i = inb(0x60)) {
		outb(0x60, 0xF4);	iowait();
	}
	if (i != 0xFA) ps("Could not enable scanning\r\n"); */
}

void picm(U8l irq) {
	irq -= (irq>=8)<<3;
	/* port = PIC1DATA | (irq&8)<<4; */
	outb(PIC1DATA, inb(PIC1DATA) | (1<<irq));
}

void picu(U8l irq) {
	irq -= (irq>=8)<<3;
	/* port = PIC1DATA | (irq&8)<<4; */
	outb(PIC1DATA, inb(PIC1DATA) & ~(1<<irq));
}

void picd() {
	outb(PIC1DATA, 0xFF);				iowait();
	outb(PIC2DATA, 0xFF);				iowait();
}

U16 picirr() {
	outb(PIC1CMD, READIRR);				iowait();
	outb(PIC2CMD, READIRR);				iowait();
	return ((U16l)inb(PIC2CMD)) | (((U16l)inb(PIC2CMD)) << 8);
}

U16 picisr() {
	outb(PIC1CMD, READISR);				iowait();
	outb(PIC2CMD, READISR);				iowait();
	return ((U16l)inb(PIC2CMD)) | (((U16l)inb(PIC2CMD)) << 8);
}

void eoi(U8l irq)
{
    outb(PIC1CMD | (irq>=8)<<7, 0x20);
}
