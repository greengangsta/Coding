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
        int b[n];
        for(int i=0;i<n;i++)
         cin>>b[i];
        int l[n],h[n],f[n];
        l[0] = 0;
        h[0] = 0;
        f[0] = 0;
        for(int i=1;i<n;i++)
        {
           l[i] = max(l[i-1],h[i-1]+ abs(b[i-1]-1));
           h[i] = max(h[i-1]+ b[i]-b[i-1],l[i-1]+abs(b[i-1]-1));
           f[i] = max(l[i],h[i]);
        }
        cout<<f[n-1]<<endl;
    }





    return 0;
}
