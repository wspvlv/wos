
/home/wispy/prj/wos/bin/i686-elf/idts.o:     file format elf32-i386


Disassembly of section .text:

00000000 <isr_stub_table>:
   0:	80 00 00             	addb   $0x0,(%eax)
   3:	00 86 00 00 00 8c    	add    %al,-0x74000000(%esi)
   9:	00 00                	add    %al,(%eax)
   b:	00 92 00 00 00 98    	add    %dl,-0x68000000(%edx)
  11:	00 00                	add    %al,(%eax)
  13:	00 9e 00 00 00 a4    	add    %bl,-0x5c000000(%esi)
  19:	00 00                	add    %al,(%eax)
  1b:	00 aa 00 00 00 b0    	add    %ch,-0x50000000(%edx)
  21:	00 00                	add    %al,(%eax)
  23:	00 b6 00 00 00 bc    	add    %dh,-0x44000000(%esi)
  29:	00 00                	add    %al,(%eax)
  2b:	00 c2                	add    %al,%dl
  2d:	00 00                	add    %al,(%eax)
  2f:	00 c8                	add    %cl,%al
  31:	00 00                	add    %al,(%eax)
  33:	00 ce                	add    %cl,%dh
  35:	00 00                	add    %al,(%eax)
  37:	00 d4                	add    %dl,%ah
  39:	00 00                	add    %al,(%eax)
  3b:	00 da                	add    %bl,%dl
  3d:	00 00                	add    %al,(%eax)
  3f:	00 e0                	add    %ah,%al
  41:	00 00                	add    %al,(%eax)
  43:	00 e6                	add    %ah,%dh
  45:	00 00                	add    %al,(%eax)
  47:	00 ec                	add    %ch,%ah
  49:	00 00                	add    %al,(%eax)
  4b:	00 f2                	add    %dh,%dl
  4d:	00 00                	add    %al,(%eax)
  4f:	00 f8                	add    %bh,%al
  51:	00 00                	add    %al,(%eax)
  53:	00 fe                	add    %bh,%dh
  55:	00 00                	add    %al,(%eax)
  57:	00 04 01             	add    %al,(%ecx,%eax,1)
  5a:	00 00                	add    %al,(%eax)
  5c:	0a 01                	or     (%ecx),%al
  5e:	00 00                	add    %al,(%eax)
  60:	10 01                	adc    %al,(%ecx)
  62:	00 00                	add    %al,(%eax)
  64:	16                   	push   %ss
  65:	01 00                	add    %eax,(%eax)
  67:	00 1c 01             	add    %bl,(%ecx,%eax,1)
  6a:	00 00                	add    %al,(%eax)
  6c:	22 01                	and    (%ecx),%al
  6e:	00 00                	add    %al,(%eax)
  70:	28 01                	sub    %al,(%ecx)
  72:	00 00                	add    %al,(%eax)
  74:	2e 01 00             	add    %eax,%cs:(%eax)
  77:	00 34 01             	add    %dh,(%ecx,%eax,1)
  7a:	00 00                	add    %al,(%eax)
  7c:	3a 01                	cmp    (%ecx),%al
	...

00000080 <isr_stub_0>:
  80:	e8 fc ff ff ff       	call   81 <isr_stub_0+0x1>
  85:	cf                   	iret   

00000086 <isr_stub_1>:
  86:	e8 fc ff ff ff       	call   87 <isr_stub_1+0x1>
  8b:	cf                   	iret   

0000008c <isr_stub_2>:
  8c:	e8 fc ff ff ff       	call   8d <isr_stub_2+0x1>
  91:	cf                   	iret   

00000092 <isr_stub_3>:
  92:	e8 fc ff ff ff       	call   93 <isr_stub_3+0x1>
  97:	cf                   	iret   

00000098 <isr_stub_4>:
  98:	e8 fc ff ff ff       	call   99 <isr_stub_4+0x1>
  9d:	cf                   	iret   

0000009e <isr_stub_5>:
  9e:	e8 fc ff ff ff       	call   9f <isr_stub_5+0x1>
  a3:	cf                   	iret   

000000a4 <isr_stub_6>:
  a4:	e8 fc ff ff ff       	call   a5 <isr_stub_6+0x1>
  a9:	cf                   	iret   

