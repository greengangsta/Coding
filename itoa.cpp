#include<bits/stdc++.h>
using namespace std;

int main()
{
   int a = 1567;
   string s = "";
   while(a)
   {
       s += "0123456789abcdef"[a%10];
       a  = a/10;
   }
   string t = "";
   for(int i= s.length()-1;i>=0;i--)
    {
       t += s[i];
    }
    cout<<t<<endl;
    return 0;
}