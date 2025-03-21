// Non-Overlapping Intervals

int novoverlapping(vector<int>& arr)
{
	sort(arr.begin(), arr.end());

	int end = arr[0][1];

	for (int i = 0; i < arr.size(); i++)
		if (arr[i][0] < end )
		{
			cnt++;
			end = min(arr[i][1], end);
		}

		else {
			end = arr[i][1];
		}

	return cnt;
}



























