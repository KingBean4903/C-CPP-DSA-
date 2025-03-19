#include <iostream>

template<typename T> void bubbleSort(T arr[], int n)
{
	
	for (int i = 0; i < n; i++)
		for (int j = n - 1; i < j; j--)
				if (arr[j] < arr[j - 1])
						std::swap(arr[j], arr[j - 1]);

}


int main()
{
	int arr[] =  {10, 50, 90, 33, 22};

	char name[] = {'K','a','r','i','u','k','i','k','N','A','N','G','O'};
	int charLen = sizeof(name) / sizeof(name[0]);

	int n = sizeof(arr) / sizeof(arr[0]);

	bubbleSort<char>(name, charLen);
	
	for (int i = 0; i < n; i++)
			std::cout << name[i] << " ";
	std::cout << std::endl;

	return 0;

}
