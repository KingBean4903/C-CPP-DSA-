// Range sum queries without updates


void preCompute(vector<int>& arr, vector<int>& pre)
{
	
	pre[0] = arr[0];
	for (int i = 0; i < arr.size(); i++)
			pre[i] = arr[i] + pre[i - 1];

}

int rangeSum(int i, int j, vector<int>& pre)
{
	
	if (i == 0)
		return pre[j];

	return pre[j] - pre[i - 1];
}




























