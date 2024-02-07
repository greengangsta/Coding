#include <bits/stdc++.h>


bool comparator(string a, string b){
    return a < b; 
}

void solve (vector<vector<int>> &m, int n, string path, int i, int j, vector<string> &ans){
  // cout<<"Path -> "<<path<<endl;
  if (i == n - 1 && j == n - 1 && m[i][j] == 1) {
    ans.push_back(path);
    return;
  }

  // left move

  if (j > 0 && m[i][j - 1] == 1) {
    path += "L";
    m[i][j] = 0;
    solve(m, n, path, i, j - 1, ans);
    m[i][j] = 1;
    path.erase(path.length() - 1);
  }

  // right move
  if (j < n - 1 && m[i][j + 1] == 1) {
    path += "R";
    m[i][j] = 0;
    solve(m, n, path, i, j + 1, ans);
    m[i][j] = 1;
    path.erase(path.length() - 1);
  }

  // up move
  if (i > 0 && m[i - 1][j] == 1) {
    path += "U";
    m[i][j] = 0;
    solve(m, n, path, i - 1, j, ans);
    m[i][j] = 1;
    path.erase(path.length() - 1);
  }

  // down move
  if (i < n - 1 && m[i + 1][j] == 1) {
    path += "D";
    m[i][j] = 0;
    solve(m, n, path, i + 1, j, ans);
    m[i][j] = 1;
    path.erase(path.length() - 1);
  }
}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {

        vector<string> ans; 
        string path = ""; 
        if(arr[0][0]==0 || arr[n-1][n-1]==0) {
            return ans;
        }

        solve(arr,n, path,0,0, ans );
        sort(ans.begin(), ans.end(), comparator); 
        
        return ans; 
}
