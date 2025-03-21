// Find non-overlapping intervals among
// a given set of intervals

struct interval
{
	int start, end;
};

bool compareInterval(interval i1, interval i2)
{
	return i1.start < i2.start;
}

vector<pair<int, int>> intervals(int arr[], int N)
{
	
	if (N <= 0)
		return;

	sort(arr, arr + N, compareInterval);
	


	vector<pair<int, int>> res;

	for (int i = 1; i < N; i++)
	{
		int prevEnd = arr[i - 1].end;
		int currStart = arr[i].start;

		if (currStart < prevEnd)
		{
			res.push_back({ prevEnd, currStart  });
		}
	}

	return res;







}
























