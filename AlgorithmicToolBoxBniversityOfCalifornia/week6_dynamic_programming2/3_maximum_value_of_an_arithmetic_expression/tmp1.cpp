#include <bits/stdc++.h>
using namespace std;

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
vector <int> minandmax(int i,int j,string &exp)
{
	vector <int> res(2);
   int min1 = 32767;
   int max1 = -32767;
   for(int k=i;k<=j-1;k++)
   {
       int a,b,c,d;
       a = eval(dp2[i][k],dp2[k+1][j],exp[k]);
       b = eval(dp2[i][k],dp1[k+1][j],exp[k]);
       c = eval(dp1[i][k],dp2[k+1][j],exp[k]);
       d = eval(dp1[i][k],dp1[k+1][j],exp[k]);
	   min1 = min(min1,min(a,min(b,min(c,d))));
	   max1 = max(max1,max(a,max(b,max(c,d))));
   }
   res[0]=min1;
   res[1]=max1;
return res;   
}

long long get_maximum_value(const string &exp) {
  //write your code here
  int n=exp.length();
  int dp1[n][n],dp2[n][n];
  for(int i=0;i<n;i++)
    {
        dp1[i][i]=exp[i];
        dp2[i][i]=exp[i];
    }
  for(int s=1;i<n;i++)
   {
       for(int i=0;j<n-s;i++)
      {
          int j=i+s;
          vector<int> res;
          res = minandmax(i,j,exp);
          dp1[i][j]=res[0];
          dp2[i][j]=res[1];
      }
   }
   
   
  return dp2[0][n-1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
