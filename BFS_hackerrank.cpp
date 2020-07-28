#include<bits/stdc++.h>
using namespace std;

void bfs(vector <vector<int>> adj, int n,int st)
{
    vector <int> dist(n);
    for(int i=0;i<n;i++){
        dist[i]=-1;
    }
    queue <int> q;
    q.push(st-1);
    dist[st-1] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0;i<adj[u].size();i++)
        {
            int v = adj[u][i];
            if(dist[v]==-1)
            {
            dist[v] = dist[u] + 6;
            q.push(v);
            }
        }
        
    }
    for(int i=0;i<n;i++){
        if(i!=st-1)
        cout<<dist[i]<<" ";
    }
     
}
int main()
{
   int q;
   cin>>q;
   
   while(q--){
       int n,m; 
       cin>>n>>m;
       vector <vector<int>> adj(n);
       for(int i=0;i<m;i++){
          int u,v;
          cin>>u>>v;
          adj[u-1].push_back(v-1);
          adj[v-1].push_back(u-1);
       }
       int st;
       cin>>st;
       bfs(adj,n,st); 
       cout<<endl;
   }
   
}