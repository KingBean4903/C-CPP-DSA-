// Floor in a Sorted Array

int floor(vector<int>& arr, int x) 
{
	int high = arr.size();
	int low = 0;
	int ans = -1;

	while(low <= high)
		int mid = (low + mid) / 2;
		if (arr[mid] > x)
			high = mid - 1;
		else if (arr[mid] <= x)
			ans = mid;
			low = mid + 1;

	return ans;

}
