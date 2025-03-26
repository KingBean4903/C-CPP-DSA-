// Print previous greater element

void greater(vector<int>& arr)
{
	int n = arr.size();
	stack<int> s;

	s.push(arr[0]);

	std::cout << "-1, " << " ";

	for (int i = 0; i < n; i++)
		while (!s.empty() && s.top() <= arr[i] )
			s.pop();

		s.empty() ? std::cout "-1, " : std::cout << st.top();

		s.push(a[i]);
}



























