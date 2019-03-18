#include<bits/stdc++.h>
using namespace std;

struct node
{
    string c;
    node* next;
};

long long int  power(long long int  a,long long int  i)
{
    long long int b=1;
    while(i>0)
    {
	 b=b*a;
	 i--;
    }
    return b;
}

long long int  cal_hash(string s)
{
    long long int  mod=1000000007;
    long long int  l =s.length();
    long long int  val=0;
    for(long long int  i=0;i<l;i++)
    {
      long long int p;
      p = (int)s[i];
      val+= p*power(263,i);
    }
    return val%mod;
}
int  main()
{
	
	long long int  n;
    long long int  m;
    cin>>m;
    cin>>n;
    node temp;
    temp.c="";
    temp.next=NULL;
    node hash[m]={temp};
    for(long long int  i=0;i<n;i++)
    {
        string q;
        cin>>q;
        if(q=="add")
        {
          string s;
          cin>>s;
          long long int  id = cal_hash(s)%m;
          long long int  flag=0;
          node *h ;
          h = &hash[id];
          while(h->c!=s && h->next!=NULL)
          {
              if(h->c==s)
               {
                   flag=1;
                   break;
               }
              h =h->next;
          }
          if(flag!=1)
          {
            h=&hash[id];
            node* a = new node;
            a->c=h->c;
            a->next=h->next;
            h->c=s;
            h->next=a;
          }
          
        }
        else if(q=="del")
        {
            string s;
            cin>>s;
            long long int  id = cal_hash(s)%m;
            node *h ;
            h = &hash[id];
            while(h->c!=s && h->next!=NULL)
            {
               if(h->c==s)
                {
                  h->c= h->next->c;
                  h->next = h->next->next;
                  h->next->c = "\0";
                  h->next->next = NULL;
                }
                h =h->next;
            }
            
        }
        else if(q=="find")
        {
            string s;
            cin>>s;
            long long int  id = cal_hash(s)%m;
            long long int  flag=0;
            node *h ;
            h = &hash[id];
            while(h->c!=s && h->next!=NULL)
            {
              if(h->c==s)
               {
                  cout<<"yes"<<endl;
                  flag =1;
                  break;
               }
               h = h->next;
            }
              if(flag==0)
              cout<<"no"<<endl;
            
            
        }
        else if(q=="check")
        {
            long long int  a;
            cin>>a;
            node *h ;
            h = &hash[a];
            while(h->next!=NULL)
            {
                cout<<h->c<<" ";
                h = h->next;
            }
            cout<<endl;
        }
        
    }
	
	
	return 0;
}
