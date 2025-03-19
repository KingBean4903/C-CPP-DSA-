// Intersection of 2 arrays

vector<int> intersection(vector<int>& a, vector<int>& b)
{
	vector<int> res;
	unordered_set<int> sa(a.begin(), a.end());

	for (int i = 0; i < a.size(); i++)
		
		if (sa.find(b[i]) !== sa.end())
     	{
			res.push_back(b[i]);
			sa.erase(b[i]);
		}
	
	return res;
}



















