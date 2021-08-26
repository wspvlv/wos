/**
 * \file gdt.h
 * \author Wispy (wspvlv@gmail.com)
 * \brief 
 * \version 0.1
 * \date 2021-08-11
 * 
 * Dependency tree:
 * gdt.h
 * ├─→ GDTD ←── struct GDTD
 * │   ├─→ size ←──── u16 ←── wl_U16 ←┬─ types.h ←── wc
 * │   └─→ offset ←── u64 ←── wl_U64 ←┤
 * ├─→ GDTE ←── struct GDTE           │
 * │   ├─→ limit0 ←┬─ u16 ←── wl_U16 ←┤
 * │   ├─→ base0 ←─┘                  │
 * │   ├─→ base1 ←─┬─ u8 ←─── wl_U8 ←─┘
 * │   ├─→ access ←┤
 * │   ├─→ limit1 ←┤
 * │   ├─→ flags ←─┤
 * │   └─→ base2 ←─┘
 * ├─→ GDT ←─── struct GDT
 * │   ├─→ kNull ←┬─ GDTE ←── struct GDTE
 * │   ├─→ kCode ←┤
 * │   └─→ kData ←┘
 * ├─→ gdt ←─── GDT ←─── struct GDT
 * └─→ gdtl ←── GDTD ←── struct GDTD
 */
#ifndef GDT_H
#define GDT_H



#include <wc/types.h>



#ifndef REGION_TYPES
	/**
	 * \brief	GDT Description Structure
	 * \typedef GDTD
	 * \struct	GDTD
	 * 
	 */
	typedef struct __attribute__((__packed__)) GDTD {
		u16 size;
		u32 offset;
	} GDTD;

	/**
	 * \brief	GDT Entry Structure
	 * \typedef GDTE
	 * \struct	GDTE
	 * 
	 */
	typedef struct __attribute__((__packed__)) GDTE {
		u16	limit0:16;
		u16	base0:16;
		u8	base1:8;
		u8	access:8;
		u8	limit1:4;
		u8	flags:4;
		u8	base2:8;
	} GDTE;

	/**
	 * \brief	Global Descriptor Table
	 * \typedef GDT
	 * \struct	GDT
	 * 
	 */
	typedef struct __attribute__((__packed__)) __attribute__((aligned(0x1000))) GDT {
		GDTE Null;
		GDTE x32Code;
		GDTE x32Data;
		GDTE x16Code;
		GDTE x16Data;
/* 		GDTE uNull;
		GDTE uCode;
		GDTE uData; */
	} GDT;
#endif

#ifndef REGION_VARS
	/**
	 * \brief	Main Global Descriptor Table
	 * \var		gdt
	 */
/* 	extern __attribute__((aligned(0x1000))) GDT gdt;
	extern GDTD gdtd; */
#endif

#ifndef REGION_FUNCTIONS
	extern void gdtl();
	/* extern GDTE gdten(const u32 limit, const u32 base, const u8 access, const u8 flags); */
#endif

#endif