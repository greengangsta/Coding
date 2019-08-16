#include<bits/stdc++.h>
using namespace std;

int flag = 0;
vector<int> reachable(vector <vector<int>> adj,int u,vector <int> visited,int init)
{
    for(int i = 0;i<adj[u].size();i++)
    {
       // cout<<"check inner loop"<<endl;
        if(adj[u][i] == init)
        {
         //    cout<<"check inner condition"<<endl;
            flag = 1;
            return visited;
        }
        else if(visited[adj[u][i]]==0 && flag == 0)
          visited = reachable(adj,adj[u][i],visited,init);
    }
   
    return visited;
}


int  cycle(vector <vector<int>> adj,vector <int> visited)
{
    for(int i = 0;i<adj.size();i++)
    {
        int init = i;
        if(visited[i]==0)
         {
           visited = reachable(adj,i,visited,init);
         }
    }
    return flag;
    
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
     // adj[v-1].push_back(u-1);
   }
   vector<int > visited(n);
   for(int i = 0;i<n;i++)
     visited.push_back(0);
   int flag = cycle(adj,visited);
   cout<<flag<<endl;
    
    
    return 0;
}