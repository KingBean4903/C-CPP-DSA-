#include <stdio.h>
#include <string.h>

int main() 
{
	
	char s1[] = "Autobots rollout";
	char s2[] = "bee";
	char *r;

	r = strpbrk(s1, s2);

	if (r) 
			printf("First matching character: %c\n", *r);
	else 
			printf("Character not found");

	return 0;
}
