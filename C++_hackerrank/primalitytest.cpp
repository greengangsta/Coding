#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int is_prime(int n)
{
    int flag = 0;
    for(int i= 2;i<=sqrt(n);i++)
    {
       if(n%i==0)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n==2)
         cout<<"Prime"<<endl;
        else if(n==1)
         cout<<"Not prime"<<endl;
        
        else if(is_prime(n)==0)
         cout<<"Prime"<<endl;
         else
         {
             cout<<"Not prime"<<endl;
         }
    }


    return 0;
}
