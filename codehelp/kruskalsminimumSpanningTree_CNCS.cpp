#include<bits/stdc++.h>

bool comparator(vector<int> &a, vector<int> &b){
  return a[2] < b[2]; 
}

int findParent(int u, vector <int> &parent){
      if(u == parent[u]){
        return u; 
      }
      return parent[u] = findParent(parent[u], parent);
}

void unionSet(int u, int v, vector <int> &parent, vector <int> &rank){
    u = findParent(u, parent); 
    v = findParent(v, parent); 

    if(rank[u] < rank[v]){
       parent[u] = v; 
    }
    else if(rank[u] > rank[v]){
       parent[v] = u; 
    }
    else{
      parent[u] = v; 
      rank[v]++;             
    }
}


int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  /*
    Don't write main().
    Don't read input, it is passed as function argument.    
    No need to print anything.
    Taking input and printing output is handled automatically.
  */
  vector <int> rank(n, 0); 
  vector <int> parent(n); 
  for(int i=0;i<n;i++){
    parent[i] = i; 
  }



   sort(edges.begin(), edges.end(), comparator); 
   int minWeight = 0; 

   for(int i=0;i<edges.size();i++){
       int u = findParent(edges[i][0], parent); 
       int v = findParent(edges[i][1], parent); 
       int w = edges[i][2]; 

       if(u != v){
           minWeight += w; 
          unionSet(edges[i][0], edges[i][1], parent, rank);
       }

   }

   return  minWeight;



   
}
