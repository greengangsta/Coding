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
    int x,a,b;
    cin>>x>>a>>b;
    arr.erase(arr.begin()+x-1);
    arr.erase(arr.begin()+a-1,arr.begin()+b-1);
    cout<<arr.size()<<endl;
    for(auto it = arr.begin();it!=arr.end();it++)
     cout<<*it<<" ";
}

