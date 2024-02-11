#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.

    unordered_map <int, list<pair<int, int>> > adj; 
    for(int i=0;i<m;i++){
        int u = g[i].first.first; 
        int v = g[i].first.second; 
        int w = g[i].second; 

        adj[u].push_back(make_pair(v,w)); 
        adj[v].push_back(make_pair(u,w)); 
    }

    unordered_map <int, int> parent; 
    unordered_map <int, bool> mst; 
    unordered_map <int, int> key; 

    for(int i=0;i<=n;i++){
        parent[i] = -1;
        mst[i] = false; 
        key[i] = INT_MAX;  
    }
    
    key[1] = 0;
    for(int i=1;i<=n;i++){
        int mini = INT_MAX; 
        int u; 

        for(int j=1;j<=n;j++){
            if(mst[j] == false && key[j] < mini){
                mini = key[j]; 
                u = j; 
            }
        }

        mst[u] = true; 
        for(auto it: adj[u]){
            int v = it.first; 
            int w = it.second; 
            
            if(mst[v]== false && w < key[v]){
                parent[v] = u;
                key[v] = w;  
            }
        }

    }

    vector<pair<pair<int, int>, int>>  result; 
    for(int i=2;i<=n;i++){
        result.push_back(make_pair(make_pair(parent[i],i), key[i])); 
    }

    return result; 


}
