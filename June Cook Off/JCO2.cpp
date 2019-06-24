#include<bits/stdc++.h>
using namespace std;

struct node{
int a;
int b;
};


bool cmp (node n1,node n2)
{
	return n1.b <= n2.b;
}


int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
	   
	   int n,m;
	   cin>>n>>m;
	   node arr[n];
	   for(int i=0;i<n;i++)
	   {
	   	cin>>arr[i].a;
	   	cin>>arr[i].b;
	   }
	   sort(arr,arr+n,cmp);	    		
	int sum=0;
	sum += arr[n-1].b;
	int i=n-1;
	while(arr[i].a==arr[i-1].a)
	{
		i--;
	}
//	for(int i=0;i<n;i++)
//	 cout<<arr[i].a<<" "<<arr[i].b<<endl;
	sum += arr[i-1].b;
	cout<<sum<<endl;
	
}

    
    return 0;
    
}