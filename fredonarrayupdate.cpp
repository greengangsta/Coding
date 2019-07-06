#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    int a[n];
    long long int sum = 0;
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
      sum += a[i];
    }
    int num = sum/n;
    cout<<num+1<<endl;
    
 
    
    
    return 0;
}