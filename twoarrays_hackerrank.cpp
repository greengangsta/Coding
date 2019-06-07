#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--) {
    int n,k;
    cin>>n>>k;
    int a[n],b[n];
    for(int i=0;i<n;i++)
     cin>>a[i];
    for(int i=0;i<n;i++)
     cin>>b[i];
    sort(a,a+n);
    sort(b,b+n,greater<int>());
    int flag=0;
    for(int i=0;i<n;i++){
      if (a[i] + b[i] < k) {
        cout<<"NO"<<endl;
        flag=1;
        break;
        }
    }
    if (flag == 0) {
      cout << "YES" << endl;
    }
    }

    return 0;
}