# as = ../wcc/bin/i686-elf-as -msyntax=intel -mnaked-reg
as = nasm 
# -msyntax=intel -mnaked-reg
cc = i686-elf-gcc -ffreestanding -Ofast -Iinc -I../wlib/inc -m32 -Wall -Wextra -Werror -Wfatal-errors -nostdlib -DWL_PREFIX=0 -DWL_LIBC=0
emu = qemu-system-x86_64
obj = obj
src = src
inc = inc
bin = bin
iso = iso

boot:
	mkdir -p $(bin)
	$(as) -fbin $(src)/boot-bin.s -o $(bin)/boot.x
kernel:
	mkdir -p $(obj)
	$(as) -felf32 $(src)/prot.s -o $(obj)/prot.o
	$(as) -felf32 $(src)/gdtl.s -o $(obj)/gdtl.o
	$(as) -felf32 $(src)/idtl.s -o $(obj)/idtl.o
	$(as) -felf32 $(src)/isr.s -o $(obj)/isr.o
	$(as) -felf32 $(src)/pic.s -o $(obj)/pic.s.o
	$(cc) -c $(src)/term.c -o $(obj)/term.o
	$(cc) -c $(src)/gdt.c -o $(obj)/gdt.o
	$(cc) -c $(src)/idt.c -o $(obj)/idt.o -Wno-array-bounds
	$(cc) -c $(src)/pic.c -o $(obj)/pic.o
	$(cc) -c $(src)/keyboard.c -o $(obj)/keyboard.o
	$(cc) -c $(src)/kernel.c -o $(obj)/kernel.o
build: boot kernel
	$(cc) \
		$(obj)/kernel.o \
		$(obj)/prot.o	\
		$(obj)/gdtl.o	\
		$(obj)/pic.s.o	\
		$(obj)/gdt.o	\
		$(obj)/idtl.o	\
		$(obj)/idt.o	\
		$(obj)/isr.o	\
		$(obj)/pic.o	\
		$(obj)/term.o	\
		$(obj)/keyboard.o	\
	-o $(bin)/wos.x -Tlinker.ld -L../wlib/lib -lwa
iso: build
	dd if=/dev/zero of=iso/wos.iso bs=512 count=2880 >/dev/null
	mkfs.fat -F 12 -n "NBOS" iso/wos.iso >/dev/null
	dd if=$(bin)/boot.x of=iso/wos.iso conv=notrunc >/dev/null
	mcopy -i iso/wos.iso ../wlib/lib/libwa.a "::libwa.a"
	mcopy -i iso/wos.iso $(bin)/boot.x "::boot.x"
	mcopy -i iso/wos.iso $(bin)/wos.x "::wos.x"
# mkdir -p $(iso)/boot/grub
# cp $(bin)/boot.x $(iso)/boot/boot.x
# cp $(bin)/wos.x $(iso)/boot/wos.x
# cp $(src)/grub.cfg $(iso)/boot/grub/grub.cfg
# grub-mkrescue -o wos.iso $(iso)
debug:
	$(emu) -cdrom wos.iso
#	$(emu) -kernel $(bin)/wos.x
all: boot kernel build iso
run: 
#	$(emu) -cdrom iso/wos.iso
	qemu-system-i386 -fda iso/wos.iso

.PHONY: iso