000000aa <isr_stub_7>:
  aa:	e8 fc ff ff ff       	call   ab <isr_stub_7+0x1>
  af:	cf                   	iret   

000000b0 <isr_stub_8>:
  b0:	e8 fc ff ff ff       	call   b1 <isr_stub_8+0x1>
  b5:	cf                   	iret   

000000b6 <isr_stub_9>:
  b6:	e8 fc ff ff ff       	call   b7 <isr_stub_9+0x1>
  bb:	cf                   	iret   

000000bc <isr_stub_10>:
  bc:	e8 fc ff ff ff       	call   bd <isr_stub_10+0x1>
  c1:	cf                   	iret   

000000c2 <isr_stub_11>:
  c2:	e8 fc ff ff ff       	call   c3 <isr_stub_11+0x1>
  c7:	cf                   	iret   

000000c8 <isr_stub_12>:
  c8:	e8 fc ff ff ff       	call   c9 <isr_stub_12+0x1>
  cd:	cf                   	iret   

000000ce <isr_stub_13>:
  ce:	e8 fc ff ff ff       	call   cf <isr_stub_13+0x1>
  d3:	cf                   	iret   

000000d4 <isr_stub_14>:
  d4:	e8 fc ff ff ff       	call   d5 <isr_stub_14+0x1>
  d9:	cf                   	iret   

000000da <isr_stub_15>:
  da:	e8 fc ff ff ff       	call   db <isr_stub_15+0x1>
  df:	cf                   	iret   

000000e0 <isr_stub_16>:
  e0:	e8 fc ff ff ff       	call   e1 <isr_stub_16+0x1>
  e5:	cf                   	iret   

000000e6 <isr_stub_17>:
  e6:	e8 fc ff ff ff       	call   e7 <isr_stub_17+0x1>
  eb:	cf                   	iret   

000000ec <isr_stub_18>:
  ec:	e8 fc ff ff ff       	call   ed <isr_stub_18+0x1>
  f1:	cf                   	iret   

000000f2 <isr_stub_19>:
  f2:	e8 fc ff ff ff       	call   f3 <isr_stub_19+0x1>
  f7:	cf                   	iret   

000000f8 <isr_stub_20>:
  f8:	e8 fc ff ff ff       	call   f9 <isr_stub_20+0x1>
  fd:	cf                   	iret   

000000fe <isr_stub_21>:
  fe:	e8 fc ff ff ff       	call   ff <isr_stub_21+0x1>
 103:	cf                   	iret   

00000104 <isr_stub_22>:
 104:	e8 fc ff ff ff       	call   105 <isr_stub_22+0x1>
 109:	cf                   	iret   

0000010a <isr_stub_23>:
 10a:	e8 fc ff ff ff       	call   10b <isr_stub_23+0x1>
 10f:	cf                   	iret   

00000110 <isr_stub_24>:
 110:	e8 fc ff ff ff       	call   111 <isr_stub_24+0x1>
 115:	cf                   	iret   

00000116 <isr_stub_25>:
 116:	e8 fc ff ff ff       	call   117 <isr_stub_25+0x1>
 11b:	cf                   	iret   

0000011c <isr_stub_26>:
 11c:	e8 fc ff ff ff       	call   11d <isr_stub_26+0x1>
 121:	cf                   	iret   

00000122 <isr_stub_27>:
 122:	e8 fc ff ff ff       	call   123 <isr_stub_27+0x1>
 127:	cf                   	iret   

00000128 <isr_stub_28>:
 128:	e8 fc ff ff ff       	call   129 <isr_stub_28+0x1>
 12d:	cf                   	iret   

0000012e <isr_stub_29>:
 12e:	e8 fc ff ff ff       	call   12f <isr_stub_29+0x1>
 133:	cf                   	iret   

00000134 <isr_stub_30>:
 134:	e8 fc ff ff ff       	call   135 <isr_stub_30+0x1>
 139:	cf                   	iret   

0000013a <isr_stub_31>:
 13a:	e8 fc ff ff ff       	call   13b <isr_stub_31+0x1>
 13f:	cf                   	iret   
