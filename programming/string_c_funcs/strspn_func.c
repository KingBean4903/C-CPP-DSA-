#include <string.h>
#include <stdio.h>

int main() 
{
	
	char s1[] = "Auto bots, Rollout!!";
	char s2[] = "bots";
	
	int len = strspn("bots auto", "bots");
	
	printf ("Segment matching length: %d\n", len);


	return 0;
	
}
