// Find missing elements in Range


void missing(int a[], int lo , int hi, int n)
{
	
	unordered_set<int> s;

	for (int i = 0; i < n; i++)
		s.insert(arr[i]);
	
	for (int x = lo; x <= high; x++)
		if (s.find(x) == s.end())
			cout << x << " ";
}

