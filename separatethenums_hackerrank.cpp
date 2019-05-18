#include<bits/stdc++.h>
using namespace std;
string cals(int i,int j,string s)
{
   // cout<<"check1";
    string s1="";
    for(int k=i;k<j;k++)
     s1+=s[k];
 
   return s1;
}

string cals1(string s)
{
   // cout<<"check2";
  int l=s.length();
  char x ;
  int i = l-1;
  x = s[i];
  if(x-'0'!=9)
  s[l-1]= x+1;
  else 
  {
      while(x-'0'==9&&i>0)
      {
          s[i]=='0';
          i--;
          x = s[i];
      }
      if(i==0&&s[i]=='9')
      {
          s[i]='0';
          s = "1"+s;
      }
      else 
      {
          x = s[i];
          s[i]=x+1;
      }
  }
return s;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int flag=0;
        string s,s1;
        cin>>s;
        int l=s.length();
        for(int i=1;i<=l/2;i++)
        {
           s1 = cals(0,i,s);
           string s3=s1;
           string s2=s1;
           while(s1.length()<s.length())
           {
               s2=cals1(s2);
               s1+=s2;
           }
           cout<<s1<<" ";
           cout<<endl;
           if(s1==s)
           {
            if(s1[0]=='0')
            cout<<"NO"<<endl;
            else
            cout<<"YES"<<" "<<s3<<endl;
            flag=1;
            break;
           }
        }
        if(flag==0)
        cout<<"NO"<<endl;


    }
    return 0;
}