#include <wl/array.h>
#include "term.h"



/**
 * \brief	VGA Text Buffer 
 * \def		VGATB
 */
#define	VGATB		0xB8000
/**
 * \brief	VGA Text Buffer Width 
 * \def		VGATB
 * Width of VGA's text buffer in 16-bit words, a.k.a. the number of columns in
 * the buffer
 */
#define VGATBW		80
/**
 * \brief	VGA Text Buffer Width 
 * \def		VGATH
 * Height of VGA's text buffer in 16-bit words, a.k.a. the number of row in the * buffer
 */
#define VGATBH		20



U16l* tbCursor = (U16l*)VGATB;



/* Print Characters */
void pcs(char* c, U16f n) {
	U16f i;
	for (i = 0; i < n; i++) {
		if_unlikely(c[n] == '\n') {
			
		}
		pc(c[n]);
	}
}

/* Print String */
void ps(char* c) {
	while (*c != '\0') {
		pc(*c);
		c++;
	}
}

/* Clear screen */
void cs() {
	while ((Pt)tbCursor < VGATB+VGATBW*VGATBH*sizeof(tbCursor)) {
		pc('\0');
	}
	tbCursor = (U16l*)VGATB;
}

char* x2s(U8l i, char* str) {
	char j = i&0xF;
	if (j < 10) str[1] = '0'+j;
	else str[1] = 'A'+(j-10);
	j = (i>>4)&0xF;
	if (j < 10) str[0] = '0'+j;
	else str[0] = 'A'+(j-10);
	str[2] = 0;
	return str;
}
