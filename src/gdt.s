[bits 32]

;section .data
;section .text

gdtl:
	lgdt [gdtd]
	jmp 0x08:.rcs
.rcs:
	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
	ret
GLOBAL gdtl

; Global Descriptor Table
gdt:
	; NULL descriptor
	dq 0
	; 32-bit code segment
	dw 0xFFFF		; limit 0—15
	dw 0			; base 0—15
	db 0			; base 16—23
	db 10011010b	; access (present, ring 0, code, exec, direction 0, read, access 0)
	db 11001111b	; granularity (4K pages, 32-bit pmode) + limit 16—19
	db 0			; base high
	; 32-bit data segment
	dw 0xFFFF		; limit 0—15
	dw 0			; base 0—15
	db 0			; base 16—23
	db 10010010b	; access (present, ring 0, data, not exec, direction 0, read, access 0)
	db 11001111b	; granularity (4K pages, 32-bit pmode) + limit 16—19
	db 0			; base high
	; 16-bit code segment
	dw 0xFFFF		; limit 0—15
	dw 0			; base 0—15
	db 0			; base 16—23
	db 10011010b	; access (present, ring 0, code, exec, direction 0, read, access 0)
	db 00001111b	; granularity (1B pages, 16-bit pmode) + limit 16—19
	db 0			; base high
		; 16-bit daya segment
	dw 0xFFFF		; limit 0—15
	dw 0			; base 0—15
	db 0			; base 16—23
	db 10010010b	; access (present, ring 0, data, not exec, direction 0, read, access 0)
	db 00001111b	; granularity (1B pages, 16-bit pmode) + limit 16—19
	db 0			; base high

; GDT Descriptor
gdtd:
	dw gdtd - gdt - 1	; size of GDT
	dd gdt