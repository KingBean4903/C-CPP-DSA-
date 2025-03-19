// Processing backspace in string
// abc#de#f#ghi#jklmn#op#
//
string processBackspace(string s)
{
	
	int n = s.length();

	deque<char> dq;

	for (int i = 0; i < n - 1; i++) {
		
		if (s[i] != '#')
		{
			dq.push_back(s[i]);
		} else if (!dq.empty()) {
			dq.pop_back();
		}
	}

	string ans = "";
	while(!dq.empty())
	{
			ans += dq.pop_front();
			dq.pop_front();
	}

	return ans;


}
