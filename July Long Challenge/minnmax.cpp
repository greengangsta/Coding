#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       int n,k;
       cin>>n;
       cin>>k;
       int c ;
       c = k%n;
       int a[n];
       for(int i=0;i<n;i++)
       {
           a[i] = k/n;
       }
       int j = 0;
       while(c!=0 && j<n)
       {
           a[j] +=1;
           j+=2;
           c--;
       }
     //  cout<<c<<endl;
       j = 0;
       while(c!=0 && j<n)
       {
           a[j] +=1;
           j+=2;
           
       }
       int sum = 0;
       for(int i=0;i<n-1;i++)
       {
           sum += abs(a[i]-a[i+1]);
       }
       cout<<sum<<endl;
    }
    
    
    
    return 0;
}