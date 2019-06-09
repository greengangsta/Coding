#include<bits/stdc++.h>
using namespace std;

bool isdiv(unsigned long long int n)
{
   int sum=0;
   while(n)
   {
       sum+=n%10;
       n = n/10;
   }
   if(sum%10==0)
    return true;
    else
    return false;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    unsigned long long int n;
    cin>>n;
    for(unsigned long long int i = n*10;i<=(n*10)+10;i++)
    {
      if(isdiv(i))
      {
          cout<<i<<endl;
          break;
      }
    }
    
    }
    
    return 0;
    
}