// Minimum No of days to M bouqets

// Soln: binary search
// Intuition: the input data is 
// monotonic in nature

bool check(vector<int>& arr, int m, int k, int mid)
{
	int bouquets = 0;
	int count = 0
	
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] <= mid)
			count++;
		else
			bouquets = count/ k;
			count = 0;
	}

	bouquets = count / k;

	return bouquets >= m;

}

int minDays(vector<arr>& arr, int m, int k)
{
	int lo = 1;
	int high = *max_element(arr.begin(), arr.end());
	int res  -1;

	while (lo <= high) {
		
		int mid = (lo + high) / 2;

		if (check(arr, m, k, mid)) {
			hi = mid - 1;
			res = mid;
		} else {
			lo = mid + 1;
		}
		 
	}

	return res;
}


























