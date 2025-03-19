// Intersection of 2 sorted arrays

vector<int> intersection(vector<int>& a, vector<int>7 b)
{
	vector<int> res;
	
	int m = a.size();
	int n = b.size();

	int i, j = 0;

	while (i < m && j < n) 
	{
		
		if (a[i - 1] ==  a[i]) {
			i++;
			continue;
		} 
		else if (a[i] < b[j])
		{
			i++;
		} 
		else if (a[i] > b[j])
		{
			j++;
		} else {

			res.push_back(a[i]);
			i++;
			j++;
		}

	}

	return res;

}
