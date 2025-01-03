#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isIL(string& s1, string& s2, string& s3) {
	
	int m = s1.size(), n = s2.size();

	if ( m + n != s3.size()) return false;

	vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

	dp[0][0]= true;

	
	for (int j = 1;  j <= n; j++) { 
		dp[0][j] = (s2[j- 1] == s3[ j - 1 ]) && dp[0][j - 1];
	}

	for (int i = 1;  i <= m; i++) { 
		dp[i][0] = (s1[i - 1] == s3[ i - 1 ]) && dp[i - 1][0];
	}

	// Process all characters of s1 and s2
	for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
					
				int k = j + i;
				dp[i][j] = (s1[i - 1] == s3[k - 1] && dp[i - 1][j]) ||
					(s2[ j - 1] == s3[k - 1] && dp[i][j - 1]);
					
			}
	}

	return dp[m][n];

}

int main() {
	
	string s1 = "XXY";
	string s2 = "XXZ";
	string s3 = "XXZXXXY";

	cout << (isIL(s1, s2, s3) ? "true" : "false" ) << endl;
	return 0;

}
