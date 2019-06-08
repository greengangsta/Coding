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
         int a[n],b[n];
         int k=0;
         for (int i=1; i <=n; i++) 
         {
           if (i % 3 == 0)
           {
              a[k] =i;
              b[k] =n-i;
              k++;
           }
         }
         int max =-1;
         int flag=0;
         for (int i = 0; i < k; i++) 
         {
             if(b[i]%5==0)
             {
                 if(a[i]>max)
                 max = a[i];
                 flag=1;
             }
             if (i == k-1 && flag == 0) {
                 max=0;
             }
         }
        if(max==-1||(n-max)%5!=0)
        {
            cout<<-1<<endl;
        }
        else
        {
            string s1 = "", s2 = "";
            for (int i = 0; i < max; i++)
              s1 += "5";
            for (int i = max; i < n; i++)
              s2 += "3";
            s1 += s2;
            cout << s1 << endl;
        }
     }

    return 0;
}
