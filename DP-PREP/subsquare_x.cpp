#include <bits/stdc++.h>
using namespace std;


int largestSubSequence(vector<vector<char>& mat) {

	
int n = mat.size();

	int maxSize = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int size = 1; size <= n - max(i, j); size++) {
					
				bool valid = true;

				for (int k = 0; k < size; k++) {
	
					if (mat[i]][j])
				}
				
			}
		}

	}
}


