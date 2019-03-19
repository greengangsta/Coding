#include<bits/stdc++.h>
using namespace std;

string t,p;
long long int  fastpower(long long int  a,long long int  i)
{
    long long int  mod=100000000007; 
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
long long int  cal_hash(string s)
{
    long long int  mod=100000000007;
    int  l=s.length();
    long long int  val=0;
    for(int  i=0;i<l;i++)
    {
       int p;
       p = (int)s[i];
       val+=((p%mod)*(fastpower(1,i)%mod))%mod;
    }

    return val%mod;
}
int match(int j,string s2)
{
	for(int i=j,k=0;i<i+s2.length(),k<s2.length();i++,k++)
	{
		if(t[i]!=p[k])
			return 0;
	}
	return 1;
}
int main()
{
	cin>>p;
	cin>>t;
	int tl =t.length();
	int pl = p.length();
	vector <int> ans;
	char s[pl+1];
	long long int h,h1;
	h = cal_hash(p);
	for(int i=tl-1,j=0;i>tl -pl,j<pl;i--,j++)
		s[j]=t[i];
	s[pl]='\0';
	h1 = cal_hash(s);
	//cout<<h<<" "<<h1<<endl;
    long long int mod=100000000007;
	for(int i=tl-pl;i>=0;i--)
	{
	  if(h==h1)
	    {
		  if(match(i,p))
			  {
			      ans.push_back(i);
			      //cout<<i<<endl;
			  }
	    } 
	   long long int x =(((int)t[i+pl-1]%mod)*(fastpower(1,pl-1)%mod))%mod;
	  // cout<<x<<endl;
	   int y =(int)t[i-1];
	   h1 = ((h1-x)%mod + mod)%mod;
	   h1= (((h1%mod)*(1%mod))%mod + y)%mod;
	   
	 //  cout<<h1<<endl; 
	}
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)
	 cout<<ans[i]<<" ";
}


