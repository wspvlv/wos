[bits 32]

extern isrh

%macro isrnoerror	1

global isr%1:
isr%1:
	push 0
	push %1
	jmp isr_common

%endmacro

%macro isrerror	1

global isr%1:
isr%1:
	push %1
	jmp isr_common

%endmacro

isrnoerror 0
isrnoerror 1
isrnoerror 2
isrnoerror 3
isrnoerror 4
isrnoerror 5
isrnoerror 6
isrnoerror 7
isrerror 8
isrnoerror 9
isrerror 10
isrerror 11
isrerror 12
isrerror 13
isrerror 14
isrnoerror 15
isrnoerror 16
isrerror 17
isrnoerror 18
isrnoerror 19
isrnoerror 20
isrerror 21
isrnoerror 22
isrnoerror 23
isrnoerror 24
isrnoerror 25
isrnoerror 26
isrnoerror 27
isrnoerror 28
isrnoerror 29
isrnoerror 30
isrnoerror 31
isrnoerror 32
isrnoerror 33
isrnoerror 34
isrnoerror 35
isrnoerror 36
isrnoerror 37
isrnoerror 38
isrnoerror 39
isrnoerror 40
isrnoerror 41
isrnoerror 42
isrnoerror 43
isrnoerror 44
isrnoerror 45
isrnoerror 46
isrnoerror 47
isrnoerror 48
isrnoerror 49
isrnoerror 50
isrnoerror 51
isrnoerror 52
isrnoerror 53
isrnoerror 54
isrnoerror 55
isrnoerror 56
isrnoerror 57
isrnoerror 58
isrnoerror 59
isrnoerror 60
isrnoerror 61
isrnoerror 62
isrnoerror 63
isrnoerror 64
isrnoerror 65
isrnoerror 66
isrnoerror 67
isrnoerror 68
isrnoerror 69
isrnoerror 70
isrnoerror 71
isrnoerror 72
isrnoerror 73
isrnoerror 74
isrnoerror 75
isrnoerror 76
isrnoerror 77
isrnoerror 78
isrnoerror 79
isrnoerror 80
isrnoerror 81
isrnoerror 82
isrnoerror 83
isrnoerror 84
isrnoerror 85
isrnoerror 86
isrnoerror 87
isrnoerror 88
isrnoerror 89
isrnoerror 90
isrnoerror 91
isrnoerror 92
isrnoerror 93
isrnoerror 94
isrnoerror 95
isrnoerror 96
isrnoerror 97
isrnoerror 98
isrnoerror 99
isrnoerror 100
isrnoerror 101
isrnoerror 102
isrnoerror 103
isrnoerror 104
isrnoerror 105
isrnoerror 106
isrnoerror 107
isrnoerror 108
isrnoerror 109
isrnoerror 110
isrnoerror 111
isrnoerror 112
isrnoerror 113
isrnoerror 114
isrnoerror 115
isrnoerror 116
isrnoerror 117
isrnoerror 118
isrnoerror 119
isrnoerror 120
isrnoerror 121
isrnoerror 122
isrnoerror 123
isrnoerror 124
isrnoerror 125
isrnoerror 126
isrnoerror 127
isrnoerror 128
isrnoerror 129
isrnoerror 130
isrnoerror 131
isrnoerror 132
isrnoerror 133
isrnoerror 134
isrnoerror 135
isrnoerror 136
isrnoerror 137
isrnoerror 138
isrnoerror 139
isrnoerror 140
isrnoerror 141
isrnoerror 142
isrnoerror 143
isrnoerror 144
isrnoerror 145
isrnoerror 146
isrnoerror 147
isrnoerror 148
isrnoerror 149
isrnoerror 150
isrnoerror 151
isrnoerror 152
isrnoerror 153
isrnoerror 154
isrnoerror 155
isrnoerror 156
isrnoerror 157
isrnoerror 158
isrnoerror 159
isrnoerror 160
isrnoerror 161
isrnoerror 162
isrnoerror 163
isrnoerror 164
isrnoerror 165
isrnoerror 166
isrnoerror 167
isrnoerror 168
isrnoerror 169
isrnoerror 170
isrnoerror 171
isrnoerror 172
isrnoerror 173
isrnoerror 174
isrnoerror 175
isrnoerror 176
isrnoerror 177
isrnoerror 178
isrnoerror 179
isrnoerror 180
isrnoerror 181
isrnoerror 182
isrnoerror 183
isrnoerror 184
isrnoerror 185
isrnoerror 186
isrnoerror 187
isrnoerror 188
isrnoerror 189
isrnoerror 190
isrnoerror 191
isrnoerror 192
isrnoerror 193
isrnoerror 194
isrnoerror 195
isrnoerror 196
isrnoerror 197
isrnoerror 198
isrnoerror 199
isrnoerror 200
isrnoerror 201
isrnoerror 202
isrnoerror 203
isrnoerror 204
isrnoerror 205
isrnoerror 206
isrnoerror 207
isrnoerror 208
isrnoerror 209
isrnoerror 210
isrnoerror 211
isrnoerror 212
isrnoerror 213
isrnoerror 214
isrnoerror 215
isrnoerror 216
isrnoerror 217
isrnoerror 218
isrnoerror 219
isrnoerror 220
isrnoerror 221
isrnoerror 222
isrnoerror 223
isrnoerror 224
isrnoerror 225
isrnoerror 226
isrnoerror 227
isrnoerror 228
isrnoerror 229
isrnoerror 230
isrnoerror 231
isrnoerror 232
isrnoerror 233
isrnoerror 234
isrnoerror 235
isrnoerror 236
isrnoerror 237
isrnoerror 238
isrnoerror 239
isrnoerror 240
isrnoerror 241
isrnoerror 242
isrnoerror 243
isrnoerror 244
isrnoerror 245
isrnoerror 246
isrnoerror 247
isrnoerror 248
isrnoerror 249
isrnoerror 250
isrnoerror 251
isrnoerror 252
isrnoerror 253
isrnoerror 254
isrnoerror 255

global isr
isr:
%assign i 0 
%rep    256 
    dd isr%+i ; use DQ instead if targeting 64-bit
%assign i i+1 
%endrep

isr_common:
	pusha

	xor eax, eax
	mov ax, ds
	push eax
	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax

	push esp

	call isrh

	add esp, 4
	pop eax
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	popa
	add esp, 8
	iret
