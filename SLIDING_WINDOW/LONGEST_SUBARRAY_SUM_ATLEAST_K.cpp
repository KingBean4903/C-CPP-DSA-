#include <bits/stdc++.h>
using namespace std;

int maxSumWithK(int arr[], int k, int n)
{
	
	int maxSum[n];
	maxSum[0] = arr[0];

	int currSum = arr[0];
	for (int i = 0; i < n; i++){
		currSum = max(arr[i], currSum + arr[i]);
		maxSum[i] = currSum;
		
	}

	

	int sum = 0;
	for (int i = 0; i < k; i++){ 
			
				sum += arr[i];

	}

	int result = sum;
	for (int i = 0; i < n; i++) {
	

		sum  = sum + arr[i] - arr[i - k];
			
		result = max(result, sum);

		result = max(result, sum + maxSum[i-k]);
	}


	return result;



}

int main()
{
	
	int arr[] = {1, 2, 3, -10, -3};
	int k = 4;
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << maxSumWithK(arr, k, n);

	return 0;
}
