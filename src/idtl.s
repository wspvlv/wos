[bits 32]

global idtl
idtl:
	push ebp
	mov ebp, esp
	mov eax, [ebp+8]
	lidt [eax]
	mov esp, ebp
	pop ebp
	ret
