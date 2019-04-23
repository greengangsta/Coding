#include<bits/stdc++.h>
using namespace std;

struct node{
    int key;
    int left;
    int right;
};

//vector <int> in;
int isBSTUtil(int i, int min, int max,node tree[])  
{  
  if (tree[i].left==-1&&tree[i].right==-1)  
     return 1; 
  if (tree[i].key < min || tree[i].key > max)  
     return 0;  
  return 
    isBSTUtil(tree[i].left, min,tree[i].key-1,tree) &&
    isBSTUtil(tree[i].right, tree[i].key+1, max,tree); 
}  
int isBST(int i,node tree[])  
{  
  return(isBSTUtil(i, INT_MIN, INT_MAX,tree));  
}  
 main()
{
    int n;
    cin>>n;
    node tree[n];
    int a[n];
    for(int i=0;i<n;i++)
     {
         cin>>a[i];
         tree[i].key=a[i];
         cin>>tree[i].left;
         cin>>tree[i].right;
     }
     if(isBST(0,tree))
     cout<<"CORRECT"<<endl;
     else
     cout<<"INCORRECT"<<endl;
    return 0;
}