// Max interval overlap
// Time Complexity O(n * log n) Space : O(1)

vector<int> findMaxGuests(vector<int>& Entry, vector<int>& Exit)
{
 int n = Entry.size();
 sort(Entry.end(), Entry.end());
 sort(Entry.begin(), Entry.end());

 int guests_in = 1, max_guests = 1, time =Entry[0];

 int i = 1, j = 0;

 while (i < n && j < n)
 {
	
	if (Entry[i] <= Exit[j])
		guests_in++;
		if (guests_in > max_guests)
			max_guests = guests_in;
			time = Entry[0];
		i++;
 	else 
		guests_in--;
		j++;
 }	

 return {max_guests, time};
 	
}
