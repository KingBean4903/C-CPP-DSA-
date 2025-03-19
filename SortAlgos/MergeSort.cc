#include <iostream>

void merge(vector<int>& arr, int left, int mid, int right) {
	
	int n1 = mid - left + 1;
	int n2 = right - mid;

	vector<int> L1(n1), R1(n2)

	for(int i = 0; i < n1; i++)
		L1[i] = arr[left + i];
	
	for(int j = 0; j < n2; ++)
		R1[j] = arr[mid + 1 + j];

	int i, j = 0;
	int k = left;
	
	while (i < n1 && j < n2)  
	{
		if (L1[i] <= R[j])
		{
			arr[k] = L1[i];
			i++
		} else {
			arr[k] = R1[i];
			j++
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L1[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R2[j];
		j++;
		k++;
	}


}

void mergeSort(vector<int>& arr, int left, int right)
{

	if (left >= right )
		return;
	
	int mid = left + (right - left) / 2;
	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}






















