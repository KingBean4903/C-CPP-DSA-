// Check if 2 arrays are equal

bool areEqual(vector<int>& a, vector<int>& b)
{
	int n = a.size();
	int m = b.size();

	if (n < m)
		return false;
	
	unordered_map<int, int> hashMap;
	for (int i = 0; i < n; i++)
		hashMap[a[i]]++;

	for (int i = 0; i < m; i++)
		if (hashMap.find(b[i]) == hashMap.end())
			return false;

		if (hashMap[b[i]] == 0)
			return false;

		mp[b[i]]--;

	return true;
}





















