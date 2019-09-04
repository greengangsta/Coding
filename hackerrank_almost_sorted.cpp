#include<bits/stdc++.h>
using namespace std;

int is_sorted(int a[],int l,int h)
{
  for(int i=l;i<h-1;i++)
   if(a[i]>a[i+1])
    return 0;
  return 1;
}
int is_rev_sorted(int a[],int l,int h)
{
  for(int i=l;i<h-1;i++)
   if(a[i]<a[i+1])
    return 0;
  return 1;
}
int main()
{  
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
     cin>>a[i];
    if(is_sorted(a,0,n))
     cout<<"YES"<<endl;
    else 
    {
        int id = -1,id1 = -1;
        for(int i=0;i<n-1;i++)
        {
            if(a[i]>a[i+1])
             {
                 id = i;
                 break;
             }
        }
        int count = 0;
        if(id!=-1)
        {
            for(int i = id;i<n-1;i++)
            {
              if(a[i]>a[i+1])
               {
                   count++;
                   id1 = i+1;
               }
            }
        }
        if(count==1)
         {
             int temp;
             temp = a[id];
             a[id]  = a[id1];
             a[id1] = temp;
             if(is_sorted(a,0,n))
             {
              cout<<"yes"<<endl;
              cout<<"swap "<<id+1<<" "<<id1+1<<endl;
             }
             else 
             cout<<"no"<<endl;
         }
        else if(is_rev_sorted(a,id,id1+1))
        {
            sort(a+id,a+id1+1);
            if(is_sorted(a,0,n))
            {
            cout<<"yes"<<endl;
             cout<<"reverse "<<id+1<<" "<<id1+1<<endl;
            }
            else
             cout<<"no"<<endl;
        }
        else
         cout<<"no"<<endl;
    }




    return 0;
}