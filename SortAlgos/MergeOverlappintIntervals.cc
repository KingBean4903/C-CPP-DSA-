// Merge overlapping intervals

vector<vector<int>> mergeOverlap(vector<vector<int>>& arr)
{
	sort(arr.begin(), arr.end());
	
	vector<int> res;
	res.push_back(arr[0]);

	for (int i = 0; i < arr.size(); i++)
	{
		vector<int> last = res.back();
		vector<int> curr = arr[i];
		
		if (curr[0] <= last[1])
		{ 
			last[1] = max(curr[1], last[1]);
		} else
		{
			res.push_back(arr[i]);
		}

	} 

	return res;

}
