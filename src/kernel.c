#include "term.h"
#include "gdt.h"
#include "idt.h"

void __attribute__((cdecl)) kernel() {
	gdti();
	isri();
	irqi();
    cs();
	ps("wOS\n\r");
	for(;;);
}
