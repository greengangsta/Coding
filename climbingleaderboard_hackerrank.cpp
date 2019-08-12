#include<bits/stdc++.h>
using namespace std;


vector<int> bin_pos(int a[],int low,int high,int num)
{

   int mid = (low + high)/2;
    if(low == high)
    {
        vector<int> ans(2);
         ans[0] = low;
         ans[1] = 0;
        return ans;
    }
    if(a[mid]== num)
    {
         vector<int> ans(2);
         ans[0] = mid;
         ans[1] = 1;
        return ans;
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
         vector<int> ans(2);
        ans = bin_pos(a,0,k,b[i]);
        if(ans[1]==0)
         {
          cout<<k - ans[0] + 1;
         }
        else
        {
          cout<<k - ans[0];
        }
        cout<<endl;
    }



    return 0;
}
