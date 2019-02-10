#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
int modInverse(int a, int m) 
{ 
    int m0 = m; 
    int y = 0, x = 1; 
    if (m == 1) 
      return 0; 
    while (a > 1) 
    {
        int q = a / m; 
        int t = m; 
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
          int n,k,m;
          int p=0,q=1;
          cin>>n>>k>>m;
         for(int i=1;i<=m;i++)
         {
             if(m-i>=1&&n>k)
             {
                 n=n%k;
             }
             else
             {
            
                   int a=gcd(q-p,q*n);
                   cout<<"a : "<<a<<endl;
                    int x=(q-p)/a;
                    int y=(q*n)/a;
                    int l =(q*y)/gcd(q,y);
                    p=(p*(l/q)) + (x*(l/y));
                    q=l;
                     n+=k;
                     cout<<"p/q : "<<p<<'/'<<q<<endl;
                     cout<<"n : "<<n<<endl;
             }
         }
         
           cout<<p*modInverse(q,mod)<<endl;
          
      }
       
    
    
    
    return 0;
}
