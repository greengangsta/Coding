#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;
long long int a[n];
for(int i=0;i<n;i++)
cin>>a[i];

long long int maxpr =0;
sort(a,a+n);
maxpr = a[n-1]*a[n-2];
cout<<maxpr<<endl;


return 0;
}