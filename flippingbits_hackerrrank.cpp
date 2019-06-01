#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long int n;
        cin>>n;
        int a[32] = {0};
        int i=31;
        while(n>1)
        {
            if(n%2==0)
             a[i] =0;
            else
             a[i] =1;
            n/=2;
            i--;
        }
         if(n==1)
          a[i] = 1;
         for(int i=0;i<32;i++)
         {
             if(a[i]==0)
              a[i]=1;
             else 
              a[i] = 0;
         }
         long int sum = 0;
         for(int i=31,j=0;i>=0,j<32;i--,j++)
          sum+=a[i]*pow(2,j);
         cout<<sum<<endl;
    }
    return 0;
}