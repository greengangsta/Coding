#include<bits/stdc++.h>
using namespace std;

int max_seq(string a, string b, int n, int m,int k)
{
    if(n<=1||m<=1)
     return 0;
    if(a[n-1]==b[m-1])
     return 1 + max_seq(a,b,n-1,m-1,k);
    else
    {
        int c1,c2,c3;
        c1 = max_seq(a,b,n-1,m,k);
        c2 = max_seq(a,b,n,m-1,k);
        if(k>0)
        {
         c3 = max_seq(a,b,n-1,m-1,k-1);
         if(c3>c2 && c3>c1)
          k = k- 1;
         return  max(max(c1,c2),1+c3);  
        }
        else
         return max(c1,c2);      
    }
}

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int k;
       cin>>k;
       string a,b;
       cin>>a>>b;
       int ans = max_seq(a,b,a.length(),b.length(),k);
       cout<<ans<<endl;
       
   }





    return 0;
}