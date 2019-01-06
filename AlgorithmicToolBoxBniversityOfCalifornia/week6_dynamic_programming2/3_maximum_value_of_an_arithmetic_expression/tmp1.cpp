#include <bits/stdc++.h>
using namespace std;

long long int dp1[14][14],dp2[14][14];

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}
vector <long long int> minandmax(int i,int j,string exp)
{
	vector <long long int> res(2);
    int min1 = 32767;
   int max1 = -32767;
   for(int k=i;k<=j-1;k++)
   {
        cout<<"check3"<<endl;
       int a,b,c,d;
       a = eval(dp2[i][k],dp2[k+1][j],exp[k*2 +1]);
       b = eval(dp2[i][k],dp1[k+1][j],exp[k*2 +1]);
       c = eval(dp1[i][k],dp2[k+1][j],exp[k*2 +1]);
       d = eval(dp1[i][k],dp1[k+1][j],exp[k*2 +1]);
	   min1 = min(min1,min(a,min(b,min(c,d))));
	   max1 = max(max1,max(a,max(b,max(c,d))));
   }
   res[0]=min1;
   res[1]=max1;
return res;   
}

long long get_maximum_value(const string exp) {
  //write your code here
  int n=exp.length();
//  int dp1[n][n],dp2[n][n];
  for(int i=0;i<=n/2;i++)
    {
        cout<<"check1"<<endl;
        dp1[i][i]=exp[i*2]-'0';
        dp2[i][i]=exp[i*2]-'0';
    }
  for(int s=1;s<=n/2;s++)
   {
       for(int i=1;i<=n/2-s;i++)
      {
           cout<<"check2"<<endl;
          int j=i+s;
          vector<long long int> res(2);
          res = minandmax(i,j,exp);
          dp1[i][j]=res[0];
          dp2[i][j]=res[1];
      }
   }
  for(int i=0;i<=n/2;i++)
  {
      for(int j=0;j<=n/2;j++)
      {
          cout<<dp1[i][j]<<" ";
      }
      cout<<endl;
  }
  cout<<endl<<endl;
  for(int i=0;i<=n/2;i++)
  {
      for(int j=0;j<=n/2;j++)
      {
          cout<<dp2[i][j]<<" ";
      }
      cout<<endl;
  }
   
  return dp2[0][n-1];
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
         cout<<"case : "<<t<<endl;
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
    }
}
