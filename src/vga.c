/**
 * \file vga.c
 * \author Wispy (wspvlv@gmail.com)
 * \brief 
 * \version 0.1
 * \date 2021-08-09
 * 
 * 
 */
#include "vga.h"
#include <wc/char.h>
#include "log.h"

/**
 * \var		VGABuffer
 * \brief	VGA Buffer
 */
Ve* vb;
/**
 * \var		VGARow
 * \brief	VGA Row Coordinate
 */
/**
 * \var		VGAColumb
 * \brief	VGA Column Coordinate
 */
Vp vr, vc;

/**
 * \fn		voc
 * \brief	VGA Output Character
 */
void voc(const char chr, const Vcl fg, const Vcl bg) {
	log('V','C');
			if (chr == '\n') vr++;
	else	if (chr == '\r') vc = 0;
	else {
		vp( ve(chr,fg,bg), vc, vr );
		if (++vc == VW) {
			vc = 0;
			if (++vr == VH)
				vr = 0;
		}
	}
}

/**
 * \fn		vos
 * \brief	VGA Output String
 * Basically outputs a character string length times
 */
void vos(char* restrict const str, const Vcl fg, const Vcl bg) {
	log('V','S');
	for (Vbs i = 0; i < sl(str); i++)
		voc(str[i], fg, bg);
}