#include<bits/stdc++.h>

bool dfs(int v,  unordered_map <int, list<int> > &adj,  unordered_map <int, bool> &visited,  unordered_map <int, bool> &dfs_visited){

    if(!visited[v]){

        visited[v] = true; 
        dfs_visited[v] = true; 
        for(auto it: adj[v]){
            if(visited[it] && dfs_visited[it]){
              return true; 
            }
            else if(!visited[it]){
                 bool ans =  dfs(it, adj, visited, dfs_visited); 
                 if(ans)
                    return ans; 
                   
            }
        }

    }

    dfs_visited[v] = false; 

    return false; 

}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.

  unordered_map <int, list<int> > adj; 
  unordered_map <int, bool> visited; 
  unordered_map <int, bool> dfs_visited; 

  for(int i=0;i<edges.size();i++){
      int u= edges[i].first; 
      int v= edges[i].second; 
      adj[u].push_back(v); 
    }

    for(int i=1;i<=n;i++){
      visited[i]= false; 
      dfs_visited[i]= false; 
    }

    for(int i=1;i<=n;i++){
      if(!visited[i])
      {
        bool ans = dfs(i, adj, visited, dfs_visited); 
        if(ans)
          return ans; 
      }
     
    }

    return false; 
}
