#include "vga.h"
#include "io.h"
#include "keyboard.h"
#include "log.h"

static const char ascii[] = {
	 0 ,  0 , '1', '2', '3', '4', '5', '6',
	'7', '8', '9', '0', '-', '=',  0 ,  0 , 
	'q', 'w', 'e', 'r', 't', 'y', 'u', 'i',
	'o', 'p', '[', ']',  0 ,  0 , 'a', 's',
	'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',
	'\'','`',  0 , '\\', 'z', 'x', 'c', 'v',
	'b', 'n', 'm', ',', '.', '/',  0 , '*',
	 0 , ' '
};

/**
 * \brief	Keyboard interrupt handler
 * \fn		__attribute__((interrupt)) void kh(void* unused) 
 * \param	unused
 */
__attribute__((interrupt)) void kh(const void* restrict const unused) {
	log('K','H');
	u8 sc = ib(0x60);
	if (sc < 58 && ascii[sc])
		voc(ascii[sc], VCLW, VCLK);
	pem();
}

/**
 * \brief	PIC End Master
 * \fn		void pem()
 */
void pem() {
	log('P','M');
	ob(P1C, PEOI);
}

/**
 * \brief	PIC End Slave
 * \fn		void pes()
 */
void pes() {
	log('P','S');
	ob(P2C, PEOI);
	ob(P1C, PEOI);
}

/**
 * \brief	PIC Remap
 * \fn		void prm()
 */
void prm() {
	log('P','R');
	u8 a1, a2;

	a1 = ib(P1D);
	a2 = ib(P2D);

	ob(P1C, I1I | I1I4);
	ob(P2C, I1I | I1I4);

	ob(P1D, 0x20);
	ob(P2D, 0x28);

	ob(P1D, 4);
	ob(P2D, 2);

	ob(P1D, I4_8086);
	ob(P2D, I4_8086);

	ob(P1D, a1);
	ob(P2D, a2);
}					/* Keyboard Scancode to Character */