// Find the closest pair from 2 sorted arrays

// 2 pointer technique

vector<int> printClosest(int arr1[], int arr2[], int m,
					int n, int target)
{
	
	
	int diff = INT_MAX;
	int l = 0, r = n -1;
	int res_l, res_r;

	while (l < m && r >= 0 )
	{
		if (abs(arr1[l] + arr2[r] - target)  <diff )
		{
			res_l = l;
			res_r = r;
			diff  = abs(arr1[l] + arr2[r] - x);
		} 

		if (arr1[l] + arr2[r] > x)
			r--;
		else
			l++;
	}

	retrun {res_l, res_r};

}
