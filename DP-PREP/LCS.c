#include <stdio.h>

int max(int x , int y) { return (x > y) ? x : y; }

int lcs(const char * S1, const char *S2) {
		
	int m = strlen(S1);
	int n = strlen(S2);

	int dp[m + 1][n + 1];

	for(int i  = 0; i <=m; i++) {
		for(int j = 0; j <=n; j++) {
				
			if (i == 0 || j == 0) 
					dp[i][j] = 0;
			else if (S1[i] == S2[j])
					dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

		}
	}

	return dp[m][n];
	
}


int main() {
	
	const char *S1 = "abcdf";
	const char *S2 = "acbcf";

	printf("Length of LCS is %d\n", lcs(str1, str2));

	return 0;

}
