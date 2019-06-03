#include<bits/stdc++.h>
using namespace std;

int main()
{

  string s1,s2;
  cin>>s1>>s2;
  int a[26] = {0};
  int sum=0;
  for(int i=0;i<s1.length();i++)
     a[s1[i]-'a']++;
  for(int i=0;i<s2.length();i++)
     a[s2[i]-'a']--;
  for(int i=0;i<26;i++)
     sum+=abs(a[i]);
  cout<<sum<<endl;


    return 0;
}