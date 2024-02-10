#include<bits/stdc++.h>

bool bfs(unordered_map < int, list<int>> &adj, int i, unordered_map <int, bool> &visited, unordered_map <int, int> &parent){
    
    queue<int> q; 
    q.push(i);
    parent[i] = -1; 
    visited[i] = true; 
   
    while(!q.empty()){
        int frontVal = q.front(); 
        q.pop();
        for (auto it: adj[frontVal]) { 
            if(visited[it] == true && it != parent[frontVal]){
                  return true; 
            }
            else if(!visited[it] ){
                parent[it] = frontVal; 
                visited[it] = true; 
                q.push(it);
            } 
            
        }
        
    } 

    return false; 

}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.

    unordered_map <int, bool> visited;
    unordered_map <int, list<int>> adj;
    unordered_map <int, int> parent; 

    for (int i = 0; i < n; i++) {
        visited[i] = false; 
    }

    for(int i=0;i<m;i++)
    {
        int u = edges[i][0]; 
        int v = edges[i][1]; 
        adj[u].push_back(v); 
        adj[v].push_back(u); 
    }

   
    for(int i=0;i<n;i++){
        if(!visited[i]){
        bool ans = bfs(adj, i, visited, parent); 
            if(ans){
            return "Yes"; 
            }
        }
        
           
    }

    return "No"; 
    
}
