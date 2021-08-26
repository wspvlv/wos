#ifndef IDT_H
#define IDT_H

#	include <wc/types.h>



#define IDTIG	0b10001110
#define IDTCG	0b10001100
#define IDTTG	0b10001111

#ifndef REGION_TYPES
	/**
	 * \brief	IDT Descriptor Structure
	 * \typedef IDTD
	 * \struct	IDTD
	 * 
	 */
	typedef struct __attribute__((__packed__)) IDTD {
		u16 limit;
		u32 base;
	} IDTD;

	/**
	 * \brief	IDT Entry Structure
	 * \typedef IDTE
	 * \struct	IDTE
	 * 
	 */
	typedef struct __attribute__((__packed__)) IDTE {
		u64	offset0:16;
		u64	selector:16;
		u64	zero:8;
		u64	type:4;
		u64 storage:1;
		u64 dpl:2;
		u64 present:1;
		u64 offset1:16;
	} IDTE;

	/**
	 * \brief	Interrupt Descriptor Table
	 * \typedef IDT
	 * \struct	IDT
	 * 
	 */
	typedef IDTE __attribute__((aligned(0x1000))) IDT[256];
/* 	typedef struct __attribute__((__packed__)) IDT {
		IDTE irq[256];
	} IDT; */
#endif

#ifndef REGION_DECLARATIONS
extern __attribute__((aligned(0x1000))) IDT idt;
extern IDTD idtd;
extern u32 isr_stub_table[];
extern void idteso();	/* IDT Entry Set Offset */
extern void idtl();
__attribute__((noreturn)) extern void xh();	/* Exception handler */
#endif

#endif