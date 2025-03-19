// Two Sum - Pair Closest to 0

// Binary search + sorting
int closestPair(vector<int>& arr)
{
	
	int n = arr.size();
	
	sort (arr.begin(), arr.end());

	int res = INT_MAX;

	for (int i = 0; i < n; i++)
	{
		int x = arr[i];
		int left = i + 1;
		int right = n - 1;
		int mid = (left + right) / 2;
		
		while (left <= right) {

		int curr = arr[mid] + x;

		if (curr == 0)
			return 0;

		if (abs(curr) < abs(res))
			res = curr;

		if (curr < 0)
			left = mid + 1;
		else
			right = mid - 1;
		}
	}
	return res;
}
























