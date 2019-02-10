#include <bits/stdc++.h>
using namespace std;

long long int gcd(long long int a, long long int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
long long int modInverse(long long int a, long long int m) 
{ 
   long long  int m0 = m; 
    long long int y = 0, x = 1; 
    if (m == 1) 
      return 0; 
    while (a > 1) 
    {
       long long int q = a / m; 
        long long int t = m; 
        m = a % m, a = t; 
        t = y; 
        y = x - q * y; 
        x = t; 
    } 
    if (x < 0) 
       x += m0; 
    return x; 
}
int main() {
    int t;
    cin>>t;
     while(t--)
      {
          long long int mod=1000000007;
          long long int n,k,m;
          long long int p=0,q=1;
          cin>>n>>k>>m;
         for(long long int i=1;i<=m;i++)
         {
             if(m-i>=1&&n>k)
             {
                 n=n%k;
             }
             else
             {
            
                   long long int a=gcd(q-p,q*n);
                  // cout<<"a : "<<a<<endl;
                   long long int x=(q-p)/a;
                    long long int y=(q*n)/a;
                    long long int l =(q*y)/gcd(q,y);
                    p=(p*(l/q)) + (x*(l/y));
                    q=l;
                     n+=k;
                    // cout<<"p/q : "<<p<<'/'<<q<<endl;
                    // cout<<"n : "<<n<<endl;
             }
         }
         
           cout<<p*modInverse(q,mod)<<endl;
           //cout<<modInverse(207,mod);
      }
           
    
    
    
    return 0;
}
