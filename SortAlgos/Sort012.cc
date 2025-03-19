// Sort an array 0s, 1s and 2s

// Naive approach
// Time COmplexity O( n* log n) Space O(1)
void sort12(vector<int>& arr)
{
	int n = arr.size();
	int c0 = 0, c1 = 0, c2 = 0;

	for (int i = 0; i < n; i++)
		if (arr[i] == 0)
			c0 += 1;
		else if (arr[i] == 1)
			c1 += 1;
		else
			c2 += 1;
	
	int idx = 0;

	for (int i = 0; i < c0; i++ )
		arr[idx++] = 0;

	for (int i = 0; i < c1; i++ )
		arr[idx++] = 1;
	
	for (int i = 0; i < c2; i++ )
		arr[idx++] = 2;
}

// Better approach
// Time O(n) Space O(1)

void sort012(vector<int> & arr)
{
	int n = size();
	int lo = 0;
	int mid = 0;
	int hi = n - 1;


	while(mid <= high)
	{
		if (arr[mid] == 0)
			swap(arr[mid++], arr[lo++]);
		else if (arr[mid] == 1)
			mid++
		else
			swap(arr[mid], arr[hi--])
	}

}
