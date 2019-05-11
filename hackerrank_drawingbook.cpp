#include<bits/stdc++.h>
using namespace std;

int main()
{

int n,p;
  cin>>n;
  cin>>p;
  int front=1,back=n;
  int c1=0,c2=0;
  for(int i=1;i<=p;i++)
  {
      if(front==p||front==p+1)
        break;
      front+=2;
      c1++;
  }
  for(int i=n;i>0;i--)
  {
      if(back==p||(back==p+1&&i!=n)||back==p-1)
        break;
      else if(back==p)
       break;
       back-=2;
       c2++;
  }
  cout<<min(c1,c2)<<endl;





    return 0;
}
