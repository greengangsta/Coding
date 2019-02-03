#include <bits/stdc++.h>
using namespace std;
long long int countDivisibles(long long int x, long long int y, long long int k) 
{ 
    if (x%k==0) 
        return (y/k)-(x/k) +1; 
    return (y/k)-(x/k); 
} 
long long int gcd(long long int a, long long int b)  
{ 
    if (a == 0 || b == 0)  
        return 0;  
    if (a == b)  
        return a;  
    if (a > b)  
        return gcd(a-b, b);  
    return gcd(a, b-a);  
}  
long long int lcm(long long int a,long long int b)  
{  
    return (a*b)/gcd(a, b);  
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        
    long long int n,a,b,k;
    cin>>n>>a>>b>>k;
    long long int c=lcm(a,b);
    long long int a1=countDivisibles(1,n,a);
    long long int b1=countDivisibles(1,n,b);
    long long int c1=countDivisibles(1,n,c);

   // cout<<a1<<" " <<b1<<" " <<c1<<" :"<<a1+b1-(2*c1)<<endl;
   
    if(a1+b1-(2*c1)>=k)
    cout<<"Win"<<endl;
    else
    cout<<"Lose"<<endl;
    
     
    }
}
