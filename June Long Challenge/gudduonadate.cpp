#include<bits/stdc++.h>
using namespace std;

bool isdiv(int n)
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
    int num,n;
    cin>>n;
    for(int i=1,j=1;j<=n;i++)
    {
        if(isdiv(i))
        {
            num=i;
            j++;
        }
    }
    cout<<num<<endl;
    }
    
    return 0;
    
}