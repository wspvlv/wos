TARGET=i686-elf
#TARGET=x86_64-elf

wcc_dir = /home/wispy/prj/wcc/bin
bin = bin/$(TARGET)
gcc = $(wcc_dir)/$(TARGET)-gcc -ffreestanding -Ofast -Wall -Wextra -Werror -Wfatal-errors -I$(inc) -Iinc -nostdlib -nostdinc -DOS_WOS=1 -std=c2x
wlib_gcc = $(wcc_dir)/$(TARGET)-gcc -ffreestanding -DOS_WOS=1
asm-x86_64-elf = /usr/bin/nasm -felf64
asm-i686-elf = /usr/bin/nasm -felf
asm = $(asm-$(TARGET))
inc = /home/wispy/prj/wlib/inc

# For wlib
wlib = /home/wispy/prj/wlib
lsobj = $(shell find $(wlib)/obj/* -name '*.o' | tr '\n' ' ')
crobj = $(shell $(wlib)/lib.sh "$(wlib_gcc)" $(wlib)/src $(wlib)/obj $(wlib)/inc)

always:
	mkdir -p bin
	mkdir -p $(bin)
wlib:
	$(call crobj)
	ar -rc $(bin)/wc.l $(call lsobj)
boot:
	$(asm) src/boot.s -o $(bin)/boot.o
kernel: kernel-$(TARGET);
kernel-i686-elf:
	$(asm) src/gdt.s -o $(bin)/gdt.o
	$(asm) src/idt.s -o $(bin)/idts.o
	$(asm) src/io.s -o $(bin)/io.o
	$(gcc) -c src/idt.c -o $(bin)/idt.o -mgeneral-regs-only -Wno-unused-parameter
	$(gcc) -c src/vga.c -o $(bin)/vga.o
	$(gcc) -c src/kernel.c -o $(bin)/kernel.o
	$(gcc) -c src/keyboard.c -o $(bin)/keyboard.o -mgeneral-regs-only -Wno-unused-parameter
	$(gcc) $(bin)/boot.o $(bin)/kernel.o $(bin)/vga.o $(bin)/idt.o $(bin)/idts.o $(bin)/gdt.o $(bin)/io.o $(bin)/keyboard.o -T linker.ld -o $(bin)/wos.x -L$(bin) -l:wc.l 
kernel-x86_64-elf:
iso:
	mkdir -p isodir/boot/grub
	cp $(bin)/wos.x isodir/boot/wos.x
	cp grub.cfg isodir/boot/grub/grub.cfg
#	grub-mkrescue -o $(bin)/wos.iso isodir
#	grub-mkrescue -b /boot/eltorito.img -no-emul-boot -boot-load-size 4 -boot-info-table -iso-level 3 -o $(bin)/wos.iso isodir -V "WOS" -J -R -c boot/bootcat
	grub-mkrescue -R -J -c boot/bootcat -b /boot/eltorito.img -no-emul-boot -boot-load-size 4 -o $(bin)/wos.iso isodir

run:
	qemu-system-x86_64 -cdrom $(bin)/wos.iso
debug:
	bochs -f boch.cfg
all:
	make boot
	make kernel
	make iso
