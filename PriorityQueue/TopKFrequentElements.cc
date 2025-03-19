// Top K Frequent elements in an array


vector<int> topKElements(vector<int>& arr, int k)
{
	
	unordered_map<int, int> mp;
	for (int i :  arr) {
		mp[i]++
	}

	priority_queue<pair<int, int>
	vector<pair<int, int>>, greater<pair<int, int>>()>> pq;

	for (auto y : mp)
	{
		pq.push({y.second, y.first});
		if (pq.size > K)
		{
			pq.pop();
		}
	}

	vector<int> res(K);

	for (int i = K- 1; i >= 0; i--)
		res[i] = pq.top().second
		pq.pop();
	

	return res;




}






























