#include <stdio.h>
#include <string.h>

int max(int x, int y) {
	
	return (x > y) ? x : y;

}

int lps(const char *s) {
	
	int n = strlen(s);

	int dp[n][n];

	for(int i = 0; i < n; i++) {
			dp[i][i] = 1;
	}

	for(int i = n -2; i >=0; i--) {
	
		for(int j = i + 1; j < n; j++) {
			
			if (s[i] == s[j]) {
					dp[i][j] = dp[i+1][j-1] + 2;
			} else { 
					dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
			}
		}
	}

	return dp[0][n-1];
}

int main() {

	const char *s = "GEEKSFORGEEKS";

	printf("The length of LPS id %d", lps(s));

	return 0;
}
