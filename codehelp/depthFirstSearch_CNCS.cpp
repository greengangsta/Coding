void dfs(int v, vector<vector<int>> &adjList, vector<int>&temp,  unordered_map <int, bool> &visited){

    if(!visited[v]){
        visited[v] = true; 
        temp.push_back(v); 
        for(auto it: adjList[v]){
            if(!visited[it]){
                 dfs(it, adjList, temp, visited); 
            }
        }

    }

}


vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here

    unordered_map <int, bool> visited;
    for (int i = 0; i < V; i++) {
        visited[i] = false; 
    }
    vector<vector<int>> ans; 
    vector<vector<int>> adjList; 

    vector<int> temp; 

    vector < int> adjtemp [V]; 

    for(int i=0;i<E;i++)
    {
        int u = edges[i][0]; 
        int v = edges[i][1]; 
        adjtemp[u].push_back(v); 
        adjtemp[v].push_back(u); 
    }

       vector < vector < int >> adj(V); 
       for(int i=0;i<V;i++){
           adj[i].push_back(i); 
           for(int j=0;j<adjtemp[i].size();j++){
                adj[i].push_back(adjtemp[i][j]); 
           }
       }

    for(int i=0;i<V;i++){
        dfs(i, adj, temp, visited); 
        if(temp.size() > 0)
        ans.push_back(temp);
        temp.clear(); 
    }
    return ans; 
}
