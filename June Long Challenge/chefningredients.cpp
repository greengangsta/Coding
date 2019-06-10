#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	
	int t;
	cin>>t;
	while(t--)
	{
		unsigned long long int n,k,mod,c11,c12;
		mod = 1000000007;
		cin>>n>>k;
        
		if(n+k-1>=(2*k)-1)
		cout<<k-1<<endl;
		else
		{
			unsigned long long int sum=0;
			sum+= k-1;
			k = k-n;
			k = ((k%mod)*((k+1)%mod))%mod;
			sum+=k/2;
			cout<<sum<<endl;
			
		}
	}

    
    return 0;
    
}