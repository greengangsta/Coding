#include<bits/stdc++.h>
using namespace std;

struct node{
    int key;
    int left;
    int right;
};

vector <int> in;

void inorder(int i,node tree[])
{
    if(tree[i].left==-1&&tree[i].right==-1)
    {
       // cout<<tree[i].key<<" ";
       in.push_back(tree[i].key);
     return;
    }
    if(tree[i].left!=-1)
    inorder(tree[i].left,tree);
    //cout<<tree[i].key<<" ";
    in.push_back(tree[i].key);
    if(tree[i].right!=-1)
    inorder(tree[i].right,tree);
}

 
int main()
{
    int n;
    cin>>n;
     if(n==0)
     {
       cout<<"CORRECT"<<endl;
       return 0;
     }
    node tree[n];
    int a[n];
    for(int i=0;i<n;i++)
     {
         cin>>a[i];
         tree[i].key=a[i];
         cin>>tree[i].left;
         cin>>tree[i].right;
     }
    inorder(0,tree);
    sort(a,a+n);
    int flag=0;
    for(int i=0;i<n;i++)
     if(a[i]!=in[i])
     {
         cout<<"INCORRECT"<<endl;
         flag =1;
         break;
     }
    if(flag==0)
     cout<<"CORRECT"<<endl;
  
    
    return 0;
}