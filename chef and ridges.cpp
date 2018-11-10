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
int a[n+1];
a[0]=0;
a[1] =1;
for(int i=2;i<=n;i++)
	a[i]= a[i-1] + 2*a[i-2];
int x ,y;
x = a[n];
y = pow(2,n);
cout<<x<<" "<<y<<" ";
}

return 0;
}

