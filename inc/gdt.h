#ifndef GDT_H
#define GDT_H	1



#include <wl/types.h>



#define gdtLimit(entry, limit)	\
	(entry).limit0 = (limit);\
	(entry).limit0 = (limit)>>16

#define gdtBase(entry, base)	\
	(entry).base0 = (base);\
	(entry).base1 = (base)>>16;\
	(entry).base2 = (base)>>24



/**
 * \brief GDT Entry Access Byte Type
 * 
 */
typedef struct GdtAb {
	Bl	accessed	:1;	/* Accessed bit */
	Bl	rw			:1;	/* Readable/Writeable bit */
	Bl	dc			:1;	/* Direction/Conforming bit */
	Bl	executable	:1;	/* Executable bit */
	Bl	type		:1;	/* Descriptor type bit */
	U8l privilege	:2; /* Descriptor privilege level bit */
	Bl	present		:1;	/* Present bit */
} __attribute__((packed)) GdtAb;

/**
 * \brief GDT Entry Flags Type
 * 
 */
typedef union GdtF {
	struct GdtFStruct {
		Bl	reserved	:1;
		Bl	longMode	:1;	/* Long-mode code flag */
		Bl	size		:1;	/* Size flag */
		Bl	granularity	:1;	/* Granularity flag */
	} _struct;
	U8l _int;
} GdtF;

/**
 * \brief GDT Entry Type
 * 
 */
typedef struct GdtE {
	U16l	limit0;
	U16l	base0;
	U8l		base1;
	GdtAb	access;
	U8l		limit1	:4;
	U8l		flags	:4;
	U8l		base2;
} __attribute__((packed)) GdtE;

/**
 * \brief GDT Descriptor
 * 
 */
typedef struct GdtD {
	U16l	size;
	GdtE*	offset;
} __attribute((packed)) GdtD;


/**
 * \brief Global Descriptor Table
 * 
 */
extern GdtE gdt[3];

extern GdtD gdtr;



/**
 * \brief GDT Load
 * 
 * Loads GDT
 */
extern void __attribute__((cdecl)) gdtl(
	GdtD* gdt, 
	U16l codeSegment, 
	U16l dataSegment
);

extern void gdti();

#endif
