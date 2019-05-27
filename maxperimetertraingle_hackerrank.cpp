#include <bits/stdc++.h>
using namespace std;

int main()
{
   long long int n;
   cin>>n;
   long long int a[n];
   long long int m[3],p;
   m[0]=m[1]=m[2]=p=0;
   for(long long int i=0;i<n;i++)
    cin>>a[i];
   for(long long int i=0;i<n;i++)
    {
        for(long long int j=i+1;j<n;j++)
        {
            for(long long int k=j+1;k<n;k++)
             {
                 if(a[i]+a[j]>a[k]&&a[j]+a[k]>a[i]&&a[i]+a[k]>a[j])
                 {
                     long long int np=a[i]+a[j]+a[k];
                     long long int na[3];
                     na[0] = a[i];
                     na[1] = a[j];
                     na[2] = a[k];
                     if(np>p)
                      {
                          p = np;
                          m[0]=a[i];
                          m[1] = a[j];
                          m[2]= a[k];
                      }
                     else if(p==np)
                     {
                       sort(na,na+3);
                       sort(m,m+3);
                       if(na[2]>m[2])
                       {
                           for(long long int x=0;x<3;x++)
                            m[x] = na[x];
                       }
                       else if(na[2]==m[2]&&na[0]>m[0])
                       {
                           for(long long int x=0;x<3;x++)
                            m[x] = na[x];
                       }
                     }
                 }
             }
        }
    }
    if (m[0] == m[1] && m[2]==m[1]&&m[2]==m[0]&&m[0]==0)
      cout << -1 << endl;
    else {
      sort(m, m + 3);
      for (long long int i = 0; i < 3; i++)
        cout << m[i] << " ";
      cout << endl;
    }

    return 0;
}