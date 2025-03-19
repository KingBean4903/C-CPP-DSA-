// Meeting rooms - Find minimum meeting rooms

int minMeetingRooms(vector<int>& start, vector<int>& end)
{
 
 int n = start.size();

 sort(start.begin(), start.end());
 sort(end.begin(), end.end());
 
 int room = 0;
 int res = 0;

 int i = 0, j = 0;

 while (i < n) 
 {
 	if (start[i] < end[j]) 
	{
		room++;
		i++
	} else 
	{
		room--;
		j++;
	}

 }

 res = max(res, room)

 return res;

}
