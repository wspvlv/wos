#include "gdt.h"



GdtE gdt[3];
GdtD gdtr = { sizeof(gdt) - 1, gdt };



void gdti() {
	/* Code Segment*/
	gdtBase(gdt[1], 0);
	gdtLimit(gdt[1], 0xFFFF);
	gdt[1].access.accessed = FALSE;
	gdt[1].access.rw = TRUE;
	gdt[1].access.dc = FALSE;
	gdt[1].access.executable = TRUE;
	gdt[1].access.type = TRUE;
	gdt[1].access.privilege = 0;
	gdt[1].access.present = TRUE;
	/* A very elaborate way to cast a struct to int */
	gdt[1].flags = (GdtF){
		._struct = (struct GdtFStruct){
			.longMode = TRUE,
			.size = TRUE,
			.granularity = TRUE
		}
	}._int;
	/* Data Segment */
	gdtBase(gdt[2], 0);
	gdtLimit(gdt[2], 0xFFFF);
	gdt[2].access.accessed = FALSE;
	gdt[2].access.rw = TRUE;
	gdt[2].access.dc = FALSE;
	gdt[2].access.executable = FALSE;
	gdt[2].access.type = TRUE;
	gdt[2].access.privilege = 0;
	gdt[2].access.present = TRUE;
	/* A very elaborate way to cast a struct to int */
	gdt[2].flags = (GdtF){
		._struct = (struct GdtFStruct){
			.longMode = TRUE,
			.size = TRUE,
			.granularity = TRUE
		}
	}._int;

	gdtl(&gdtr, 0x08, 0x10);
}
