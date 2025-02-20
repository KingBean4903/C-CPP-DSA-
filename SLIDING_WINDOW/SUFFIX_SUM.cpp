#include <bits/stdc++.h>
using namespace std;

vector<int> createSuffixSum(vector<int>& arr, int n)
{
	
	vector<int> suffixArray(n, 0);

	suffixArray[n - 1] = arr[ n -1];

	for (int i = n - 2; i >= 0; i--)
			suffixArray[i] = suffixArray[i + 1] + arr[i];

	return suffixArray;

}





int main()
{
	
	vector<int> arr = { 10, 14, 16, 20 };
	int N = arr.size();
	vector<int> suffixSum = createSuffixSum(arr, N);
	
	cout << "Create suffix sum \n";
	for (int i = 0; i < N; i++)
			cout << suffixSum[i] << " ";

	return 0;

}
