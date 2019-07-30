#include<bits/stdc++.h>
using namespace std;

int main()
{

    string s1, s2;
    cin>>s1>>s2;
    cout<<s1.length()<<" "<<s2.length();
    cout<<endl<<s1 + s2<<endl;
    char c,d;
    c = s1[0];
    d = s2[0];
    s1[0] = d;
    s2[0] = c;
    cout<<s1<<" "<<s2<<endl;
}