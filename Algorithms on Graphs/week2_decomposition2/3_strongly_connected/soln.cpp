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
void dfs(vector <vector<int> > &adj,int u,vector <int> &visited,stack<int>&s)
{ 
    visited[u] = 1;
    all_visited += 1;
    for(int i = 0;i<adj[u].size();i++)
    {
        if(visited[adj[u][i]]==0)
        dfs(adj,adj[u][i],visited,post_order);
    }
    s.push(u);
   // post_order[u] = k;
   // k += 1;
    //return ;
}

void reverse(vector <vector<int> > &adj)
{
    vector <vecotr <int> > temp(adj.size());
    for(int i=0;i<v.adj.size();i++)
    {
        for(int j = 0;j<adj[i].size();j++)
        {
            temp[adj[i][j]].push_back(i);
        }
    }
    return temp;
}

void scc(vector< vector<int> > &adj,vector <int> &visited,stack<int> &s)
{
    for(int i = 0;i<adj.size();i++)
    {
        if(visited[i]==0)
         {
            dfs(adj,i,visited,s);
         }
        else if(all_visited==adj.size())
        {
            break;
        }
    }
     vector <vecotr <int> > temp(adj.size());
     temp = reverse(adj);
    while(!s.empty())
    {
        int src = s.top();
        s.pop();
        if (visited[src]==1)
          continue;
        else
          dfs(reverse,src,visited,s)
    }

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
   stack <int> s;
   scc(adj,visited,s);
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
