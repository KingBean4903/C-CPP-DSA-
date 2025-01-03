#include <stdio.h>

int max(int a, int b) { return (a > b) ? a: b ; }


int knapSack(int W, int wt[], int val[], int n) {
	
		int i, w;
		int dp[n+1][W+1];

		for(i =0; i <= n; i++) {
			for(j = 0; j<= W; j++){
				if (i == 0 || j == 0) 
						dp[i][j] = 0;
				else if (wt[i-1] <= W) 
						dp[i][j] = max(val[i-1] + dp[i-1][W - wt[i-1]],
								dp[i-1][j]);
				else 
					dp[i][j] = dp[i-1][j];
			}
		}

		return dp[n][W];

}


int main() {
		
	int values[] = {1 , 4, 5, 7};
	int weights[] = {1, 3, 4, 5};
	int W  = 7;

	int n = sizeof(values) / sizeof(values[0]);
	printf("%d", knapSack(W, weights, values, n));

	return 0;

}
