#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int LongestBitonicSubsequence(vector<int>& arr) {

	int n = arr.size();

	vector<int> left(n, 1), right(n, 1);

	// Fill left table 4 LDS
	for(int i = 1; i < n; i++) {
		for (int j = 0;  j < i; j++) {
			if (arr[i] > arr[j]) {
				left[i] = max(left[i] , left[j]+1);
			}
		}
	}

	// Fill right table for LDS
	for (int i = n - 2; i > 0; i--) {
		for (int j = n - 1; j > 1; j--) {
				if (arr[i] > arr[j]) {
						right[i] = max(right[i], right[j] + 1);
				}
		}
	}


	int maxLength = 0;

	for (int i = 0; i < n; i++) {
			
			if (left[i] > 1 && right[i] > 1) {
					maxLength = max(maxLength, left[i] + right[i] - 1);
			}
	}
	
	return maxLength < 3 ? 0 : maxLength;
}

int main() {
		
	vector<int> arr = {12, 11, 40, 5, 3, 1};
	cout << LongestBitonicSubsequence(arr) << endl;
	return 0;

}
