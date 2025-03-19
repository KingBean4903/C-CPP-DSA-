// K-th Distinct element among unique
// elements in an array

int distinct(vector<int>& arr, int k)
{
	int n = arr.size();
	unordered_map<int, int> map;

	for (int i = 0; i < n; i++)
		map[arr[i]]++;
	
	int dist_count = 0;
	for (int i =0; i< n; i++)
	{
		if (map[arr[i]] == 1)
			dist_count++;
		if (dist_count ==k )
			return a[i];

	}
	return -1;
}	




















