#include <bits/stdc++.h>
using namespace std;


int main() {
    int n,q;
    cin>>n>>q;
    vector <int> arr[n];
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        for(int j=0;j<k;j++)
        {
            int num;
            cin>>num;
            arr[i].push_back(num);
        }
    }
    for(int i=0;i<q;i++)
    { 
        int j,k;
        cin>>j>>k;
        cout<<arr[j][k]<<endl;
    }
}

