// Subarray with given sum

vector<int> subarray(vector<int>& arr, int target)
{
	int n = arr.size();
	int s = 0, e = 0;
	int curr  = 0;

	vector<int> res;

	for (int i = 0; i < n; i++) {
			curr += arr[i];

			if (curr >= target) {
				e = i;
				while (s < e && curr > target) {
					curr -= arr[s];
					++s;
				}

				if (curr == target) {
					res.push_back(s + 1);
					res.push_back(e + 1);
					return res;
				}		
			}
	}
	
	return {-1};

}
