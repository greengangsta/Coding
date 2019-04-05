#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin>>n;
   long int a[n];
   for(int i=0;i<n;i++)
     cin>>a[i];
   sort(a,a+n);
   long int b[n-1];
   for(int i=0;i<n-1;i++)
     b[i] = a[i]%a[n-1];
   sort(b,b+n);
   cout<<b[n-2]<<endl;
    
    
    return 0;
}