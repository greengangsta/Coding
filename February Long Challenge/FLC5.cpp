#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
     while(t--)
      {
          string s;
          cin>>s;
          long long int l=s.length();
          long long int min1[26]={0},k=0;
          long long int a[26]={0},d=0;
          for(long long int i=0;i<s.length();i++)
          {
              a[s[i]-'A']++;
          }
           for(long long int i=0;i<26;i++)
            if(a[i]!=0)
             d++;
          sort(a,a+26);
          for(int i=1;i<=26;i++)
          {
              if(l%i==0)
              {
               long long int c=0;
               int m1=l/i;
               for(int j=25;j>=26-i;j--)
               { 
                 if(a[j]<m1)
                 {
                    c+=abs(a[j]-m1); 
                 }
               }
              min1[k++]=c;
             }
             else
              continue;
              
          }
          long long int m=9223372036854775807;
          for(int i=0;i<k;i++)
          {
              if(min1[i]<m)
               m=min1[i];
          }
           cout<<m<<endl;
      
          
      }
       
    
    
    
    return 0;
}
