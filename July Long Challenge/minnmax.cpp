#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       int n,k;
       cin>>n;
       cin>>k;
       if(n==1)
       {
           cout<<k<<endl;
       }
       else
       {
           int n1,n2;
           n1 = k/2;
           n2 = k-n1;
            int a[n] = {0};
            int b[2];
            b[0] = n1;
            b[1] = n2;
            if(n%2==0)
            {
                int j = 1;
                int i =0;
                while(i<2&&j<n)
                {
                 a[j] +=b[i];
                 j+=2;
                 i++;
                }
                j = 0;
                 while(i<2&&j<n)
                {
                 a[j] +=b[i];
                 j+=2;
                 i++;
                }
            }
            else
            {
               int j = 0;
                int i =0;
                while(i<2&&j<n)
                {
                 a[j] +=b[i];
                 j+=2;
                 i++;
                }
                j = 1;
                 while(i<2&&j<n)
                {
                 a[j] +=b[i];
                 j+=2;
                 i++;
                }
            }
                int sum = 0;
            for(int i=0;i<n-1;i++)
            {
                sum += abs(a[i]-a[i+1]);
            }
            //for(int i=0;i<n;i++)
            //cout<<a[i]<<" ";
           // cout<<endl;
            cout<<sum<<endl;
            
       }
      
    }
    
    
    
    return 0;
}