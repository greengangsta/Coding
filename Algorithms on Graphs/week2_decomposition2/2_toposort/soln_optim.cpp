#include<bits/stdc++.h>
using namespace std;

int k = 0;
int all_visited = 0;
struct node
{
    int vertex;
    int postorder;
};
bool cmp(const node n1, const node n2)
{
    return n1.postorder > n2.postorder;
}
void reachable(vector <vector<int> > &adj,int u,vector <int> &visited,vector<int> &post_order)
{ 
    visited[u] = 1;
    all_visited += 1;
    for(int i = 0;i<adj[u].size();i++)
    {
        if(visited[adj[u][i]]==0)
         reachable(adj,adj[u][i],visited,post_order);
    }
    post_order[u] = k;
    k += 1;
    return ;
}


void top_sort(vector< vector<int> > &adj,vector <int> &visited,vector<int> &post_order)
{
    for(int i = 0;i<adj.size();i++)
    {
        if(visited[i]==0)
         {
            reachable(adj,i,visited,post_order);
         }
        else if(all_visited==adj.size())
        {
            break;
        }
    }
    return ;
}

int main()
{
   int n,m;
   cin>>n>>m;
   vector < vector<int> > adj(n);
   for(int i=0;i<m;i++)
   {
     int u,v;
     cin >> u>>v;
      adj[u-1].push_back(v-1);
   }
   vector<int> visited(n);
   for(int i = 0;i<n;i++)
     visited.push_back(0);
   vector<int> post_order(n);
   top_sort(adj,visited,post_order);
   node order[n];
   for(int i=0;i<n;i++)
   {
       order[i].vertex = i;
       order[i].postorder = post_order[i];
   }
   sort(order,order+n,cmp);
   for(int i=0;i<n;i++)
   {
      cout<<order[i].vertex + 1<<" ";
   }
   cout<<endl;
   //cout<<all_visited;
 
    
    return 0;
}
