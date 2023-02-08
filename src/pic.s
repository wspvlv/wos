global outb
outb:
    [bits 32]
    mov dx, [esp + 4]
    mov al, [esp + 8]
    out dx, al
    ret

global inb
inb:
    [bits 32]
    mov dx, [esp + 4]
    xor eax, eax
    in al, dx
    ret

global sti
sti:
    [bits 32]
    sti
    ret

global cli
cli:
    [bits 32]
    cli
    ret
