#include<bits/stdc++.h>
using namespace std;
long long gpp(long long m) {
    long long a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
}
int main()
{
   long long int n,m;
   cin>>n>>m;
   long long int p,q,c;
   p = n%gpp(m);
    long long a= 0;
    long long b= 1;
    long long r= p;
    for (int i = 1; i < p; i++) {
        r = (a + b) % m;
        a = b;
        b= r;
    }
    cout<<r%m<<endl;
    
    
    return 0;
}