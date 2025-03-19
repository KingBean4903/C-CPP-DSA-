// Minimum Subarray sum

int smallestSubarraySum(int arr[], int n, int x)
{
	int low = 0,  high = n - 1; 
	int ans = INT_MAX;

	while (low < high)
	{
		int mid = (low + high) / 2;
		if (f(mid, arr, n, x))
		{
			ans = mid;
			high = mid - 1;
		} else {

			low = mid + 1;
		}
	}

	return (ans == INT_MAX) ? 0 : ans;
}

bool f(int mid, int arr[], int n, int x)
{
	
	int i = 0, j = 0, sum = 0;
	bool issubarray = false;
	
	for (j = 0; j < mid; j++ )
		sum += arr[j];

	while (j < n){
 	
		if (sum > x) {
			issubarray = true;
		}
		sum -= arr[i];
		sum += arr[j];
		i++;
		j++;
	}
	if (sum > x)
		issubarray = true;
	
	return issubarray;



	
}


















