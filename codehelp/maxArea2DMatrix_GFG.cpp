class Solution{
private : 
    void nextSmallest(vector <int> &nextSmallestIndex, vector<int>& heights){
        stack <int> s1; 
        int n = heights.size();
        s1.push(-1);
        for(int i=n-1;i>=0;i--){

            int top = s1.top(); 

    
            if(top == -1){
                nextSmallestIndex.push_back(top);
                s1.push(i);
            }
            else if(heights[top] < heights[i]){
                nextSmallestIndex.push_back(top);
                s1.push(i);
            }
            else {

                while(top!= -1 && heights[top] >= heights[i] ){
                    s1.pop();
                    top = s1.top();
                }
                nextSmallestIndex.push_back(top);
                s1.push(i);
            }
    
        }
    
        reverse(nextSmallestIndex.begin(), nextSmallestIndex.end());
    }

    void previousSmallest(vector <int> &previousSmallestIndex, vector<int>& heights){
        stack <int> s1; 
        int n = heights.size();
        s1.push(-1);
        for(int i=0;i<n;i++){
            int top = s1.top(); 

            if(top == -1){
                previousSmallestIndex.push_back(top);
                s1.push(i);
            }
            else if(heights[top] < heights[i]){
                previousSmallestIndex.push_back(top);
                s1.push(i);
            }
            else {

                while(top!= -1 && heights[top] >= heights[i] ){

                    s1.pop();
                    top = s1.top();
                }
                previousSmallestIndex.push_back(top);
                s1.push(i);
            }
    
        }
    
    }

  int largestRectangleArea(vector<int> &heights, vector <int> &nextSmallestIndex, vector <int> &previousSmallestIndex ) {

        nextSmallest(nextSmallestIndex, heights);

        previousSmallest(previousSmallestIndex, heights);


        vector <int> areas; 
        int n = heights.size();

        int max = -1; 


        for(int i=0;i<heights.size();i++){
            int area = heights[i];
            if(nextSmallestIndex[i] == -1){
                area += (n-i-1)* heights[i];;
            }
            else{
                 area += (nextSmallestIndex[i] -i-1)* heights[i];
            }

            if(previousSmallestIndex[i] == -1){
                area += i* heights[i];
            }
            else{
                 area += (i- previousSmallestIndex[i]-1)* heights[i];
            }
            if(area > max)
            max = area; 
            areas.push_back(area);
        }
        
    return max ; 
        
    }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int maxarea = 0;
        vector <int> nextSmallestIndex; 
        vector <int> previousSmallestIndex; 
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j] > 0){
                    M[i][j] += M[i-1][j]; 
                }
            }
        }
        
        int maxi = 0; 
        for(int i=0;i<n;i++){
            vector<int> currRow; 
             for(int j=0;j<m;j++){
                 currRow.push_back(M[i][j]);
             }
            int currArea = largestRectangleArea(currRow, nextSmallestIndex, previousSmallestIndex);
            nextSmallestIndex.clear();
            previousSmallestIndex.clear();
            if(currArea > maxi)
            maxi = currArea; 
            currRow.clear();
        }
        return maxi; 
    }
};
