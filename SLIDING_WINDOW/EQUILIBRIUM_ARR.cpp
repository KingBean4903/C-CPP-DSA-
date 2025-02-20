#include <bits/stdc++.h>
using namespace std;

int findEquilibrium(vector<int>& arr)
{
	
	int n = arr.size();

	vector<int> prefSum(n, 0);
	vector<int> suffSum(n, 0);

	suffSum[n - 1] = arr[n - 1];
	for (int i = n - 2; i >= 0; i--)
			suffSum[i] = arr[i] + suffSum[i + 1];

	prefSum[0] = arr[0];
	for (int i = 1; i < n; i++)
			prefSum[i] = arr[i] + prefSum[i - 1];

	for (int i = 0; i < n; i++)
			if (prefSum[i] == suffSum[i])
					return i;

	 return -1;
}



int main()
{
	vector<int> arr = { -7, 1, 5, 2, -4, 3, 0 };
	

	cout << findEquilibrium(arr) << " \n";
	return 0;
}
