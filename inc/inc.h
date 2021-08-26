/**
 * \file inc.h
 * \author Wispy (wspvlv@gmail.com)
 * \brief 
 * \version 0.1
 * \date 2021-08-09
 * 
 * 
 */
#ifndef INT_H
#define INT_H



#ifndef REGION_MACROS
	/**
	 * \brief	PIC1 Command
	 * \def		PIC1C
	 * \def		PIC1_COMMAND
	 */
#	define PIC1C			0x20
#	define PIC1_COMMAND	PIC1C
	/**
	 * \brief	PIC1 Data
	 * \def		PIC1C
	 * \def		PIC1_DATA
	 */
#	define PIC1D			0x21
#	define PIC1_DATA		PIC1D
	/**
	 * \brief	PIC2 Command
	 * \def		PIC2C
	 * \def		PIC2_COMMAND
	 */
#	define PIC2C			0xA0
#	define PIC2_COMMAND	PIC2C
	/**
	 * \brief	PIC2 Data
	 * \def		PIC2C
	 * \def		PIC2_DATA
	 */
#	define PIC2D			0xA1
#	define PIC2_DATA		PIC2D

#	define ICW1INIT		0x10
#	define ICW1_ICW4		0x01
#	define ICW4_8086		0x01
#endif



#ifndef REGION_FUNCTIONS
	/* PIC Remap */
	extern void picr();
#endif

#endif