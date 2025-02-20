#include <bits/stdc++.h>
using namespace std;

void printFirstNegativeInt(int arr[], int n, int k)
{


	deque<int> Di;

	int i;

	for (int i = 0; i < k; i++)

			if (arr[i] < 0)
				Di.push_back(i);


	for (; i < n; i++)
	{
		
		if (!Di.empty())
			cout << arr[Di.front()] << " ";

		else 
			cout << "0" << " ";


		while ((!Di.empty()) && Di.front() < (i - k + 1))
		{
				Di.pop_front();
		}

		if (arr[i] < 0)
				Di.push_back(i);
	
	}

	if (!Di.empty())
			cout << arr[Di.front()] << " ";
	else 
		 	cout << "0" << " ";
	

}

int main() 
{

	int arr[] = { 12, -1, -7, 8, -15, 30, 16, 28 };

	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 2;

	printFirstNegativeInt(arr, n, k);

	return 0;

}
