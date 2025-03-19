// MAX distinct elements after removing
// k elements
// Given an array of duplicates find
// the max no of distinct elements
// after removing k elements

// Intuition
// Use a hashmap to store elements
// and their frequencies
// push them into priority queue
// and pop them subtract their frequency
// and keep count of distinct

int distinctElements(vector<int>& arr, int k) 
{
	
	unordered_map<int, int> map;

	for(auto x : arr)
	{
		map[x]++;
	}

	priority_queue<pair<int, int>> pq;

	for (auto y: map)
	{
		int freq = y.second;
		int val = y.first;
		pq.push({freq, val});
	}

	int ans;

	while(!pq.empty())
	{
		pair<int, int> top = pq.top();
		int val = top.second;
		int freq = top.first;
		pq.pop();
		
		int toRemove = min(freq-1, k);
	
		ans++;
		
		k -= toRemove;
	}

	return ans-k;

}
