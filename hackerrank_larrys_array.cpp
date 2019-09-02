#include<bits/stdc++.h>
using namespace std;

int is_sorted(int a[],int l,int h)
{
  for(int i=l;i<h-1;i++)
   {
       if(a[i]>a[i+1])
        return 0;
   }
   return 1;
}

int main()
{
   int t;
   cin>>t;
   while(t--)
    {
        int n;
        cin>>n;
        int N = n;
        int w = 3;
        int q = n/3;
         q++;
        n = n*q-1;
        int a[n];
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
        }
        for(int i = N;i<n;i++)
            a[i] = i+1;
        int inv = 0;
        multiset<int> set1; 
        set1.insert(a[0]);
        for(int i=1;i<n;i++) 
        { 
            set1.insert(a[i]);
            auto it = set1.upper_bound(a[i]); 
            inv += distance(it, set1.end()); 
        } 
        if(inv%2==0)
         cout<<"YES"<<endl;
        else 
         cout<<"NO"<<endl;
        
    
    }




    return 0;
}
