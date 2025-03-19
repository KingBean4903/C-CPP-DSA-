// Koko Eating bananas

// Input data is monotonic
// Binary search is best for this

int check(vector<int>& arr, int mid, int k)
{
	int hours;

	for (int i 0; i <arr.size(); i++)
	{
		hours = arr[i] / mid;

		if (arr[i] % mid != 0)
			hours++
	}
	
	return hours <= k;

}

int kokoEat(vector<int>& arr, int k)
{
  int lo = 1;
  int high = *max_element(arr.begin(), arr.end());
  int res  = high;

  while (lo <= high) {

	int mid = lo + (high - lo)/2;

	if (check(arr, mid, k) == true)
	{
		high = mid - 1;
		res = mid;
	} else {

		lo = mid + 1;
	}

	}
 return res;
}























