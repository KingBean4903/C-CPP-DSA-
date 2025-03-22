// Find K closest elements to a
// given value

vector<int> kClosest(vector<int>& arr, int x,  int k)
{

	priority_queue<pair<int, int>> pq;

	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] == x)
			continue;

		pq.push({abs(arr[i] - x), -arr[i]});
		
		if (pq.size() > k)
			pq.pop();
	}

	vector<int> res;

	while (!pq.empty())
	{
		auto p = pq.top();
		res.push_back(p.second());
		pq.pop();
	}
	
	reverse(res.begin(),res.end());

	return res;

}























