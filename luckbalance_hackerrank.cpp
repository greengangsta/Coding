#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,k;
  cin>>n>>k;
  int l[n],t[n];
  int sum=0;
  for(int i=0;i<n;i++) 
   {
       cin>>l[i]>>t[i];
       if(t[i]==0)
       sum+=l[i];
   }
   int a[n],j=0;
   for(int i=0;i<n;i++)
    {
        if(t[i]==1)
        a[j++]=l[i];
    }
   sort(a,a+j);
   while(j--&&k--)
   {
       sum+=a[j];
   }
   while(j>=0)
   {
       sum-=a[j];
       j--;
   }
   cout<<sum<<endl;
   
    return 0;
}