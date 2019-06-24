#include<bits/stdc++.h>
using namespace std;

struct node1
{
    float r;
	int id;	
};


struct node{
int d;
int f;
int b;
};

bool cmp (node1 n1, node1 n2)
{
	return n1.r < n2.r;
}


int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
	   
	   int n,m;
	   cin>>n>>m;
	   int arr2[n][3];
	   int ans[n],k=0;
	   int arr1[m];
	   int count[m]={0};
	   for(int i=0;i<m;i++)
	    cin>>arr1[i];
	   for(int i=0;i<n;i++)
	    {
	    	cin>>arr2[i][0];
	    	cin>>arr2[i][1];
	    	cin>>arr2[i][2];
	    	count[arr2[i][0]-1]++;
		}
		node1 x[m];
		for(int i=0;i<m;i++)
		{
			if(count[i]==0)
			 x[i].r = (float)arr1[i];
			else
			x[i].r = (float)arr1[i]/(float)count[i];
			x[i].id = i+1;
		//	cout<<x[i].r<<" ";
		}
		
		sort(x,x+m,cmp);
	    int sum = 0;
	    int j=m-1;
	    for(int i=0;i<n;i++)
	    {
	       if(arr1[arr2[i][0]-1]>0)	
	       {
	       	sum += arr2[i][1];
	       	arr1[arr2[i][0]-1]--;
	       	ans[k] = arr2[i][0];
	       	k++;
	      //	cout<<"Condition 1"<<endl;
		   }
		   else
		   {
		   	 sum += arr2[i][2];
		   	 arr1[x[j].id-1]--;
		   	 ans[k] = x[j].id;
		   	 k++;
		   	 if(arr1[x[j].id-1]==0)
		   	   j--; 
		  //  	cout<<"Condition 2"<<endl;	 
		   }
		}
	      cout<<sum<<endl;
	      for(int i=0;i<n;i++)
	       cout<<ans[i]<<" ";
	      cout<<endl;
	
   }

    
    return 0;
    
}
