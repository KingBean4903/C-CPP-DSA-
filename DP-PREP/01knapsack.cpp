#include <iostream>
#include <vector>

using namespace std;

int knapsack(int W, vector<int>& wt, vector<int>& profit) {
	
	int n = wt.size();

	vector<vector<int>> dp(n + 1, vector<int>(W + 1));

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= W; j++) {
			
				if (i == 0 || j == 0)
						dp[i][j] = 0;
				else if(wt[i - 1] <= j)
						dp[i][j] = max(dp[i-1][j], profit[i - 1] + dp[i - 1][j - wt[i - 1]]);
				else
						dp[i][j] = dp[i - 1][j];
		}
	}

	return dp[n][W];


}


int main() {
		
	vector<int> weights = {1, 3, 4, 5};
	vector<int> profit = {1, 4, 5, 7};
	int W = 7;

	cout << knapsack(W, weights, profit) << endl;

	return 0;
		
}
