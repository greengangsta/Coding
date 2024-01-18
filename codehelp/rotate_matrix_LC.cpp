class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int startRow = 0; 
        int startCol = 0;
        int n = matrix.size();

        //first transpose the matrix 
        for(int k=0;k<n;k++) {

            // do the swapping 
            for(int i=startRow;i<n;i++){
                swap(matrix[startRow][i], matrix[i][startRow]);
            }
            startRow++;
        }

        //reverse the rows 

        for(int i=0;i<n;i++){
            int s=0, e=n-1; 
            while(s<=e){
                swap(matrix[i][s],matrix[i][e]);
                s++;
                e--;
            }
        }
       
    }
};
