// First negative integer in
// every window of size k

// Soln : Sliding Window + deque

void firstNegative(vector<int>& arr, int k)
{
	
	deque<int> Di;
	
	int i;
	for (i = 0; i < k; i++)
		if (arr[i] < 0)
			Di.push_back(i);

	for (; i < n;  i++)
		if (!Di.empty())
			 cout << arr[Di.front()] << " ";
		else
			cout << "0" << " ";

		if (!Di.empty() && Di.front() < (i - k + 1))
			Di.pop_front();

		if (arr[i] < 0)
			Di.push_back(i);

	if (!Di.empty())
		cout << arr[Di.front()] << " ";
	else
		cout << "0";

}




























