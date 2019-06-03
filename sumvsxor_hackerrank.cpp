#include<bits/stdc++.h>
using namespace std;

int main()
{
   long long int n;
   cin>>n;
   long int count= 0;
   while(n)
     {
       if(n%2==0)
        count++;
       n/=2;
     }
   count=pow(2,count);
   cout<<count<<endl;

    return 0;
}