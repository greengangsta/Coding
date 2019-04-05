#include<bits/stdc++.h>
using namespace std;

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       string s;
       long long int sum=0,total;
       char x;
       cin>>s;
       cin>>x;
       int j=0,k;
       for(int i=0;i<s.length();i++)
        {
            if(s[i]==x)
            {
             sum+=((i-j)*(i-j-1))/2;
             j=i;
            }
        }
        
       total = ((n)*(n+1))/2;
       cout<<total-sum<<endl;
          
   }
    
    return 0;
}