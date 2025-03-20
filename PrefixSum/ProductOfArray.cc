// Product of array except self

vector<int> product(vector<int>& arr)
{
	int n = arr.size();
	vector<int> prefProduct;
	vector<int> suffixProduct;
	vector<int> res;

	prefProduct[0] = 1;
	for (int i = 1; i < n; i++)
		prefProduct[i] = prefProduct[i - 1] * arr[i - 1];

	suffixProduct[n - 1] = 1;
	for (int j = n - 2; j >= 0; j++)
		suffixProduct[j] = suffixfProduct[j + 1] * arr[j + 1];

	for (int i = 0; i < n; i++)
		res[i] = prefixProduct[i] * suffixProduct[i];

	
	return res;
}



























