#include<bits/stdc++.h>
using namespace std;

long long int  fastpower(long long int  a,long long int  i)
{
    long long int  mod=1000000007; 
    long long int b=1;
     if(i==0)
      return 1;
     else if(i==1)
		return a;
	 else if(i%2==0)
		return ((fastpower(a,i/2)%mod)*(fastpower(a,i/2)%mod))%mod;
	 else
	    return ((a%mod)*((fastpower(a,i/2)%mod)*(fastpower(a,i/2)%mod))%mod)%mod;
		 
}

int main()
{
	long long int mod = 1000000000 + 7;	
	int t;
	cin>>t;
	while(t--)
	{
	   long long int k;
	   cin>>k;
	   int ans;
	   ans  = 10;
	   long long int fact;
	   fact = fastpower(2,k-1);
	   ans = ((ans%mod)*(fact%mod))%mod;
	   cout<<ans<<endl;
	   
    }
    
    
    
    return 0;
    
}