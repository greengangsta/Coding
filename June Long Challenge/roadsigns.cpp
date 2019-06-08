#include<bits/stdc++.h>
using namespace std;

int cnt(int k1,int k2)
{
	int dig[10]={0};
	do
	{
		int r =k1%10;
		dig[r] =1;
		k1/=10;
	}while(k1);
	do
	{
		int r =k2%10;
		dig[r] =1;
		k2/=10;
	}while(k2);
	int count=0;
	for(int i=0;i<10;i++)
	 if(dig[i]==1)
	  count++;

 return count;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	   int k;
	   cin>>k;
	   int n;
	   n = pow(10,k);
	   int a[n],b[n];
	   for(int i=0;i<n;i++)
	    {
	    	a[i] = i;
	    	b[i] = n-i-1;
		}
		int count = 0;
		for(int i=0;i<n;i++)
		{
			int c1,c2;
			c1 = cnt(a[i],b[i]);
			if(c1==2)
			{
		//	cout<<a[i]<<": "<<b[i]<<" | ";
			count++;
	     	}
		}
		cout<<count<<endl;
    }
    
    
    
    return 0;
    
}