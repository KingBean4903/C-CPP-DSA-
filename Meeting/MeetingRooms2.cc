// Meeting Rooms


bool meeting(vector<int>& arr)
{
	int n = arr.size();
	
	sort (arr.begin(), arr.end());

	for (int i = 0; i < n; i++)
		if (arr[i][1] > arr[i][0])
			return false;

	return true;
}

















