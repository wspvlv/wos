/**
 * \file	vga.h
 * \author	Wispy (wspvlv@gmail.com)
 * \brief	Vga output
 * \version 0.1
 * \date 2021-08-09
 * 
 * 
 */
#ifndef VGA_H
#define VGA_H


#include <wc/core.h>
#include <wc/types.h>



#ifndef REGION_MACROS
	/**
	 * \brief	VGA display width in characters
	 * \def		VW
	 * \def		VGA_WIDTH
	 */
#	define VW 				80
#	define VGA_WIDTH		VW
	/**
	 * \brief	VGA display height in characters
	 * \def		VH
	 * \def		VGA_HEIGHT
	 */
#	define VH				25
#	define VGA_HEIGHT 		VH
	/**
	 * \brief	VGA entry definition
	 * \def		ve(c,color)
	 * \def		VGADefineEntry
	 * \arg		ch		An ASCII character
	 * \arg		color	
	 */
#	define ve(c,fg,bg)		( (Ve)(c) | (Ve)(((fg)&0xF)<<8) | (Ve)(((bg)&0xF)<<12) )
#	define VGADefineEntry	ve
	/**
	 * \brief	Position a VGA entry at
	 * \def		vp(e, x, y)
	 * \def		VGAPositionEntry
	 */
#	define vp(e,x,y)		( vb[(y)*VW+(x)] = (e) )
//#	define vp(e,x,y)		( *(Ve*)(vb+((y)*VW+(x))*2) = (e) )
#	define VGAPositionEntry	vp

/* #	define voc(chr, fg, bg, x, y)	vp(ve((chr), (fg), (bg)), (x), (y)) */

#	define VGABuffer				vb
#	define VGARow					vr
#	define VGAColumn				vc
#	define VGACOLOR_BLACK			VCLK
#	define VGACOLOR_BLUE			VCLB
#	define VGACOLOR_GREEN			VCLG
#	define VGACOLOR_CYAN			VCLC
#	define VGACOLOR_RED				VCLR
#	define VGACOLOR_MAGENTA			VCLM
#	define VGACOLOR_ORANGE			VCLO
#	define VGACOLOR_GRAY			VCLLK
#	define VGACOLOR_LIGHT_GRAY		VCLDW
#	define VGACOLOR_LIGHT_BLUE		VCLLB
#	define VGACOLOR_LIGHT_GREEN		VCLLG
#	define VGACOLOR_LIGHT_CYAN		VCLLC
#	define VGACOLOR_LIGHT_RED		VCLLR
#	define VGACOLOR_LIGHT_MAGENTA	VCLLM
#	define VGACOLOR_LIGHT_ORANGE	VCLLO
#	define VGACOLOR_WHITE			VCLW
#endif



#ifndef REGION_TYPES
	/**
	 * \typedef	Ve
	 * \typedef VGAEntry
	 * \brief 	VGA Entry type
	 */
	typedef u16 Ve, VGAEntry;
	/**
	 * \typedef	Vp
	 * \typedef	VGAEntryPosition
	 * \brief 	VGA Entry position type
	 */
	typedef u8	Vp, VGAEntryPosition;
	/**
	 * \typedef Vbs
	 * \typedef VGABufferSize
	 * \brief	VGA Buffer Size
	 */
	typedef u8	Vbs, VGABufferSize;
	/**
	 * \enum	Vc
	 * \typedef Vc
	 * \typedef VGAColor
	 * \brief	VGA 16-color palette
	 */
	typedef enum Vcl {
		VCLK = 0,	/**< Black */
		VCLB = 1,	/**< Blue */
		VCLG = 2,	/**< Green */
		VCLC = 3,	/**< Cyan */
		VCLR = 4,	/**< Red */
		VCLM = 5,	/**< Magenta */
		VCLO = 6,	/**< Orange */
		VCLLK = 7,	/**< Gray (Light Black) */
		VCLDW = 8,	/**< Light Gray (Dark White) */
		VCLLB = 9,	/**< Light Blue */
		VCLLG = 10,	/**< Light Green */
		VCLLC = 11,	/**< Light Cyan */
		VCLLR = 12,	/**< Light Cyan */
		VCLLM = 13,	/**< Light Magenta */
		VCLLO = 14,	/**< Light Orange */
		VCLW = 15,	/**< White */
	} Vcl, VGAColor;
#endif



#ifndef REGION_VARIABLES
	extern Ve* vb;		/* VGA Buffer */
	extern Vp vr, vc;	/* VGA Row & Column */
#endif



#ifndef REGION_FUNCTIONS
	/* VGA Ouput Character */
	extern void voc(const char chr, const Vcl fg, const Vcl bg);
	/* extern void voc(const char chr, const Vcl fg, const Vcl bg, const Vp x, const Vp y); */
	/* VGA Ouput String */
	extern void vos(char* restrict const str, const Vcl fg, const Vcl bg);
#endif



#endif