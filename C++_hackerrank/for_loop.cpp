#include <bits/stdc++.h>

using namespace std;



int main()
{
    int a,b;
    cin >>a>>b;
    string s[10] = {"","one","two","three","four","five","six","seven","eight","nine"};
    for(int i=a;i<=b;i++)
    {
        if(i<=9)
         cout<<s[i];
        else if (i%2 == 0)
         cout<<"even";
        else
         cout<<"odd";
        cout<<endl;
    }
    return 0;
}
