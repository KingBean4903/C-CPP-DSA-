// Prefix sum of an array

// Complexity Time: 0(n) Space: O(n)
vector<int> findPrefixSum(vector<int>& arr)
{
	int n = arr.size();
	vector<int> res;
	
	res[0] = arr[0];

	for (int  i = 1; i< n; i++)
		res[i]  = res[i - 1] + arr[i];


	return res;
}























