// Find median in a data stream

vector<double> median(vector<int>& arr)
{
	int n = arr.size();

	priority_queue<int> lMaxHp;
	priority_queue<int, vector<int>, greater<int>> rMinHeap;

	vector<double> res;

	for (int i = 0; i < n; i++
	{
		lMaxHp.push(arr[i]);

		int temp = lMaxHp.top();
		lMaxHp.pop();
		rMinHeap.push(temp);

		if (rMinHeap.size() > lMaxHp.size())
		{		
			temp = rMinHeap.top();
			rMinHeap.pop();
			lMaxHp.push(temp);
		}
		
		double median;
		if (rMinHeap.size() != lMaxHp.size() )
		{
			median = (double) lMaxHp.top();
		} else 
		{
			median = (double) (lmaxHp.top() + rMinHeap.top())/2;
		}

		res.push_back(median);

	}
	return res;

}















