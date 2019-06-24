#include<bits/stdc++.h>
using namespace std;


int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int l;
       cin>>l;
       string s1,s2;
       cin>>s1;
       cin>>s2;
       
       int sum = 0;
       
       int flag=0;
       for(int i=0;i<l;i++)
       {
           if(flag==1)
           {
               flag=0;
               continue;
           }
           else if(s1[i]==s2[i])
           {
               sum++;
           }
           else if(s2[i]=='N')
           {
              continue; 
           }
           else
           {
            flag = 1;   
           }
       }
       cout<<sum<<endl;
       
       
   }
    
    
    return 0;
}