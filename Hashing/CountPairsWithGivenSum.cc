// 2 Sum - Count pairs with given sum

int pairs(vector<int>& arr, int target)
{
	int n = arr.size();
	unordered_map<int, int> mp;
	
	int count = 0;

	for (int i = 0; i < arr.size(); i++)
	{
		if (mp.find(target - arr[i]) != mp.end())
		{
			cnt += mp[target - arr[i]];
		}
	
		mp[arr[i]]++;
	}

	return count;
}






