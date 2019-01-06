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
vector <int> minandmax(int i,int j)
{
   int min = 32767;
   int max = -32767;
   for(int k=i;k<=j-1;k++)
   {
       int a,b,c,d;
       a = M
   }
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
          res = minandmax(i,j);
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
