// Sort a nearly sorted (or K Sorted) array
/// Input  arr=[6. 5, 3, 2, 8, 10, 9] k=3
// Items are at a distance K in the sorted
// array

// Intuition

// Naive Approach
// sort the array Time O()n logn ) space - O(1)

// Add first K elements into a min-heap
// Loop from a[k] to a[N - 1] and push to pq
// for every position k + 1
// get top() from pq
// place it at position arr[i - k]

#include <queue>
#include <functional>

void sortArray(vector<int>& arr, int K) 
{
	int  N = arr.size();
	
	priority_queue<int, vector<int>, greater<int>()> pq;

	for (int i = 0; i < K; i++) 
		pq.push(arr[i]);

	int i;

	for (i = k; i < N; i++) {
		pq.push(arr[i]);
		arr[i - k] = pq.top();
		pq.pop();
	}

	while(!pq.empty()) {
		a[i - k] = pq.top();
		pq.pop();
		i++;
	}



}

