/* Substring of length k
 * having max frequency in the
 * given string
 */

// Naive approach generating all substrings
// store the frequency of each in a map
// use sliding window technique
string maxSubstring(string s, int k)
{

	string curr = "";
	int i = j = 0, n = s.length();

	map<string, int> mp;

	while(j < n)
	{
		cur += s[j];

		if (j - i < k)
		{
				j++;
		} else if (j -i == k)
		{
			map[curr]++;
			curr(0, 1);
			i++;
			j++;
		}
	}

	int cnt = INT_MIN;
	string ans;

	for (auto x : mp)
	{
		int c = x.second;
	  if (c > c ) {
				ans = x.first;
				cnt = c;
		}

	}
	
	return ans;	
}

using ll = long long int;
// Efficient approach
void maxOccSub(string s, ll k)
{
	
	map<deque<char>, ll> M;
	ll i;

	deque<char> D;

	for (i = 0; i < k; i++)
				D.push_back(s[i]);

	M[D]++;

	D.pop_front();

	for (int j = i; j < s.size(); j++) {
				
				D.push_back(s[j]);
				M[D]++;

				D.pop_front();
	}

	ll maxi = INT_MIN;
	deque<char> ans;
	for (auto x : M)
	{
		if (x.second > maxi) {
				maxi = x.second;
				ans = x.first;
		}
			
	}
	
	for (ll i = 0; i < ans.size(); i++)
			std::cout << ans[i] ;

}


































