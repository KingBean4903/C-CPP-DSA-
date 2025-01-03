#include <bits/stdc++.h>
#include <vector>

using namespace std;

void addEdge(vector<vector<int>>& mat, int i, int j) {
	
	mat[i][j] = 1;
	mat[j][i] = 1;

}

void displayMatrix(vector<vector<int>>& mat) {
	
	int n = mat.size();

	for (int i = 0; i < n; i++) { 
		for (int j =0; j < n; j++) 
				cout << mat[i][j] << " ";
		cout << endl;
	}
}

int main() {

	int V = 4;

	vector<vector<int>> mat(V, vector<int>(V, 0));

	addEdge(mat, 0, 1);
	addEdge(mat, 0, 2);
	addEdge(mat, 1, 2);
	addEdge(mat, 2, 3);

	cout << "Adjacency Matrix" << endl;

	displayMatrix(mat);

	return 0;

}
