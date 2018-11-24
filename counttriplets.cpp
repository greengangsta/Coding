#include<bits/stdc++.h>
using namespace std;

int  main()
{
  map<int,long > mp1,mp2;
  int n,r,val;
  cin>>n>>r;
  long long int res =0;
  for(int i=0;i<n;i++)
   {
    cin >> val;
    if (mp2.count(val)) 
      res += mp2[val];
    if (mp1.count(val)) 
      mp2[val * r] += mp1[val];
    mp1[val * r]++;
   }
   cout<<res<<endl;
    return 0;
}

