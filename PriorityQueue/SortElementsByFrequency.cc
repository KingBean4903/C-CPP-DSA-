// Sort elements by frequency

vector<int> sort(vector<int>& arr)
{
	int n = arr.size();

	priority_queue<vector<int>> pq;

	unordered_map<int, int> map;

	for (auto i : arr)
		map[i]++;
	
	for (int val : mp)
	{
		pq.push({ val.second, -val.first   });
	}

	vector<int> res;

	while (!pq.empty())
	{
		int freq = pq.top()[0];
		int ele = pq.top()[1];
		pq.pop();
		for (int i = freq -1; i >=0 ; i--)
		{
			res.push_back(ele);
		}
	}

	return res;

}
























