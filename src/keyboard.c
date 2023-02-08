/* #include <wl/bit.h> */
#include "keyboard.h"
#include "pic.h"



char scanCode[] = {
	0x0, 0x0, '1', '2', '3', '4', '5', '6',
	'7', '8', '9', '0', '-', '=', 0x0,'\v',
	'q', 'w', 'e', 'r', 't', 'y', 'u', 'i',
	'o', 'p', '[', ']','\n', 0x0, 'a', 's',
	'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',
   '\'', '`', 0x0,'\\', 'z', 'x', 'c', 'v',
	'b', 'n', 'm', ',', '.', '/', 0x0, '*',
	0x0, ' ', 0x0, '!', '@', '#', '$', '%',
	'^', '&', '*', '(', ')', 0x0, 0x0, '7',
	'8', '9', '-', '4', '5', '6', '+', '1',
	'2', '3', '0', '.', 0x0, 0x0, 0x0, '_',
	'+',

	0x0, 0x0, '!', '@', '#', '$', '%', '^',
	'&', '*', '(', ')', '_', '+', 0x0, 0x0,
	'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I',
	'O', 'P', '{', '}','\n', 0x0, 'A', 'S',
	'D', 'F', 'G', 'H', 'J', 'K', 'L', ':',
	'"', '~', 0x0, '|', 'Z', 'X', 'C', 'V',
	'B', 'N', 'M', '<', '>', '?', 0x0, '*',
	0x0, ' ', 0x0, '!', '@', '#', '$', '%',
	'^', '&', '*', '(', ')', 0x0, 0x0, '7',
	'8', '9', '-', '4', '5', '6', '+', '1',
	'2', '3', '0', '.', 0x0, 0x0, 0x0, '_',
	'+',
};
/* int i = sizeof(scanCode); */

#define KEY_BACKSPACE	0x0E
#define KEY_LSHIFT		0x2A
#define KEY_RSHIFT		0x36
#define KEY_CAPSLOCK	0x3A

#define SHIFT_MASK		0x01
#define CTRL_MASK		0x02
#define ALT_MASK		0x04
#define SUPER_MASK		0x08
#define CAPSLOCK_MASK	0x10

U8f mod = 0;

void keyboardHandler() {
	/* inb(0x60); */
	U8f c = inb(0x60);
	if_unlikely(c == KEY_BACKSPACE)
		cc();
	if_unlikely(c == KEY_LSHIFT || c == KEY_RSHIFT)
		mod |= SHIFT_MASK;
	if_unlikely(c == KEY_CAPSLOCK)
		mod ^= CAPSLOCK_MASK;
	else if_likely(c < 0x80) {
		pc(scanCode[(mod&(SHIFT_MASK|CAPSLOCK_MASK)*sizeof(scanCode)/2)+c]);
		mod &= ~SHIFT_MASK;
	}
}
