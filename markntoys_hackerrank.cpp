#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
     cin>>a[i];
    sort(a,a+n);
    int count=0,i=0;
    while(k-a[i]>=0)
    {
        count++;
        k-=a[i];
        i++;
    }
    cout<<count<<endl;

    return 0;
}