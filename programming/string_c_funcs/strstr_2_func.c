#include <stdio.h>
#include <string.h>

int main()
{

	char s1[] = "I'm a deceptorcon";
	char s2[] = "deceptorcon";
	char *p;
	
	p = strstr(s1, s2);


	if (p) 
	{
		strcpy(p, "Autobot");
		printf ("%s", s1);
	} 
	else 
		printf("String not found\n");



	return 0;


}
