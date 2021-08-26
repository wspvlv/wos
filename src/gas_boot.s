/* Declare constants for the multiboot header. */
.set ALIGN,    1<<0             /* align loaded modules on page boundaries */
.set MEMINFO,  1<<1             /* provide memory map */
.set FLAGS,    ALIGN | MEMINFO  /* this is the Multiboot 'flag' field */
.set MAGIC,    0x1BADB002       /* 'magic number' lets bootloader find the header */
.set CHECKSUM, -(MAGIC + FLAGS) /* checksum of above, to prove we are multiboot */

 
/* 
Declare a multiboot header that marks the program as a kernel. These are magic
values that are documented in the multiboot standard. The bootloader will
search for this signature in the first 8 KiB of the kernel file, aligned at a
32-bit boundary. The signature is in its own section so the header can be
forced to be within the first 8 KiB of the kernel file.
*/
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

/**/
.section .stack
.align 16
sbottom:
	.skip 16384	# 16 KB
stop:

.section .text
.global _start
.type _start, @function
_start:
	mov $stop, %esp	/* Initialize stack */
	/* Infinite loop */
	cli
	lgdt $rdi
	mov %eax, %cr0
	or %eax, 1
	mov %cr0, %eax
	call kernel		/* Load the kenel */
halt:
	hlt
	jmp halt

.size _start, .-_start
