#include <bits/stdc++.h>

using namespace std;

int minCost(vector<vector<int>>& cost) {
	
	int m = cost.size();
	int n = cost[0].size();

	vector<vector<int>> dp(m, vector<int>(n, 0));

	dp[0][0] = cost[0][0];

	// Fill first row
	for (int j = 1; j < n; j++) {
			dp[0][j] = dp[0][j - 1] + cost [0][j];
	}

	// Fill first column 
	for (int i = 1; i < m; i++) {
			
		dp[i][0] = dp[i - 1][0] + cost[i][0];

	}

	// fill the rest of the table
	
	for (int i = 1; i < m; i++) {

		for (int j= 1; j < n; j++ ) {
				
				dp[i][j] = cost[i][j] + min({dp[i - 1][j] , dp[i][j - 1], dp[i - 1][j - 1]});

		}
	
	}

	return dp[m - 1][n - 1];

}


int main() {
	
	vector<vector<int>> cost = {
			{1, 2, 3},
			{4, 8, 2},
			{1, 5, 3},
	};

	cout << minCost(cost) << endl;

	return 0;

}




























