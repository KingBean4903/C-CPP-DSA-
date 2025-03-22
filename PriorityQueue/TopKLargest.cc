// Find K largest elements in 
// an array


vector<int> kLargest(vector<int>& arr, int k)
{
	int n = arr.size();

	priority_queue<int, vector<int>, greater<int>>
		pq(arr.begin(), arr.begin() + k);

	for (int i = 0; i < n; i++)
	{
		if (pq.top() < arr[i])
			pq.pop();
			pq.push(arr[i]);

	}
	
	vector<int> res;

	while (!pq.empty())
	{
		res.push_back(pq.top());
		pq.pop();
	}

	reverse(res.begin(), res.end());

	return  res;

}


















