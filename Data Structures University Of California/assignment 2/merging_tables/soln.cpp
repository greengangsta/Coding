#include<bits/stdc++.h>
using namespace std;

struct node
{
    int rank;
    int parent;
    int value;
};

int find(node arr[],int i)
{
    if(arr[i].parent!=i)
      arr[i].parent = find(arr,arr[i].parent);
    return arr[i].parent;
}

int union1(node arr[],int i, int j)
{
  int x = find(arr,i);
  int y = find(arr,j);
  if(x==y)
   return -1;
  if(arr[x].rank<arr[y].rank)
  {
     arr[x].parent = y;
     arr[y].value+=arr[x].value;
     return arr[y].value;
  }
  else if(arr[x].rank==arr[y].rank)
  {
      arr[x].parent = y;
      arr[y].rank+=1;
      arr[y].value+=arr[x].value;
      return arr[y].value;
  }
  else
  {
      arr[y].parent =x;
      arr[x].value+=arr[y].value;
      return arr[x].value;
      
  }
}

int main()
{
    int n,m;
    cin>>n>>m;
    node arr[n];
    int max =-1;
    for(int i=0;i<n;i++)
    {
        arr[i].parent=i;
        arr[i].rank=0;
        cin>>arr[i].value;
        if(arr[i].value>max)
        max = arr[i].value;
    }
    for(int j=0;j<m;j++)
    {
        int a,b;
        cin>>a;
        cin>>b;
        int newmax = union1(arr,a-1,b-1);
        if(newmax>max)
        max = newmax;
        cout<<max<<endl;
    }

     
     
    return 0;
}