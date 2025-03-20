// Equilibrium Index

int equilibrium(vector<int>& arr)
{
	int n = arr.size();
	int total = 0, prefSum = 0;

	for (auto ele: arr)
		total += ele;

	for (int pivot = 0; pivot < n; pivot++)
		 int suffSum = total - prefSum - arr[pivot];
		 if (prefSum == suffSum)
		 	  return pivot;
		 prefSum += arr[pivot];
	
	return -1;
}

























