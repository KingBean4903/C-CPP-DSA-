#include <string.h>
#include <stdio.h>

int main() 
{
	
	int size;

	char str1[]  = "Autobots, Rollout!!";
	char str2[] = "prime";
	
	size = strcspn(str1, str2);

	printf("The unmatched characters before first matched character %d\n", size);

	return 0;
	

}
