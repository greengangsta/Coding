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
   int min1 = 1000000001;
   for(int i=0;i<n-1;i++)
   {
       min1 = min(abs(a[i]-a[i+1]),min1);
   }
   cout<<min1<<endl;
    

    return 0;
}