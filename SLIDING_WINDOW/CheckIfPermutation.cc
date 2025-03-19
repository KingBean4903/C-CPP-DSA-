// Check if permutation patter is SubString


bool check(vector<int>& freq)
{
	for (int i = 0; i< MAX_CHARS; i++)
		if (freq[i] != 0)
			return false
	
	return true;

}

bool substring(string & txt, string & pat)
{
	int n = txt.length();
	int m = pat.length();

	vector<int> freq(MAX_CHARS, 0);

	for (int i = 0; i < m; i++)
		freq[txt[i] - 'a'] += 1;
		freq[pat[i] - 'a'] -= 1;


	if (check(freq))
		return true;

	for (int i = m; i < n; i++)
		freq[txt[i]- 'a' ] += 1;	
		freq[txt[i - m]- 'a' ] -= 1;
		if (check(freq))
			return true;
	

return false









}



























