#include <stdio.h>
#include <string.h>

int main() 
{
	
	char str1[] = "Deceptorcon";
	char str2[] = "Autobot";

	puts("Str1 before memcpy");
	puts(str1);

	memcpy(str1, str2, sizeof(str2));

	puts("Str1 after memcpy()");
	puts(str2);

	return 0;

}
