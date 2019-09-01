#include<bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        int a[n][n];
        int capacity[n]={0};
        int balls[n]={0};
        for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
          cin>>a[i][j];
        for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
          capacity[i] += a[i][j];
        for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
          balls[i] += a[j][i];
        sort(balls,balls+n);
        sort(capacity,capacity+n);
        int flag = 0;
        for(int i=0;i<n;i++)
        {
            if(capacity[i]!=balls[i])
             {
                 flag = 1;
                 break;
             }
        }
        if(flag==1)
         cout<<"Impossible"<<endl;
        else
         cout<<"Possible"<<endl;
        
    }




    return 0;
}