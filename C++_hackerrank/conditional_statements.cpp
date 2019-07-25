#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n;
    cin >> n;
    string a[10] = {"","one","two","three","four","five","six","seven","eight","nine"};
    if(n<=9)
     cout<<a[n];
    else
     cout<<"Greater than 9";

    return 0;
}
