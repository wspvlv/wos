/**
 * \file int.c
 * \author Wispy (wspvlv@gmail.com)
 * \brief 
 * \version 0.1
 * \date 2021-08-09
 * 
 * 
 */
#include "inc.h"
#include <wc/types.h>

/**
 * \brief	PIC Remap
 * \fn		void picr();
 */
void picr() {
	u8	a1 = ib(PIC1D), 
		a2 = ib(PIC2D);

	ob(PIC1C, ICW1INIT | ICW1_ICW4);
	ob(PIC2C, ICW1INIT | ICW1_ICW4);
	ob(PIC1D, 0x20);
	ob(PIC2D, 0x28);
	ob(PIC1D, 4);
	ob(PIC1D, 2);
	ob(PIC1D, ICW4_8086);
	ob(PIC2D, ICW4_8086);

	ob(PIC1D, a1);
	ob(PIC1D, a2);
}