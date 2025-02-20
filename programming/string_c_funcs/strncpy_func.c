#include <stdio.h>
#include <string.h>

int main()
{
	
	char src[] = "Hello, Nerds";
	char dest[20];

	strncpy(dest, src, 5);
	dest[5] = '\0';

	printf("Destination string %s\n ", dest);

	return 0;
}
