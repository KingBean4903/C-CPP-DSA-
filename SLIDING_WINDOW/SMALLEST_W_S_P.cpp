#include <bits/stdc++.h>
using namespace std;

string SmallestWindow(string s, string p)
{

	int len1 = s.length();
	int len2 = p.length();
	
	vector<int> hashP(256, 0);
	vector<int> hashS(256, 0);

	for (int i = 0; i < len2; i++) hashP[p[i]]++;

	int start = 0, start_index = -1, min_len = INT_MAX;
	int count = 0;

	for (int j = 0; j < len1; j++) 
	{
			
		hashS[s[j]]++;

		if (hashP[s[j]] != 0 && hashS[s[j]] <= hashP[s[j]]) 
		{
				count++;
		}

		if (count == len2) 
		{
			while (hashS[s[start]] > hashP[s[start]] || 
						hashS[s[start]] == 0) {		
				if (hashS[s[start]] > hashP[s[start]]) 
				{
					hashS[s[start]]--;
				}
				start++;
			}

			int len_window = j - start + 1;
			if (min_len > len_window) 
			{
				min_len = len_window;
				start_index = start;
			}

		}

	}

	if (start_index == -1) return "-1";

	return s.substr(start, min_len);


}


int main() 
{
	
	string s = "zoomlazapzo";
	string p = "oza";
	
	cout << SmallestWindow(s, p);

	return 0;


}
