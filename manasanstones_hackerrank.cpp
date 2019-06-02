#include<bits/stdc++.h>
using namespace std;

int main()
{ 
   int t;
   cin>>t;
   while(t--)
   {
       int n,a,b;
       cin>>n>>a>>b;
       unordered_set <int> s1,s2;
       s1.insert(0);
       int flag = 0;
       while(n--)
       {
           if(flag==0)
           {
           for(auto it = s1.begin();it!=s1.end();it++)
             {
                 s2.insert(it->value+a);
                 s2.insert(it->value+b)';'
             }
            flag=1;
           }
           else
           {
            for(auto it = s2.begin();it!=s2.end();it++)
             {
                 s1.insert(it->value+a);
                 s1.insert(it->value+b)';'
             }
            flag=0;
           }

       }
       int arr[n];
       if(flag==0)
        {
            int i=0;
         for (auto it = s2.begin(); it != s2.end(); it++)
          {
              arr[i] = it->value;
              i++;
          }
          sort(a,a+n);
          for(int i=0;i<n;i++)
           cout<<a[i]<<" ";
           cout<<endl;
        }
        else
        {
            int i=0;
         for (auto it = s1.begin(); it != s1.end(); it++)
          {
              arr[i] = it->value;
              i++;
          }
          sort(a,a+n);
          for(int i=0;i<n;i++)
           cout<<a[i]<<" ";
           cout<<endl;
        }
   }

    return 0;
}