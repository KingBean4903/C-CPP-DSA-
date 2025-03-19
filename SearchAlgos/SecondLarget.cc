// Second largest element in an Array

// Naive Approach
int secondLargest(vector<int>& arr)
{
	sort(arr.begin(), arr.end());
	
	int res = 0;

	for (int i = n - 2; i >= 0; i--)
		if (arr[i] != arr[n - 1])
			return arr[i]

	return -1;
}

// Two Pass Approach
int secondLargest(vector<int>& arr)
{
	
	int n = arr.size();
	int largest = -1, secondLargest = -1;

	for(int i= 0; i<n; i++)
		if (arr[i] > largest)
			largest = arr[i];

	for (int i = 0; i < n; i++)
		if (arr[i] > secondLargest && arr[i] != largest) {
			secondLargest = arr[i];
		}
	
	return secondLargest;

}























