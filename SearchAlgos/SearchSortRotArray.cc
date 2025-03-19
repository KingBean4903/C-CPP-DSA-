// Search in a sorted rotatedd array


int search(vector<int>& arr, int key)
{

	int lo = 0;
	int hi = arr.size();

	while (lo < hi)
	{
		int mid = lo + (hi - lo) / 2;
		
		if (arr[mid] == key)
			return mid;

		if (arr[mid] > arr[lo])
		{
			if (key >= arr[lo] && key <= arr[mid])
				hi = mid - 1;
			else 
				low = mid + 1;

		} else {
		
			if (arr[mid] < arr[hi])
			{
			  if (key >= arr[mid] && key < arr[hi])
					lo = mid + 1;
			  else 
			  		 hi = mid - 1
		}
		 
	}
	return -1;
}
