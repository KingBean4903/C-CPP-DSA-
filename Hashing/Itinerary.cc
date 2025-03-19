// Find Itinerary from a given
// list of tickets

vector<vector<string>> itinerary(vector<vector<string>> & arr)
{
	map<string, string> dataSet;
	for (auto x: arr)
		dataSet[x[0]] = x[1];

	
	map<string, string> rvsSet;
	for (auto x: arr)
		dataSet[x[1]] = x[1];
	
	string start;

	for (int i = 0; i < arr.size(); i++)
		if (rvsSet.count(arr[i][0]) == 0 )
			start = arr[i][0];

	vector<vector<string>> ans;

	auto it = dataSet.find(start);
	while (it != dataSet.end())
	{
		ans.push_back({ it->first, it->second  });
		it = dataSet.find(it->second);
	}

	return ans;
}
