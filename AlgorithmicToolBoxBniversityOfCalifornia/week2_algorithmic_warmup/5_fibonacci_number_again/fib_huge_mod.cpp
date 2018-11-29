#include<bits/stdc++.h>
using namespace std;
long long get_pisano_period(long long m) {
    long long a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
}
int main()
{
   long long int n,b;
   cin>>n>>b;
   long long int p,q,c;
   c = get_pisano_period(b);
   p = n%b;
   cout<<c<<endl;
   cout<<p<<endl;
   int a[c+1];
   a[0] = 0;
   a[1] = 1;
   for(int i=2;i<=c;i++)
     a[i] = (a[i-1]+ a[i-2])%b;
     for(int i=0;i<=c;i++)
      {// cout<<a[i]<<" ";
        if(a[i]==151)
         cout<<"index is : "<<i<<endl;
      }
    cout<<a[p+2]<<endl;
    
    
    return 0;
}