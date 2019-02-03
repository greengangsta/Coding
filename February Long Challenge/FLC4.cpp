#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
       int n;
       cin>>n;
       long long int a,count=0;
       for(int i=0;i<n;i++)
       {
           cin>>a;
           count+=a-1;
       }
       cout<<count+1<<endl;
    }
    
    
    
    return 0;
}
