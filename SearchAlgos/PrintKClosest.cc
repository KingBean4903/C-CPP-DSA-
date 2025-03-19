// Find K closest elements to a given value

// Use binary search
// Find the crossover point,
// we can print k closest elements
// in O(k) time.

int findCrossOver(int arr[], int low, int high int x)
{
	if (arr[high] <= x)
		return high;
	if (arr[low] > x)
		return low;

	int mid = (low + high) / 2;
	
	if (arr[mid] <= x && arr[mid + 1] > x)
		return mid;
	
	if (arr[mid] < x)
		return findCrossOver(arr, mid + 1, high, x);
	
	return findCrossOver(arr, low, mid - 1, x);
}

void printClosest(int arr[], int k, int n, int x)
{
	int l = findCrossOver(arr, 0, n -1, k);
    int r = l+;
	int count = 0;

	if (arr[l] == x) l--;

	while (l >= 0 && r < n && count < k)
	{
		if (x - arr[l] < arr[r] - x)
			printf(" %d", arr[l--]);
		else
			printf(" %d", arr[r++])
		count++;
	}
	
	while (count < k && l >= 0)
		printf(arr[l--]); count++
	while (count < k && r < n)
		printf(arr[r++]); count++


}
