#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
cin>>a[i];
long int maxpr =0;
for(int i=0;i<n-1;i++)
  for(int j=i+1;j<n;j++)
    {
	   maxpr = max(maxpr,a[i]*a[j]); 
	}
cout<<maxpr<<endl;
return 0;
}