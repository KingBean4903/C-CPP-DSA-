/* 
 * X86Args.h - Variable-length arguments macro for IA32
*/
#include <stdint.h>

#ifndef x86ARGS
#define	X86ARGS

#define Args(arg) \
	unsigned int _x; \
	__asm("mov %%ebp,%0":"=r"(_x)); \
	_x += 8; \
	arg = (void *)(uintptr_t) _x

#endif
