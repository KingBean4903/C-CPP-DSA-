// Allocate minimum pages


bool check(vector<int>& arr, int k, int mid)
{
	int cnt = 0;
	int pageSum = 0;
	for (int i = 0; i < arr.size(); i++)
		if (pageSum + arr[i] >= mid)
			cnt++;
			pageSum = arr[i];
		else
			pageSum += arr[i];


	return (cnt <= k);


}


int minPages(vector<int>& arr, int k)
{
	
	int lo = *max_element(arr.begin(), arr.end());
	int hi = accumulate(arr.begin(). arr.end(), 0);
	int res = -1;

	while(lo <= hi) 
	{
		int mid = lo + (hi - lo) / 2;
		if (check(arr, k, mid))
		{
			res = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}

	}

	return res;
}





























