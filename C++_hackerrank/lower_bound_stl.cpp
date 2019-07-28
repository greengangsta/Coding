#include <bits/stdc++.h>
using namespace std;


int main() {
    
    int n;
    cin>>n;
    vector <int> arr;
    for(int i=0;i<n;i++)
    {
      int num;
      cin>>num;
      arr.push_back(num);
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        int num;
        cin>>num;
        auto low = lower_bound(arr.begin(),arr.end(),num);
        if(*low==num)
         cout<<"Yes "<<low-arr.begin() + 1 <<endl;
        else
         cout<<"No "<<low - arr.begin() + 1<<endl;
    }
}

