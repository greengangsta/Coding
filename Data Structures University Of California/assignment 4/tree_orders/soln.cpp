#include<bits/stdc++.h>
using namespace std;

struct node{
    int key;
    int left;
    int right;
};


void inorder(int i,node tree[])
{
    if(tree[i].left==-1&&tree[i].right==-1)
    {
        cout<<tree[i].key<<" ";
     return;
    }
    if(tree[i].left!=-1)
    inorder(tree[i].left,tree);
    cout<<tree[i].key<<" ";
    if(tree[i].right!=-1)
    inorder(tree[i].right,tree);
}
void preorder(int i,node tree[])
{
  if(tree[i].left==-1&&tree[i].right==-1)
     {
         cout<<tree[i].key<<" ";
         return;
     }
    cout<<tree[i].key<<" ";
    if(tree[i].left!=-1)
    preorder(tree[i].left,tree);
    if(tree[i].right!=-1)
    preorder(tree[i].right,tree);  
}
void postorder(int i,node tree[])
{
    if(tree[i].left==-1&&tree[i].right==-1)
    {
        cout<<tree[i].key<<" ";
        return;
    }
    if(tree[i].left!=-1)
    postorder(tree[i].left,tree);
    if(tree[i].right!=-1)
    postorder(tree[i].right,tree);
    cout<<tree[i].key<<" ";
}
 
int main()
{
    int n;
    cin>>n;
    node tree[n];
    for(int i=0;i<n;i++)
     {
         cin>>tree[i].key;
         cin>>tree[i].left;
         cin>>tree[i].right;
     }
    inorder(0,tree);
    cout<<endl;
    preorder(0,tree);
    cout<<endl;
    postorder(0,tree);
  
    
    return 0;
}