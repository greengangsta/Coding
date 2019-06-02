#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[101] = {0};
    for (int i = 0; i < n; i++) {
        int x;
        cin>>x;
        a[x]++;
    }
    for (int i = 0; i < 101; i++) {
      if (a[i] == 1) {
        cout << i << endl;
        break;
      }
    }

    return 0;
}
