#include <string.h>
#include <stdio.h>

int main() 
{
	
	char s1[] = "Autobots, Rollout!!";
	char s2[] = "bot";
	char *p;

	p = strstr (s1, s2);

	if (p) {
	
			printf("String found \n");
			printf ("First occurrence of string %s in %s is %s", s2, s1,  p);
	} 
	else 
		printf("String not found\n");



	return 0;


}
