#ifndef PIC_H
#define PIC_H	1



#include <wl/types.h>



#define iowait()	outb(0x80, 0);
#define PIC1CMD		0x20
#define PIC1DATA	0x21
#define PIC2CMD		0xA0
#define PIC2DATA	0xA1
#define ICW1CW4		0x01
#define ICW1SINGLE	0x02
#define ICW1INT4	0x04
#define ICW1LEVEL	0x08
#define ICW1INIT	0x10
#define ICW48086	0x1
#define ICW4EOI		0x2
#define ICW4SLAVE	0x0
#define ICW4MASTER	0x4
#define ICW4BUFFER	0x8
#define ICW4SFNM	0x10
#define READIRR		0x0A
#define READISR		0x0B
#define PICEOI		0x20



extern void outb(U16l port, U8 value);
extern U8l inb(U16l port);
extern U8l sti();
extern U8l cli();
extern void picc(U8l pic1, U8l pic2);
extern void picm(U8l irq);
extern void picu(U8l irq);
extern void picd(/* U8l irq */);
extern U16 picirr();
extern U16 picisr();
extern void eoi(U8l irq);

#endif
