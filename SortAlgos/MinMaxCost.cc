// Min Max cost to buy candies

vector<int> minMax(vector<int>& arr, int k)
{
	
	sort(arr.begin(), arr.end());

	int n = arr.size();
	int minCost = 0;
	for (int i = 0; i < n; i++)
       minCost += arr[i];
	   n -= k;
	
	int maxCost = 0;
	int index = 0;
	for (int i = arr.size - 1; i >= 0; i--)
		maxCost += arr[i];
		index += k;

	return {minCost, maxCost}

}
