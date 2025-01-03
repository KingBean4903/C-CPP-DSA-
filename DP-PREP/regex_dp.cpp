#include <iostream>
#include <vector>

using namespace std;

bool isMatch(string t, string p) {

	int n = t.size();
	int m = p.size();

	vector<vector<bool>> dp(n+1, vector<bool>(m + 1, false));

	//EMPTY PATTERN MATCHES emtpy text
	dp[0][0] = true;

	// Deals with patterns like a*, a*b*, a*b*c*, where *
	// can eliminate preceding character
	
	for (int j = 1; j <= m; j++) {
		if (p[j - 1] == '*' && j > 1) {
				dp[0][j] = dp[0][j-2];
		}
	}
	
	for (int i = 1; i <=n; i++) {
		
		for (int j = 1; j <= m; j++) {
		
				if (p[j - 1] == '.' || t[i-1] == p[j - 1]) {
					
						dp[i][j] = dp[i - 1][j - 1];
				}
				
				else if (p[j - 1] == '*' && j > 1) {
						
						dp[i][j] = dp[i][j - 2] ||
							(dp[i - 1][j] && (p[j - 2] == t[i - 1] || p[j - 2] == '.'));
					
				}
		}
	}

	return dp[n][m];
}

int main() {

	cout << boolaplpha << isMatch("aab", "a.*") << endl;

	return 0;
}
