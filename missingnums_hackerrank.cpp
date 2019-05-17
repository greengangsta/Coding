#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,m;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
   cin>>a[i];
  cin >> m;
  int b[m];
  for (int i = 0; i < m; i++)
    cin >>b[i];
  sort(b,b+m);
  int min = b[0];
  int x[100]={0};
  for(int i=0;i<m;i++)
  {
      x[b[i]-min]++;
  }
  for (int i = 0; i < n; i++) {
    x[a[i] - min]--;
  }
  for(int i=0;i<100;i++)
  {
      if(x[i]!=0)
      cout<<i+min<<" ";
  }
  cout<<endl;
  return 0;
}
