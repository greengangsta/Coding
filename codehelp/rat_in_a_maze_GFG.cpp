    private : 
    void solve (vector<vector<int>> &m, int n, string path, int i, int j, vector<string> &ans){
        // cout<<"Path -> "<<path<<endl;
        if(i==n-1 && j==n-1 && m[i][j] == 1){
            ans.push_back(path); 
            return; 
        }
        
        // left move 
        
        if(j>0 &&  m[i][j-1] == 1) {
            path += "L";
            m[i][j] = 0; 
            solve(m,n, path,i,j-1, ans );
            m[i][j] = 1; 
            path.erase(path.length()-1);
        }
        
        
        
        // right move 
        if(j<n-1 &&  m[i][j+1] == 1) {
            path += "R";
             m[i][j] = 0; 
            solve(m,n, path,i,j+1, ans );
             m[i][j] = 1; 
             path.erase(path.length()-1);
        }
        

        // up move 
        if(i>0 &&  m[i-1][j] == 1) {
            path += "U";
             m[i][j] = 0;
            solve(m,n, path,i-1,j, ans );
             m[i][j] = 1; 
            path.erase(path.length()-1);
        }
        

        // down move 
        if(i<n-1 &&  m[i+1][j] == 1) {
            path += "D";
             m[i][j] = 0; 
            solve(m,n, path,i+1,j, ans );
             m[i][j] = 1; 
            path.erase(path.length()-1);
        }
       
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans; 
        string path = ""; 
        // cout<<"Code reaching here"; 
        if(m[0][0]==0 || m[n-1][n-1]==0) {
             ans.push_back("-1"); 
            return ans;
        }
        solve(m,n, path,0,0, ans );
        
        return ans; 
    }
};

    
