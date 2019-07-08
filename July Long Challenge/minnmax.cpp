#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp> 
using boost::multiprecision::cpp_int; 
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cpp_int n,k;
        cin>>n>>k;
        if(n>=k)
        {
            if(n%2!=0)
            {
                if(k<=n-k)
                 cout<<2*k<<endl;
                else
                 cout<< 2*(n-k)<<endl;
            }
            else
            {
                if(k==n-k)
                 cout<<(2*k) - 1<<endl;
                else if (k < n-k)
                 cout<< 2*k <<endl;
                else
                 cout<< 2*(n-k)<<endl;
                
            }
        }
        else
        {
            k = k%n;
            if(n%2!=0)
            {
                if(k<=n-k)
                 cout<<2*k<<endl;
                else
                 cout<< 2*(n-k)<<endl;
            }
            else
            {
                if(k==n-k)
                 cout<<(2*k) - 1<<endl;
                else if (k < n-k)
                 cout<< 2*k <<endl;
                else
                 cout<< 2*(n-k)<<endl;
                
            }
            
        }
        
    }
    
    
    
    
    return 0;
}