#include<bits/stdc++.h>

void dfs(int node, vector<bool> &visited, stack <int> &st,  unordered_map <int, list<int> > &adj){

	visited[node] = true; 
	for(auto neighbour : adj[node]){
		if(!visited[neighbour]){
			dfs(neighbour, visited, st, adj); 
		}
	}

	st.push(node); 
}

void dfs_tp(int node, vector<bool> &visited, unordered_map <int, list<int> > &adj){

	visited[node] = true; 
	for(auto neighbour : adj[node]){
		if(!visited[neighbour]){
			dfs_tp(neighbour, visited, adj); 
		}
	}

}


int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// Write your code here.
	unordered_map <int, list<int> > adj; 
	for(int i=0;i<edges.size(); i++){
		int u = edges[i][0]; 
		int v = edges[i][1]; 

		adj[u].push_back(v); 
	}

	vector<bool> visited(v, false); 
	stack <int> st; 

	for(int i=0;i<v;i++){
		if(!visited[i]){
			dfs(i, visited, st, adj); 
		}
	}

	unordered_map <int, list<int> > tp; 

	for(int i=0;i<v;i++){
		visited[i] = false;
		for(auto j: adj[i]){
			tp[j].push_back(i); 
		}
	}

	int count = 0; 

	while(!st.empty()){
		int top = st.top(); 
		st.pop(); 
		if(!visited[top]){
			dfs_tp(top, visited, tp); 
			count++; 
		}

	}

	return count; 
}
