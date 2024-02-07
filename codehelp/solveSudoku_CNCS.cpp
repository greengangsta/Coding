#include <bits/stdc++.h> 

bool isValid(vector<vector<int>>& sudoku,int row, int col, int k) {
       for(int i=0;i<9;i++){
           if(sudoku[i][col] == k){
               return false; 
           }
           if(sudoku[row][i] == k){
               return false; 
           }
       }

       for(int i=0;i<9;i++){
           int r = 3*(row/3) + i/3;
           int c = 3*(col/3) + i%3;
           if (sudoku[r][c] == k) {
               return false;
           }
       }

    return true; 
}
bool solve(vector<vector<int>>& sudoku){
 
    for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (sudoku[i][j] == 0) {
                    for(int k =1; k<=9;k++){
                        if(isValid(sudoku,i,j,k))
                        {
                            sudoku[i][j] = k; 
                            bool restAns = solve(sudoku); 
                            if(restAns){
                                return true; 
                            }
                            else {
                                sudoku[i][j] = 0;
                            }
                            
                        }
                        
                       
                    }
                    return false; 
                }
                
            }
    }

    return true; 
   
}

void solveSudoku(vector<vector<int>>& sudoku)
{
	// Write your code here
    // No need to print the final sudoku
    // Just fill the values in the given matrix

     solve(sudoku);
    
}
