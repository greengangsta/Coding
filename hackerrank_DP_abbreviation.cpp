#include<bits/stdc++.h>
using namespace std;

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       string s1,s2;
       cin>>s1>>s2;
       int n = s1.length();
       int a[n] = {0};
       int j = 0;
       int a1[26] = {0},b1[26] = {0};
       for(int i=0;i<s1.length();i++)
       {
          if(isupper(s1[i]))
           a1[s1[i]-'A'] += 1;
       }
       for(int i=0;i<s2.length();i++)
       {
         if(isupper(s2[i]))
           b1[s2[i]-'A'] += 1;
       }
       for(int i=0;i<n;i++)
       {
           char c = toupper(s1[i]);
           if(s1[i]==s2[j])
           {
               a[i] = a[i-1]+1;
               j++;
           }
           else if(c ==s2[j])
           {
               j++;
               if(a[i-1]>0)
                a[i] = a[i-1] +1;
               else 
                a[i] = 1;
           }
           else
            a[i] = a[i-1];
       }
       int flag = 0;
       for(int i=0;i<n;i++)
       {
           if(a[i]==s2.length())
           {
               flag = 1;
           }
       }
       if(s1.length()<s2.length())
        flag = 0;
       for(int i=0;i<26;i++)
       {
           if(a1[i]>b1[i])
            flag = 0;
       }
       if(flag==1)
        cout<<"YES"<<endl;
       else
        cout<<"NO"<<endl;
      // for(int i=0;i<n;i++)
       // cout<<a[i]<<" ";
   }





    return 0;
}