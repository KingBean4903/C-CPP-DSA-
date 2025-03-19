// Aggressive cows

bool check(vector<int>& arr, int k, int dist)
{
	int cnt = 0;
	int prev = stalls[0];
	for (int i = 0; i < stalls.size(); i++)
		if (stalls[i] - prev >= dist)
			cnt++;
			prev = stalls[i];
	
	retur (cnt >= k);
}



int aggressiveCows(vector<int>& stalls, int k)
{
	
	//sort 
	sort(stalls.begin(), stalls.end());
	int res = 0;
	int lo = 1;
	int hi = stalls.back() - stalls[0];

	while (lo < hi)
	{
		int mid = lo + (hi - lo)/ 2;

		if (check(stalls, k, mid))
		{
			res = mid;
			lo = mid + 1;
		} else
		{
			hi = mid - 1;
		}
	}

	return res;
}


