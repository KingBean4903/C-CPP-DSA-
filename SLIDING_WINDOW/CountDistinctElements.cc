// Count distinct elements in every
// window of size k

vector<int> distinctElements(vector<int>& arr, int k)
{
	int n = arr.size();
	unordered_map<int, int> freq;
	
	vector<int> res;

	for (int i = 0; i< k; i++)
		freq[arr[i]]++;

	for (int i = k; i < n; i++)
		freq[arr[i]] += 1;
		freq[arr[i - k]] -= 1;

		if (freq[arr[i - k]] == 0)
			freq.erase(arr[i - k]);

		res.push_back(freq.size());

	

 return res;


}























