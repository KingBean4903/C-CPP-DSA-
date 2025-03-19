// Median of two sorted arrays of 
// Different sizes

// Intuition
// The input is sorted
// most likely we will go
// for a binary search solution
// Complexity : Time O(log(m + n)) Space O(1)

double findMedian(vector<int>& a, vector<int>& b)
{
	int n = a.size();
	int m = b.size();
	
	int lo = 0;
	int hi = n;

	while (lo <= high) {
		int mid1 = (lo + hi) / 2;
		int mid2 = (n + m + 1) / 2 - mid1;

		int l1 = (a[mid1] == 0 ? INT_MIN : a[mid1 - 1]);
		int r1 = (a[mid1] == n ? INT_MAX : a[mid1]);
	
		int l2 = (a[mid2] == 0 ? INT_MIN : a[mid2 - 1]);
		int r2 = (a[mid2] == n ? INT_MAX : a[mid2]);

	    if (l1 <= r2 && r1 >= l2)
		{
			if ((n + m) % 2 == 0)
				return (max(l1, l2) + min(r1, r2))/ 2.0;
			else
				return max(l1, l2);
		}


	
		if (l1 > r2)
			hi = mid1 - 1;
		else
			lo = mid1 + 1;
	}
	return 0.0;
}
