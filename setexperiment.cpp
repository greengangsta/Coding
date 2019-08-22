#include<bits/stdc++.h>
using namespace std;

int main()
{
  unordered_set <int> s;
  set <int,greater<int>> s1;
  int n;
  cin>>n;
  for(int i= 0;i<n;i++)
  {
      int a;
      cin>>a;
      s.insert(a);
      s1.insert(a);
  }
  for(auto it = s.begin();it!=s.end();it++)
   cout<<*it<<" ";
  cout<<endl;
  for(auto it = s1.begin();it!=s1.end();it++)
   cout<<*it<<" ";
  
  
  
    return 0;
}