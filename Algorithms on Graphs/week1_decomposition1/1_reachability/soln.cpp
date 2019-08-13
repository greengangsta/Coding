#include<bits/stdc++.h>
using namespace std;

vector<int> reachable(vector <vector<int>> adj,int u,vector <int> visited)
{
    // cout<<u<<endl;
    visited[u] = 1;
    for(int i = 0;i<adj[u].size();i++)
    {
        //cout<<"check1"<<endl;
        if(visited[adj[u][i]]==0)
          visited = reachable(adj,adj[u][i],visited);
    }
   
    return visited;
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
   int u,v;
   cin>>u>>v;
   visited = reachable(adj,u-1,visited);
   if(visited[v-1]==1) 
       cout<<1<<endl;
   else
    cout<<0<<endl;
    
    
    return 0;
}
