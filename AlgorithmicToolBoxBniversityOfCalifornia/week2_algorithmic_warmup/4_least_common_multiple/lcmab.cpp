#include<bits/stdc++.h>
using namespace std;
long long int gcdab(long long int a ,long long int b)
{
    if(b==0)
     return a;
 return gcdab(b,a%b);
}
int main()
{
   long long int a,b;
   cin>>a>>b;
   long long int c;
   c = (a*b)/gcdab(a,b);
   cout<<c<<endl;
    
    
    
    return 0;
}