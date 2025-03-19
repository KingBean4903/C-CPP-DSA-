// Most frequent element in array

int frequent(int arr[], int n)
{
	
	unordered_set<int, int> freq;
	for (int i = 0; i< n; i++)
		freq[arr[i]]++;

	int max_count = 0;
	int res = -1;

	for (auto x: freq)
	{
		if (max_count < i.second)
			res = i.first;
			max_count = i.second
	}

	return res;

}

















