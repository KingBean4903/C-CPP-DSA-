#include <string.h>
#include <stdio.h>


void printArray(int arr[], int n)
{
		for (int i = 0; i < n; i++)
				printf("%d\n",arr[i]);
}


int main() 
{
	
	int n = 10;

	int arr[n];

	// memset(arr, 0, n*sizeof(arr[0]));
	
	memset(arr, 10, n*sizeof(arr[0]));

	printf("Array after memset() \n");
	
	printArray(arr, n);


	return 0;





}
