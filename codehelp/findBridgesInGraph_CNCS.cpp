#include<bits/stdc++.h>

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<bool> &visited,  vector<vector<int>> &result, vector<int> &low,  unordered_map<int, list<int>> &adj ){
    visited[node] = true; 
    low[node] = disc[node] = timer++; 

    for(auto neighbour : adj[node]){
        if(neighbour == parent){
            continue; 
        }
        if(!visited[neighbour]){

            dfs(neighbour, node, timer, disc, visited, result,low, adj); 
            low[node]= min(low[node], low[neighbour]); 
            if(low[neighbour] > disc[node]){
                vector<int> temp; 
                temp.push_back(node); 
                temp.push_back(neighbour);
                result.push_back(temp);  
            }
        }
        else{
            low[node] = min(low[node], disc[neighbour]); 
        }

    }
}


vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here

    unordered_map<int, list<int>> adj; 
    for(int i=0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v); 
        adj[v].push_back(u); 
    }

    int timer = 0; 
    int parent = -1; 
    vector<int> disc(v, -1); 
    vector<int> low(v, -1); 
    vector<bool> visited(v, false);

    vector<vector<int>> result; 

    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(i, parent, timer, disc, visited, result, low, adj); 
        }
    }

    return result; 

}
