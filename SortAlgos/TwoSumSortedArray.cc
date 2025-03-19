// TWO SUM PAIR IN A SORTED ARRAY

vector<int> sumPair(vector<int>& arr, int target) {

	int left = 0, right = arr.size() - 1;

	while(left < right)
	{
		int curr_sum = arr[left] + arr[right];

		if (curr_sum == target)
			return { left + 1, right + 1};
		else if (curr_sum < target)
			left++;
		else 
			right++;
	}

	return {};

}
