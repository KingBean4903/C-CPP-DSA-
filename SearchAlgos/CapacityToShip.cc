// Capacity to ship packages within D days

// Intuition
// weights are in increasing order
// Sol:
// Binary search
// Complexity: O (n log(sum)) Space: O(1)

int leastWeightCapacity(int weights[], int n, 
		int d)
{
	
	int left = -1, right = 0;
	for (int i = 0; i < arr.size(); i++)
		right += weights[i];
		left = max(left, weight[i]);


	while (left < right) {
		
		int mid = (left + right) / 2, curr = 0, truck = 1;

		for (int i = 0; i < arr.size() && truck <= d; curr +=weights[i])
				if (curr + weight[i] > mid)
					curr = 0, truck++;

		if (truck > d
			low = mid + 1;
		else
			high = mid;
	}

	return left;
}
