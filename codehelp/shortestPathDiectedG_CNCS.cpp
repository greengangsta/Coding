#include<bits/stdc++.h>

void bfs(unordered_map <int, list<int> > &adj, int i, unordered_map <int, bool> &visited, unordered_map <int, int> &parent){
    
    
    queue<int> q; 
    q.push(i);
	parent[i] = -1; 
	visited[i] = 1;
	
    while(!q.empty()){
        int frontVal = q.front(); 
        q.pop();
        for (auto it: adj[frontVal]) { 
            if(!visited[it]){
                visited[it] = 1; 
				parent[it] = frontVal; 
                q.push(it);
            }
            
        }
        
    } 

}


vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here

	unordered_map <int, bool> visited;
	unordered_map < int, int > parent;
	unordered_map <int, list<int>> adj;
    for (int i = 1; i <= n; i++) {
        visited[i] = false; 
    }

	for(int i=0;i<m;i++){
      int u= edges[i].first; 
      int v= edges[i].second; 
      adj[u].push_back(v); 
       adj[v].push_back(u); 
    }

    vector<int> ans; 

	bfs(adj, s, visited, parent);

    ans.push_back(t);

    int curr = t;
    
    while(curr != s){
        curr = parent[curr]; 
        ans.push_back(curr); 
	}

    

    reverse(ans.begin(), ans.end());
	return ans; 
	
}
