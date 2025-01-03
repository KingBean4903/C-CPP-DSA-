#include <bits/stdc++.h>

using namespace std;

int cutRod(vector<int>& prices) {

	int n = prices.size();

	vector<int> dp(prices.size() + 1);

	for (int i = 1; i <= n; i++) {
	
			for (int j = 1; j <= i; j++) {
					
				dp[i] = max(dp[i], prices[j-1]+dp[i-j]);
				
			}
	}

	return dp[n];
}

int main() {
	
	vector<int> prices = {  1, 5, 8, 9, 10, 17, 17, 20 };
	cout << cutRod(prices);

	return 0;

}
