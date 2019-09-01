#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n,k;
   cin>>n>>k;
   int a[n];
   for(int i=0;i<n;i++)
    cin>>a[i];
   int b[n];
   for(int i= 0;i<n;i++)
      b[a[i]-1] = i;
    int j = 0;
    while(k>0 && j<n)
    {
        if(a[j]!=n-j)
        {
            int temp=a[j];
            int pos=b[n-j-1];
            a[j]=a[pos];
            a[pos]=temp;
            b[n-j-1]=j;
            b[temp-1]=pos;
            k--;
        }
        j++;
    }
   for(int i=0;i<n;i++)
    cout<<a[i]<<" ";






    return 0;
}
