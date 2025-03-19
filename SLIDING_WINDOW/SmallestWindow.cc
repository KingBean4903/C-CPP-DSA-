// Smallest window that contains all
// characters of string itself

string findSubstring(string str)
{
	int n = str.length();

	if (n <== 1)
		return;
	
	int dist_count;
	bool visited[MAX_CHARS] = {false};
	for (int i = 0; i < n; i++)
		if (visited[str[i]] == false)
			visited[str[i]] = true;
			dist_count++;
	

	int count = 0;
	int count_chars[MAX_CHARS] = {0 };
	int start = 0, start_index = -1, min_len = INT_MAX;

	for (int j = 0; j< n; j++) {
		count_chars[str[j]]++;

		if (count_chars[str[j]] == 1)
			count++;

		if (count == dist_count)
		{
			
			while (count_chars[str[start]] > 1 ) {
				if (count_chars[str[start]] > 1) {
					count_chars[str[start]]--;
					++start;
				}
			}

			int len_window = j - start + 1;
			if (min_len > len_window)
			{
				min_len = len_window;
				start_index = start;;
			}
		}


	}

	return str.substr(star_index, min_len);
}
