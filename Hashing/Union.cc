// Union of Two Arrays


vector<int> union(vector<int>& a, vector<int>& b)
{
	unordered_set<int> st;

	vector<int> res;

	for (int i = 0; i < a.size(); i++)
		st.insert(a[i]);

	for (int i = 0; i < b.size(); i++)
		st.insert(b[i]);

	for (auto x: st)
		res.push_back(x);

	return res;
	
}




