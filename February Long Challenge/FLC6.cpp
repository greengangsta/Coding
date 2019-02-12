#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
namespace mp = boost::multiprecision;
using namespace std;

mp::cpp_int power(mp::cpp_int x, mp::cpp_int n) 
{
    mp::cpp_int y=1;
    for(int i=0;i<n;i++)
    {
        y*=x;
    }
  return y;
}
mp::cpp_int modInverse(mp::cpp_int a,mp::cpp_int m) 
{ 
   mp::cpp_int m0 = m; 
    mp::cpp_int y = 0, x = 1; 
    if (m == 1) 
      return 0; 
    while (a > 1) 
    {
       mp::cpp_int q=a/m; 
       mp::cpp_int t=m; 
        m=a%m,a=t; 
        t=y; 
        y=x-q*y; 
        x=t; 
    } 
    if (x<0) 
       x+=m0; 
    return x; 
}
int main() {
    int t;
    cin>>t;
     while(t--)
      {
          unsigned long long int mod=1000000000+7;
           mp::cpp_int n,k,m,p,q,a,b,c;
          cin>>n>>k>>m;
          a=n,b=n-1,c=n+k;
           if(m%2==0)
            {
              p=((power(a,m/2)-power(b,m/2))*c +power(b,m/2))%mod;
              q= modInverse(power(a,m/2)*c,mod)%mod;
              cout<<(p*q)%mod<<endl;
            }
            else
            {
              p= (power(a,(m+1)/2) -power(b,(m+1)/2) )%mod;
              q= modInverse(power(a,(m+1)/2),mod)%mod;
              cout<<(p*q)%mod<<endl;
            }
         
          // cout<<p*modInverse(q,mod)<<endl;
           //cout<<modInverse(207,mod);
      }
           
    
    
    
    return 0;
}
