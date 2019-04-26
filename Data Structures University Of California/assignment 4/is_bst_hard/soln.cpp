#include<bits/stdc++.h>
using namespace std;

struct node{
    long long int  key;
    long long int  left;
    long long int  right;
};

//vector <long long int > in;
long long int  isBSTUtil(long long int  i, long long int  min, long long int  max,node tree[])  
{  
  if (i!=-1&&(tree[i].key < min || tree[i].key >= max))  
     return 0;  
   if (i==-1||(tree[i].left==-1&&tree[i].right==-1))  
     return 1; 
  return 
    isBSTUtil(tree[i].left, min,tree[i].key,tree) &&
    isBSTUtil(tree[i].right, tree[i].key, max,tree); 
}  
long long int  isBST(long long int  i,node tree[])  
{  
  return(isBSTUtil(i, -2147483648,2147483648,tree));  
}  
 int  main()
{
    long long int  n;
    cin>>n;
    node tree[n];
    long long int  a[n];
    if(n==0||n==1)
     cout<<"CORRECT"<<endl;
     else
     {
    for(long long int  i=0;i<n;i++)
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
     }
    return 0;
}