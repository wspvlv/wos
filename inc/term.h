#ifndef TERM_H
#define TERM_H	1



#include <wl/types.h>



/**
 * \brief	Print Character
 * \def		pc(c)
 * \param	c	Character to be printed
 * 
 * Prints the character \p a on the screen
 */
#define pc(c)\
	*tbCursor = (U16l)(c) | (U16l)0x0F00;\
	tbCursor++

/**
 * \brief	Clear Character
 * \def		cc(c)
 * \param	c	Character to be cleared
 * 
 * Clears the last printed character in the buffer
 */
#define cc()\
	tbCursor--;\
	pc('\0')



extern U16l* tbCursor;



/**
 * \brief	Print Characters
 * \fn		void pc(char* c)
 * \param	c	Pointer to a string of characters
 * \param	n	Number of characters
 * 
 * Prints `n` number of characters in a string \p a on the screen
 */
extern void pcs(char* c, U16f n);

/**
 * \brief	Print String
 * \fn		void ps(char* c)
 * \param	s	Pointer to a null-terminated character string
 * 
 * Prints the null-terminated characters string pointed by `s`
 */
extern void ps(char* c);

/**
 * \brief	Clear Screen
 * \fn		void cs()
 * 
 * Clears the screen
 */
extern void cs();



#endif
