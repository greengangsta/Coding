#include <bits/stdc++.h>

bool isSafe(vector<vector<int>> &board, int row, int col, int n) {
     int x = row; 
	 int y = col;

	while (y >= 0) {
	if (board[x][y]== 1) {
		return false; 

	}
		y--; 
	}

     x = row; 
	 y = col;

	while (x >= 0 && y>=0) {
	if (board[x][y] == 1) {
		return false; 

	}
	 	x--; 
		y--; 
	}

	x = row; 
	y = col;

	while (x < n && y>=0) {
	if (board[x][y] == 1) {
		return false; 

	}
	 	x++; 
		y--; 
	}

	return true; 

}

void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int n){
	vector<int> temp; 

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			temp.push_back(board[i][j]); 
		}
	}

	ans.push_back(temp); 
}

void solve(vector<vector<int>> &board, vector<vector<int>> &ans, int n, int col) {

        if (col == n) {
			addSolution(board, ans, n); 
			return; 
        }

		for (int row = 0; row < n; row++) {
			if(isSafe(board, row, col, n)){
					board[row][col] = 1; 
					solve(board, ans, n, col+ 1); 
					board[row][col] = 0; 
			}
		}

}
 

vector<vector<int>> nQueens(int n)
{
	// Write your code here
    vector<vector<int>> board(n, vector<int> (n,0)); 
	vector<vector<int>> ans;
    solve(board, ans, n, 0); 
	return ans; 
}
