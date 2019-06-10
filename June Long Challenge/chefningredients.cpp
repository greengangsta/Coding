#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		unsigned long long int n,k,mod;
		mod = 1000000000+7;
		  cin>>n>>k;	   
		 cout<<((k%mod)*((k-1)%mod))/2)%mod<<endl;
		
	}

    
    return 0;
    
}