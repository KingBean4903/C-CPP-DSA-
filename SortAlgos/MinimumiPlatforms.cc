// Minimum platforms Arrival Depature

// Intuition
// Sort the depature and Arrival times
// to check for a platform compare
// arrival and depature times

int minPlatforms(vector<int>& arr, vector<int>& dept)
{
	
	sort(arr.begin(), arr.end());
	sort(dept.begin(), dept.end());

	int cnt = 0, j = 0;

	for (int i = 0; i < arr.size(); i++)
	{
		while (j < n && dept[j] < arr[i]) 
		{
			cnt--;
			j++;
		}
		cnt++;

		ans = max(ans, cnt);
	}
	return ans;
}
