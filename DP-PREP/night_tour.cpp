#include <bits/stdc++.h>
using namespace std;

#define N 8

int solveKUTil(int x, int  y, int movei,
		int sol[N][N], int xMove[], int yMove[]);

/* A utility function to check if i,j are
 * valid indexes for N*N chessboard 
 */
int isSafe(int x, int y, int sol[N][N]) {
	return (x >= 0 && x < N && y >= 0 && y < N
			&& sol[x][y] == -1);
}

/* A utility function to print
 * solution matrix sol[N][N] 
 */
void printSolution(int sol[N][N]) {
	for (int x = 0; x < N; x++)	
		for (int y = 0; y < N; y++)
			cout << " " << setw(2) << sol[x][y] << " ";
	cout << endl;
}



/* Function to solve Knight tour Problem using 
 * backtracking.
 * Function mainly uses solveKUTil() to solve the
 * problem.
 * it returns false if no complete tour possible
 */
int solveKT() {
	
	int sol[N][N];

	/* Initialization of solution matrix */
	for (int x = 0; x < N; x++)
		for (int y = 0; y < N; y++)
				sol[x][y] = -1;

	int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2};
	int yMove[8] = { 1, 2, 2,  1, -1, -2, -2, -1 };

	// Since the knight is usually at the first blocj
	//
	sol[0][0] = 0;

	/* Start from 0,0 and explore all tours
	 * using solveKUTil()
	 */
		if (solveKUTil(0, 0 ,1 ,sol,  xMove, yMove) == 0){
				cout << "Solution does not exist";
				return 0;
		 } else {
			printSolution(sol);
		}
	return -1;
}

int solveKUTil(int x, int y, int movei, int sol[N][N]
		,int xMove[8],int yMove[8]) {

	int k, next_x, next_y;

	if (movei == N * N)
			return 1;

	for (k = 0; k < 8; k++) {
		next_x = x + xMove[k];
		next_y = y + yMove[k];
		if (isSafe(next_x, next_y, sol)) {
			sol[next_x][next_y] = movei;
			if (solveKUTil(next_x, next_y, movei + 1, sol, xMove, yMove) == 1)
				return 1;
			else
				sol[next_x][next_y] = -1;
		}
	}
		return 0;
}

int main() {
	
	solveKT();
	return 0;

}












