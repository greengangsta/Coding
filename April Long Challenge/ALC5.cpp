#include<bits/stdc++.h>
using namespace std;


long long int  gcd(long long int  a, long long int  b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
long long int  findGCD(long long int  arr[], long long int  n) 
{ 
    long long int  result = arr[0]; 
    for (long long int  i = 1; i < n; i++) 
        result = gcd(arr[i], result); 
  
    return result; 
} 

int main()
{
    long long int  t;
    cin>>t;
    while(t--)
    {
    long long int  n;
    cin>>n;
    long long int  p[n];
    unordered_set <long long int > s;
    for(long long int  i=0;i<n-1;i++)
    {
        long long int  x,y;
        cin>>x>>y;
        p[y-1] = x;
        s.insert(x);
    }
    p[0] = -1;
    long long int  v[n],m[n];
    for(long long int  i=0;i<n;i++)
      cin>>v[i];
    for(long long int  i=0;i<n;i++)
      cin>>m[i];
  /*  for(long long int  i=0;i<n;i++)
      cout<<p[i]<<" "<<v[i]<<" "<<m[i];
      cout<<endl;
      */
    for(long long int  i=0;i<n;i++)
     {
        // cout<<"chek 1 : "<<i+1<<endl;
         if(s.find(i+1)==s.end())
         {
             long long int  temp[n];
             long long int  y=0;
           //  cout<<"check"<<i+1<<endl;
             long long int  j = i;
             long long int  sum=0;
             while(p[j]!=-1)
             {
                sum+=v[j];
                temp[y++]=v[j];
                j = p[j]-1;
             }
             sum+=v[0];
             temp[y++]=v[0];
             temp[y++]=m[i];
            // cout<<sum<<endl;
             if(sum%m[i]==0)
             cout<<0<<endl;
             else
             {
                 long long int  max = m[i] - findGCD(temp,y);
                 cout<<max<<endl;
             }
            /* cout<<"values in the temp array are"<<endl;
             for(long long int  i=0;i<y;i++)
              cout<<temp[i]<<" ";
              */
         }
         else
         {
             //continue;
         }
     }
  }
  
    return 0;
}