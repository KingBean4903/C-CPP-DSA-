#include <unistd.h>
#include "x86args.h"

#define putchar(x)     write(1, chardup2(x), 1)

char *chardup2(const char c) 
{

	static char buf[2];
	char *p;

	p = buf;

	*p++ = c;

	*p-- = 0;
	
	return buf;
}


unsigned int strlen2(const char *str) 
{

	unsigned int n;
	const char *p;

	for (p=str, n=0; *p; p++, n++);

	return n;

}


int puts2(const char *str) {
	
	unsigned int n;

	n = strlen2(str);
	if (n < 1)
		return -1;

	return write(1, str, n);
}

int printf2(const char *fmt, ...) {

		unsigned int *p;
		Args(p);

		puts2((void *)(uintptr_t)*p);
		p += 4;
		puts2((void *)(uintptr_t)*p);

		return 0;
}


int main() 
{

	printf2("%s\n", "ARG 2\n");

	return 0;
}
