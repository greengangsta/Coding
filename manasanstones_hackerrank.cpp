#include<bits/stdc++.h>
using namespace std;

int main()
{ 
   int t;
   cin>>t;
   while(t>0)
   {
       t--;
       int n,a,b;
       cin>>n>>a>>b;
     //  cout<<n<<" "<<a<<" "<<b;
       unordered_set <int> s1,s2;
       s1.insert(0);
       int flag=0;
       while(n>0)
       {
           n--;
           if(flag==0)
           {
           for(auto it = s1.begin();it!=s1.end();it++)
             {
                 s2.insert(*it+a);
                 s2.insert(*it+b);
                // cout<<"check : 1";
             }
             if(n!=0)
             s1.clear();
            flag=1;
           }
           else
           {
            for(auto it = s2.begin();it!=s2.end();it++)
             {
                 s1.insert(*it+a);
                 s1.insert(*it+b);
                // cout<<"check : 2";
             }
             if(n!=0)
             s2.clear();
            flag=0;
           }

       }
       int arr[n];
       if(flag==0)
        {
            int i=0;
         for (auto it = s2.begin(); it != s2.end(); it++)
          {
              arr[i] = *it;
              i++;
            //  cout<<"check : 3";
          }
          sort(arr,arr+i);
          for(int j=0;j<i;j++)
           cout<<arr[j]<<" ";
           cout<<endl;
        }
        else
        {
            int i=0;
         for (auto it = s1.begin(); it != s1.end(); it++)
          {
              arr[i] = *it;
              i++;
             // cout<<"check : 4";
          }
          sort(arr,arr+i);
          for(int j=0;j<i;j++)
           cout<<arr[j]<<" ";
           cout<<endl;
        }
   }

    return 0;
}
