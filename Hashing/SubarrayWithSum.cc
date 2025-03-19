// Subarray with given sum - Handles negative numbers


void subarraySum(int arr[], int n)
{
	
	unordered_map<int, int> map;
	int curr_sum = 0;

	for (int i = 0; i < n; i++) {

		curr_sum = curr_sum + arr[i];

		if (curr_sum == sum)
			cout << "0" << i << endl;
			return;


		if (map[curr_sum - sum ] != map.end())
			cout << map[curr_sum - sum ] + 1 << i << endl;
			return;

		map[curr_sum] = i;


	}


}



























:
