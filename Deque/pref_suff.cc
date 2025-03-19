// Length of all prefixes that are 
// also suffixes of given string
// Naive Approach
void countSamePrefixSuffix(string s, int  n)
{
	int n = s.length();
	
	unordered_map<deque<char>, int> cnt;

	deque<char> prefix, suffix;

	for (int i = 0; i < n -1; s++)
	{
			
			prefix.push_back(s[i]);
			suffix.push_back(s[i]);

			cnt[prefix] = 1;

	}

	suffix.push_back(s[n - 1]);

	int index = n - 1;

	for (int i = 0; i < n - 1; i++)
	{

		suffix.pop_front();

		if (cnt[suffix] == 1) 
		{
			std::cout << index << " ";
		}

		index--;
	}
}

// Efficient Approach 
// Time O(N * N)
// Space 	O(N)
void countSamePrefixSuffix(string s)
{

	int n = s.length();

	string prefix = "";

	for (int  i = 0; i < n - 1; i++)
	{
			
		prefix += s[i];

		string suffix = s.substring(n - 1 - i, n - 1);

		if (suffix == prefix)
		{
				
			std::cout << prefix.size() <<  " "; 

		}
	}



}
