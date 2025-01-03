#include <iostream>
#include <vector>

using namespace std;

int maxSum(vector<int>& arr){
	
	int n = arr.size();

	vector<int> dp(n + 1,  0);

	// BASE CASE
	dp[0] = 0;
	dp[1] = arr[0];

	// fill the dp array using the bottom
	// up approach
	for (int i = 2; i <= n; i++) 
		dp[i] = max(arr[i - 1] + dp[i - 2], dp[i - 1]);


	return dp[n];
}

int main() {
	
	vector<int> arr = {6, 7, 1, 3, 8, 2, 4};
	cout << maxSum(arr) << endl;
	return 0;
}
