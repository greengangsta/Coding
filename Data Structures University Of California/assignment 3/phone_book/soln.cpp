#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	int n;
	cin>>n;
	unordered_map <int,string> mp;
	for(int i=0;i<n;i++)
	{
	  string s,q;
	  int a;
	  cin>>s;
	  if(s=="add")
	  {
	  	cin>>a;
	  	cin>>q;
	    auto it = mp.find(a);
	    if(it==mp.end())
     	mp.insert({a,q});
     	else
     	it->second=q;
	
	  }
	  else if(s=="find")
	  {
	  	cin>>a;
	  	auto it = mp.find(a);
	  	if(it!=mp.end())
	  	cout<<it->second<<endl; 
	  	else
	  	cout<<"not found"<<endl;
	  }
	  else
	  {
	  	cin>>a;
	  	mp.erase(a);
	  }
	  
	
	}
	
	
	
	return 0;
}