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
       for(int i=0;i<n;i++)
         cin>>a[i];
       int sum = 0;
       int l1 = n;
       for(int i=0;i<n-1;i++)
        {
            int b[n];
            int min1=9999,min2 = 9999;
            int pos = 0;
            for(int j=0;j<l1;j++)
            {
                if(a[j%l1]+a[(j+1)%l1]<min1+min2)
                {
                    min1 = a[j%l1];
                    min2 = a[(j+1)%l1];
                    pos = j;
                }
              
            }
            sum += min1+min2;
           // cout<<min1<<" "<<min2<<endl;
          //  cout<<min1+min2<< " at postition : " <<pos<<endl;
              a[pos%l1] = 0;
              a[(pos+1)%l1] = 0;
              a[pos%l1] = min1+min2;
              int k=0;
              for(int x=0;x<l1;x++)
              {
                  if(a[x]!=0)
                  {
                      b[k] = a[x];
                      k++;
                  }
              }
              l1 = k+1;
            //  cout<<"Value of l1 : " <<l1<<endl;
              for(int x=0;x<l1;x++)
              {
                  a[x] = b[x];
              }
        }
        cout<<sum<<endl;
        
    }
    
    
    
    return 0;
}