#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
   cin>>a[i];
  sort(a,a+n);
  long long int sum=0;
  for(int i=n-1,j=0;i>=0,j<n;i--,j++)
    sum+= a[i]*pow(2,j);
  cout<<sum<<endl;


    return 0;
}