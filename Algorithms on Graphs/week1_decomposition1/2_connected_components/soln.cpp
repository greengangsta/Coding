#include<bits/stdc++.h>
using namespace std;

vector<int> reachable(vector <vector<int>> adj,int u,vector <int> visited)
{
    visited[u] = 1;
    for(int i = 0;i<adj[u].size();i++)
    {
        if(visited[adj[u][i]]==0)
          visited = reachable(adj,adj[u][i],visited);
    }
   
    return visited;
}


int  connected_components(vector <vector<int>> adj,vector <int> visited)
{
    // cout<<u<<endl;
    int cc = 0;
    for(int i = 0;i<adj.size();i++)
    {
        if(visited[i]==0)
         {
           visited = reachable(adj,i,visited);
           cc +=1;
         }
    }
   
    return cc;
}

int main()
{
   int n,m;
   cin>>n>>m;
   vector <vector<int>> adj(n);
   for(int i=0;i<m;i++)
   {
      int u,v;
      cin >> u>>v;
      adj[u-1].push_back(v-1);
      adj[v-1].push_back(u-1);
   }
   vector<int > visited(n);
   for(int i = 0;i<n;i++)
     visited.push_back(0);
   int cc = connected_components(adj,visited);
   cout<<cc<<endl;
    
    
    return 0;
}