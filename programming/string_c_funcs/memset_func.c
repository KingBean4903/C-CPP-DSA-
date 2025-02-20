#include <string.h>
#include <stdio.h>

int main() 
{
	
	char str[50] = "Iron Hide: Fuck Deceptorcon.";

	printf("Before memset: %s\n", str);

	memset(str + 12, '#' , 2*sizeof(char));

	printf("After memset %s\n", str);


	return 0;


}
