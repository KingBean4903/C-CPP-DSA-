// Quick sort implementation in c++
// Is a divide and conquer algorithm
// where we choose the pivot
// place smalller elements on the left
// of the pivot and larget elements
// on the right  of the pivot

// Complexity: Time - O(n log n) Space O(n) 
// due to a recursive call stack

int partition(vector<int>& arr, int low, int high)
{
	
	int pivot = arr[high];

	int i = low - 1;

	for (int j = low; j < high; j++) 
	{
		if (arr[j] < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}

	swap(arr[i + 1], arr[high]);
	
	return i + 1;

}


void quickSort(vector<int>& arr, int  low, int high)
{
	
	if (low < high) {
	int pi = partition(arr, low, high);

	quickSort(arr, low, pi - 1);
	quicksort(arr, pi + 1, high);
	}
}
