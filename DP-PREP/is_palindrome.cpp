#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int isPalindrome(string& s) {
		
	int n = s.length();
	
	// min number of cuts for palindrome
	// partitioning of s[i...j]
	int dp[n][n];

	// True if substring s[i...j]
	// is palindrome else false
	bool isPalin[n][n];

	for (int i = 0; i< n; i++) {
		dp[i][i] = 0;
		isPalin[i][i] = true;
	}

	
	for (int len = 2; len <= n; len++) {
			
		for (int i = 0, j = i + len - 1; j < n; i++, j++) {
				
				if (len == 2) 
					isPalin[i][j] = (s[i] == s[j]);
				else 
					isPalin[i][j] = (s[i] == s[j]) &&
						isPalin[i+1][j-1];

				
				if (isPalin[i][j] == true)
						dp[i][j] = 0;
				else {
					dp[i][j] = INT_MAX;
					for(int k =  i; k <= j - 1; k++) 			
							dp[i][j] = min(dp[i][j],
									1 + dp[i][k] + dp[k+1][j]);
				}
		}			
	}

		return dp[0][n - 1];
		
}

int main() {
	
	string s = "ababbbabbababa";
	cout << isPalindrome(s) << endl;
	return 0;
		
}
