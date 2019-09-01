#include<bits/stdc++.h>
using namespace std;

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n,k;
       cin>>n>>k;
       unordered_set<int> s1;
       int a[n+1];
       for(int i=1;i<=n;i++)
       {
         s1.insert(i);
         a[i] = i;
       }
       int flag = 0;
       for(int i=1;i<=n;i++)
       {
           int x,y;
           x = abs(k+i);
           y = abs(i-k);
           if(s1.find(x)!=s1.end())
           {
             a[i] = x;
             s1.erase(x);
           }
           else if(s1.find(y)!=s1.end())
           {
              a[i] = y;
             s1.erase(y); 
           }
           else
           {
              flag  = -1;
              break; 
           }
       }
       if(flag==-1)
        cout<<flag<<endl;
       else
       {
           for(int i=1;i<=n;i++)
           {
               cout<<a[i]<<" ";
           }
         cout<<endl;
       }
   }






    return 0;
}