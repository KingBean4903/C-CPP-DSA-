#fafffafinclude <bits/stdc++.h>
using namespace std;

// A utility function to print solution
void printSolution(vector<vector<int>>& board) {

	int n = board.size();

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n;  j++) {
				if (board[i][j])
						cout << "Q ";
				else 
						cout << ". ";
		cout << "\n";
		}
	}

}

// Note that this function is called when
// 'cols' queens are already placed in columns
// for 0 to col -1.
// So we need to check only left side for 
// attacking queens
bool isSafe(vector<vector<int>>& board, 
		int row, int col) {

	int n = board.size();
	int i, j;

	//Check this row on left side
	for (i = 0; i < col; i++)
		if (board[row][i])
					return false;

	// Check upper diagonal on  left side
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
			if (board[i][j])
					return false;

	// Check lower diagonal on left side
	for (i = row, j = col; i < n && j >= 0; i++, j--)
			if (board[i][j])
					return false;
	
	return true;
}


// A recursive function to solve N
// Queen problem
bool solveNQUtil(vector<vector<int>>& board, int col) {

	int n = board.size();

	if (col >= n)
			return true;

	// Consider this column and try placing
	// this queen in all rows one by one
	for (int i = 0; i < n; i++) {
		
			
			if (isSafe(board, i, col)) {
					
					// place this queen in board[i][col]
					board[i][col] = 1;

					if (solveNQUtil(board, col + 1))
							return true;

					board[i][col] = 0;
		
			}
	}

	return false;
}

bool solveNQ(int n) {
	
	vector<vector<int>> board(n, vector<int>(n, 0));

	if (solveNQUtil(board, 0) == false) {
			cout << "Solution does not exist";
			return false;
	}

	printSolution(board);
	return true;

}


int main() {
	int n = 4;
	solveNQ(n);
	return 0;
}













































