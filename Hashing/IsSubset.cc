// Check if array is subset of another

bool issubset(vector<int>& a, vector<int>& b)
{
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	int i =0, j = 0;

	while (i < a.size() && b < b.size())
	{
		if (a[i] < b[j]) {
			i++;
		} else if (a[i] == b[j])
		{
			i++; j++;
		}
		else 
		{
			return false;
		}
	}

	return (j == b.size());
}

// Using Hashing

bool issubset(vector<int>& a, vector<int>& b)
{
	unordered_set<int> hashSet(a.begin(), a.end());

	for (auto x : b)
	{
		if (hashSet.find(x) == hashSet.end())
			return false;

	}

	return true;
}










