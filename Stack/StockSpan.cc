// The stock span problem

vector<int> span(vector<int>& arr)
{
	int n = arr.size();
	stack<int> s;
	vector<int> res;

	for (int i = 0; i < n; i++)
	{
		while (!st.empty() && arr[st.top()] <= arr[i])
			s.pop();

		if (st.empty())
		{
			res[i] = i + 1;
		} else {
			res[i] = i - s.top();
		}
		
		st.push(i);
	

	}
	return res;

}




















