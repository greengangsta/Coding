#include<bits/stdc++.h>
using namespace std;

int is_sorted(int a[],int l,int h)
{
  for(int i=l;i<h;i++)
   {
       if(a[i]>a[i+1])
        return 0;
   }
   return 1;
}

int main()
{
   int t;
   cin>>t;
   while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
         cin>>a[i];
        int flag = 0;
        for(int i=n-3;i>=0;i-=1)
        {
            flag = 0;
            if(is_sorted(a,i,i+3))
             continue;
            else 
             {
                for(int j=0;j<3;j++)
                {
                 int temp = a[i];
                 a[i] = a[i+1];
                 a[i+1] = a[i+2];
                 a[i+2] = temp;
                 if(is_sorted(a,i,i+3))
                  {
                      flag = 1;
                      break;
                  }
                }
             }
             if(flag==0)
              break;
        }
        if(is_sorted(a,0,n))
         flag = 1;
        if(flag==0)
         cout<<"NO"<<endl;
        else
         cout<<"YES"<<endl;
        for(int i=0;i<n;i++)
          cout<<a[i]<<" ";
    }




    return 0;
}