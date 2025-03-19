// Trapping rain water Problem

// Naive approach
// Time O(n^2) Space O(1)

int maxWater(vector<int>& arr)
{
	
	int n = arr.size();
	int res = 0;

	for (int i = 1; i < n; i++)
	{
		int left = arr[i];
		for (int j = 0; j < n; j+)
			left = max(left, arr[j]);

		int right = arr[i];
		for (int j = i + 1; j < n; j++)
			right = max(right, arr[i]);

		res += (min(left, right) - arr[i]);
	}
	return res;	
}

// Using Two pointer technique
int waterTrap(vector<int>& arr)
{
	int left = 1;
	int right = arr.size() - 2;

	int lMax = left - 1;
	int rMax = right + 1;
	
	int res = 0;

	while(left <= right)
	{
		if (rMax <= lMax)
		{
		  	res += max(0, rMax - arr[right]);
			rMax = max(rMax, arr[right]);
			right -= 1;
		} else {
			res += max(0, lMax - arr[left]);
			lMax = max(lMax, arr[left]);
			left += 1;
		}
	}
	return res;
}



























