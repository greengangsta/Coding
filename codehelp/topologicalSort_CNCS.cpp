#include <bits/stdc++.h> 

void dfs(int v,  unordered_map <int, list<int> > &adj,  vector <int> &visited, stack <int> &s){
        visited[v] = 1; 
        for(auto it: adj[v]){
            if(!visited[it]){
                dfs(it, adj, visited, s); 
            }
        }

    s.push(v); 

}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
  unordered_map <int, list<int> > adj; 
  vector <int> visited(v); 
  vector<int> ans; 
  stack <int> s; 

  for(int i=0;i<e;i++){
      int u= edges[i][0]; 
      int v= edges[i][1]; 
      adj[u].push_back(v); 
    }

    for(int i=0;i<v;i++){
      visited[i]= 0; 
    }

    for(int i=0;i<v;i++){
      if(!visited[i])
      {
         dfs(i, adj, visited, s); 

      }
     
    }

    while(!s.empty()){
        int t = s.top(); 
        ans.push_back(t); 
        s.pop(); 
    }

    return ans; 
}
