#include<bits/stdc++.h>
using namespace std;

long long int gcd(long long int a, long long int b)
{
    if (a == 0) 
       return b; 
    if (b == 0) 
       return a; 
    if (a == b) 
       return a; 
    if (a > b) 
        return gcd(a-b, b); 
    return gcd(a, b-a); 
    
}

int main()
{
    long long int a,b;
    cin>>a>>b;
    long long int g;
    g  = gcd(a,b);
    int count = 0;
    for(long long int i = 1;i<=sqrt(g)+1;i++)
    {
        
         if (g%i == 0) 
        { 
            if (g/i == i) 
                count++;
  
            else 
               count+=2;
        } 
        

    }
    cout<<count<<endl;
    
    
    
    
    
    return 0;
}