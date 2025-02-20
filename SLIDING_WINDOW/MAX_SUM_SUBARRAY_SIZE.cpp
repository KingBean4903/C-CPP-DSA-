#include <bits/stdc++.h>
using namespace std;

void func(vector<int> arr, int k, int n)
{
	
	int ans = n;
	int start = 0;
	int sum = 0;
	bool not_possible = false;

	for (int end = 0; end < n; end++) {
		
		sum += arr[end];

		while (sum > k) {
			sum -= arr[start];
			start++;
			
			ans = min(ans, end - start + 1);

			if (sum == 0) {
				not_possible = true;
				break;
			}
		}
		if (not_possible) {
			ans = -1;
			break;
		}
	}

	cout << ans;
}

int main()
{
	
	vector<int> arr = { 1, 2, 3, 4 };
	int k = 8;
	int n = arr.size();
	func(arr, k, n);
	return 0;

}

