#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        long long int sum=0;
        for(int i=0;i<n;i++)
        {
         cin>>a[i];
         sum += a[i];
        }
        if(sum%n!=0)
         cout<<"Impossible"<<endl;
        else
        {
            sum /=n;
            int flag = 0;
            for(int i=0;i<n;i++)
             {
                 if(a[i]==sum)
                  {
                      flag = 1;
                      sum = i+1;
                      break;
                  }
             }
            if(flag==0)
             cout<<"Impossible"<<endl;
            else
             cout<<sum<<endl;
        }
        

    }
   
   
   return 0;
}