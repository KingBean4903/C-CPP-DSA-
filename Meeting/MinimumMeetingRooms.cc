i// Minimum Meeting rooms


int meeting(vector<int>& start, vector<int>& end)
{
	int n = start.size();
	int res = 0;
	int room = 0;

	int i = 0, j = 0;

	while (i < n)
	{
		if (start[i] < end[j])
		{
			room++;
			i++;
		} else 
		{

			room--;
			j++;
		}
		res = max(res, room);
	}


	return res;
}























