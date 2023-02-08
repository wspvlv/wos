#ifndef IDT_H
#define IDT_H	1



#include <wl/types.h>



#define idtOffset(entry, offset)\
	(entry).offset0 = (offset);\
	(entry).offset1 = (offset)>>16
#define isqr(irq, handler) irqhs[(irq)] = (handler)



/**
 * \brief IDT Entry Type
 * 
 */
typedef struct IdtE {
	U16l	offset0;
	U16l	selector;
	U8l		reserved0;
	U8l		type		:4;
	Bl		reserved1	:1;
	U8l		privilege	:2;
	Bl		present		:1;
	U16l	offset1;
} __attribute__((packed)) IdtE;

/**
 * \brief IDT Descriptor
 * 
 */
typedef struct IdtD {
	U16l	size;
	IdtE*	offset;
} __attribute((packed)) IdtD; 

typedef struct Regs {
	U32l ds;
	U32l edi, esi, ebp, kesp, ebx, edx, ecx, eax;
	U32l interrupt, error;
	U32l eip, cs, eflags, esp, ss;
} __attribute((packed)) Regs;

typedef void (*IsrH)(Regs* regs);
typedef void (*IrqH)(Regs* regs);



/**
 * \brief Interrupt Descriptor Table
 * 
 */
extern IdtE idt[256];
extern U32l isr[256];
extern IdtD idtr;
extern IrqH irqhs[16];


/**
 * \brief IDT Load
 * 
 * Loads IDT
 */
extern void __attribute__((cdecl)) idtl(IdtD* idt);

extern void isrh(Regs* regs);
extern void isri();
extern void isrr(U8l intterrupt, IsrH handler);
extern void irqi();
extern void irqr(U8l irq, IrqH handler);



#endif
