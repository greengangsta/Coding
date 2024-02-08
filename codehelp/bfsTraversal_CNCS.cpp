void bfs(vector<vector<int>> &adj, int i, int n, vector<int> &ans,  unordered_map <int, bool> &visited){
    
    
    queue<int> q; 
    q.push(i);
   
    while(!q.empty()){
        int frontVal = q.front(); 
        q.pop();
        for (auto it: adj[frontVal]) { 
            if(!visited[it]){
                visited[it] = true; 
                ans.push_back(it); 
                q.push(it);
            }
            
        }
        
    } 

}


vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Write your code here.

    unordered_map <int, bool> visited;
    for (int i = 0; i < n; i++) {
        visited[i] = false; 
    }
    vector<int> ans; 
    
    bfs(adj, 0, n, ans, visited);

    return ans; 
}
