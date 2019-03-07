#include<bits/stdc++.h>
using namespace std;
vector <int> adj[100001];
int build_tree(int a[],int n)
{
    int root=0;
    for(int i=0;i<n;i++)
    {
       if(a[i]==-1)
         root=i;
       else
       {
           adj[i].push_back(a[i]);
           adj[a[i]].push_back(i);
       }
    }
    return root;
}
int BFS(int root)
{
    map <int,int> visited;
    queue<pair<int,int>> q;
    q.push({root,0});
    pair <int,int> p;
    int max_h=0;
    while(!q.empty())
    {
        p = q.front();
        visited[p.first]=1;
        max_h = max(max_h,p.second);
        q.pop();
        for(int i=0;i<adj[p.first].size();i++)
        {
            if(!visited[adj[p.first][i]])
            q.push({ adj[p.first][i], p.second + 1 }); 
        }
    }
    return max_h;
}
int main()
{
   int n;
   cin>>n;
   int a[n] ;
   for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int root= build_tree(a,n);
    int h= BFS(root);
    cout<<h<<endl;
    
    
    return 0;
}
