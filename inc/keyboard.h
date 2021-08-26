#ifndef KEYBOARD_H
#define KEYBOARD_H

#ifndef REGION_MACROS
#	define P1C		0x20	/* PIC1 Command Port */
#	define P1D		0x21	/* PIC1 Data Port */
#	define P2C		0xA0	/* PIC2 Command Port */
#	define P2D		0xA1	/* PIC2 Data Port */
#	define PEOI		0x20	/* PIC EOI */

#	define I1I		0x10	/* ICW1 INIT */
#	define I1I4		0x01	/* ICW1 ICW4 */
#	define I4_8086	0x01	/* ICW4 8086 */
#endif

#ifndef REGION_VARS
#endif

#ifndef REGION_FUNCTIONS
	/* Keyboard interrupt handler */
	extern __attribute__((interrupt)) void kh(const void* restrict const unused);
	extern void prm();								/* PIC Remap */
	extern void pem();								/* PIC End Master */
	extern void pes();								/* PIC End Slave */
	// extern void k2c(const u8 sc, const bl caps);	/* Keyboard Scancode to Character */
#endif

#endif