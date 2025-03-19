// Largest sum subarray of size at least k

// Solution : use kadane's algorithm
// and Sliding window technique

int subarray(vector<int>& arr, int k)
{
	int n = arr.size();
	vector<int> maxSum(n); 
	maxSum[0] = arr[0];

	int currMax = arr[0];
	for (int i = 1; i < n; i++)
		currMax = max(arr[i], currMax + arr[i]);
		maxSum[i] = currMax;
	
	int sum = 0;
	for (int i = 0; i < k; i++)
		sum += arr[i];

	int result = sum;
	for (int i = k; i < n; i++) {
		sum = sum + arr[i] - arr[i-k];

		result = max(sum, result);

		result = max(result, maxSum[i-k] + sum);
	}
	
	return result;














}



























