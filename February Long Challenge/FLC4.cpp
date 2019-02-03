#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
       int n;
       cin>>n;
       int a[n];
       for(int i=0;i<n;i++)
         cin>>a[i];
       sort(a,a+n);
       int count=0;
       for(int i=0;i<n;i++)
        {
            if(a[i]>count)
            count+=a[i]-count;
            else
            continue;
        }
     
      cout<<count<<endl;
    }
    
    
    
    return 0;
}
