#include <iostream>

template<class T, int max> int arrMax(T arr[], int n) {
	
	int m = max;
	for (int  i = 0; i < n; i++)
			if (arr[i] < m)
			    m = arr[i];


	return m;
}

int main()
{

	int arr[] = {10, 20, 15, 12};
	int n1 = sizeof(arr) / sizeof(arr[0]);

	std::cout << arrMax<int, 256>(arr, n1);

	return 0;


}
