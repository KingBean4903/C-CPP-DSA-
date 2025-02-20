#include <string.h>
#include <stdio.h>

int main() { 

	char str1[50] = "Fun with ";
	char str2[] = "Autobots";

	strncat(str1, str2, 4);

	printf("%s\n", str1);

	return 0;

}
