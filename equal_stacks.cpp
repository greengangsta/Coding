#include<bits/stdc++.h>
using namespace std;

bool all_equal(int h1,int h2,int h3)
{ 
    if(h1==h2&&h2==h3)
     return true;
    return false;
}


int main()
{
  int n1,n2,n3;
  cin>>n1>>n2>>n3;
  stack <int> s1,s2,s3;
  int h1=0,h2=0,h3=0;
  vector <int> v;
  for(int i=0;i<n1;i++)
  {
      int x;
      cin>>x;
      h1 += x;
      v.push_back(x);
  }
  for(int i = n1-1;i>=0;i--)
  {
      s1.push(v[i]);
  }
  v.clear();
  for(int i=0;i<n2;i++)
  {
      int x;
      cin>>x;
       h2 += x;
      v.push_back(x);
  }
  for(int i = n2-1;i>=0;i--)
  {
      s2.push(v[i]);
  }
  v.clear();
  for(int i=0;i<n3;i++)
  {
      int x;
      cin>>x;
       h3 += x;
      v.push_back(x);
  }
  for(int i = n3-1;i>=0;i--)
  {
      s3.push(v[i]);
  }
  v.clear();
  while(!all_equal(h1,h2,h3))
  {
     int m = max(max(h1,h2),h3);
     if(m==h1)
     {
        h1 -= s1.top();
        s1.pop();
     }
      if(m==h2)
     {
        h2 -= s2.top(); 
         s2.pop();
     }
      if(m==h3)
     {
         h3 -= s3.top();
         s3.pop();
     }
  }
  cout<<h1<<endl;




    return 0;
}