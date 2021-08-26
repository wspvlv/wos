[bits 32]

GLOBAL ob
ob:
	mov eax, esi
	mov edx, edi
	out dx, al
	ret

GLOBAL ib
ib:
	mov edx, edi
	in al, dx
	ret

	