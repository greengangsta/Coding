#include<bits/stdc++.h>
using namespace std;

int bin_pos(int a[],int low,int high,int num)
{
   int mid = (low + high)/2;
    if(low == high)
    {
        return low;
    }
    if(a[mid]== num)
    {
        return mid;
    }
    else if(a[mid] > num)
    {
        return bin_pos(a,low,mid,num);
    }
    else
    {
       return bin_pos(a,mid+1,high,num);
    }
}

int main()
{ 
    int n,m;
    cin>>n;
    int a[n];
    unordered_set <int > s;
    for(int i = 0;i < n;i++)
     {
          int a;
          cin>>a;
          s.insert(a);
      }
    int k = 0;
    for(auto it= s.begin();it != s.end();it++)
     {
         a[k++] = *it;
     }
    sort(a,a+k);
   // for(int i=0;i<k;i++)
   //  cout<<a[i]<<" ";
    cin>>m;
    int b[m];
    for(int i=0;i<m;i++)
     cin>>b[i];
    for(int i = 0;i<m;i++)
    {
        cout<< k - bin_pos(a,0,k,b[i]) + 1;
        cout<<endl;
    }



    return 0;
}
