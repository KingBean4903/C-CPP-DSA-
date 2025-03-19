// Find K largest elements

// Naive Soln
// Complexity Time- O(n * log n) Space - O(1)
vector<int> kLargest(vector<int>& arr, int K)
{
	
	sort(arr.begin(), arr.end(), greater<int>());

	vector<int> res(arr.begin, arr.begin() + K);

	return res;
}

// Priority Queue
// Intuition
// push first K elments into pq
// loop from a[k] to a[N - 1] 
// if elmnt at top of pq is smaller than
// arr[i] pop the element from the pq and
// push the arr[i] 

vector<int> kLargest(vector<int>& arr, int k)
{
	int N = arr.size();

	priority_queue<int, vector<int>, greater<int>()>>
		minH(arr.begin(), arr.begin() + k);

	for (int i = k; i < N; i++)
	{
		if (minH.top() < arr[i]) {
			minH.pop();
			minH.push(arr[i]);
		}
	}

	vector<int> res;

	while(!minH.empty()) {
		res.push_back(minH.top());
		minH.pop();
	}

	reverse(res.begin(), res.end());

	return res;


}
