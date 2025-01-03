#include <bits/stdc++.h>

using namespace std;


int maxCoins(vector<int> &arr) {
	
	int n = arr.size();

	arr.insert(arr.begin(), 1);
	arr.push_back(1);

	vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

	for (int length = 1; length <= n; length++) {
			
		for (int left = 1; left <= n - length + 1; left++) {
				
			int right = left + length - 1;

			for(int k = left;  k <= right; k++) {

					int coins = arr[left - 1]  *  arr[k]  *  arr[right + 1];

					int totalCoins = coins + dp[left][k - 1] + dp[k - 1][right];

					dp[left][right] = max(totalCoins, dp[left][right]);

			}
			
		}

	}
	
	return dp[1][n];

}

int main() {
	
	vector<int> arr = {3 , 1, 5, 8};
	cout << maxCoins(arr);

	return 0;

}
