// Floor in a sorted array


int floor(vector<int>& arr, int x)
{
	
	int ans = -1;
	int low = 0;
	int high = arr.size() - 1;

	while(low <= high)
	{
		int mid = (low + high) / 2;
		if (arr[mid] >= x) {
			high = mid - 1;
		} else {
			ans = mid;
			low = mid + 1;
		}
	}
	return ans;
}






















