#include <stdio.h>
#include <string.h>


int min(int x, int y, int z) {
		if (x < y)
				return (x < z) ? x : z;
		else
			return (y < z) ? y : z;
}

int editDp(const char *S1, const char *S2) {
	
	int m = strlen(S1);	
	int n = strlen(S2);

	int dp[m+1][n+1];

	for(int i = 0; i <= m; i++)
		dp[i][0] = i;
	
	
	for(int j = 0; j <= n; j++)
		dp[j][0] = j;


	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)
			if(S1[i] == S2[j])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = 1 + min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]);

	return dp[m][n];

}

int main() {
	
	const char *S1 = "abcdef";
	const char *S2 = "azced";

	printf("%d\n", editDp(S1, S2));

	return 0;
	
}
