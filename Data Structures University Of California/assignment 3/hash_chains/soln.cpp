#include<bits/stdc++.h>
using namespace std;

struct node
{
    string c;
    node* next;
};

int power(int a,int i)
{
    int mod=1000000007;
    while(i--)
     a*=a%mod;
    return a;
}

int cal_hash(string s)
{
    int mod=1000000007;
    int l =s.length();
    int val=0;
    for(int i=0;i<l;i++)
    {
      val+=((int)s[i]*power(263,i))%mod;
    }
    return val;
}
int main()
{
	
	int n;
    int m;
    cin>>m;
    cin>>n;
    node hash[m];
    for(int i=0;i<n;i++)
    {
        string q;
        cin>>q;
        if(q=="add")
        {
          string s;
          cin>>s;
          int id = cal_hash(s);
          int flag=0;
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
            a->next=hash[id]->next;
            hash[id]->c=s;
            hash[id]->next=a;
          }
          
        }
        else if(q=="del")
        {
            string s;
            cin>>s;
            int id = cal_hash(s);
            node *h ;
            h = &hash[id];
            while(h->c!=s && h->next!=NULL)
            {
               if(h->c==s)
                {
                  h->c= h->next->c;
                  h-next = h->next->next;
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
            int id = cal_hash(s);
            int flag=0;
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
              if(flag==0)
              cout<<"no"<<endl;
            }
            
        }
        else if(q=="check")
        {
            int a;
            cin>>a;
            node *h ;
            h = &hash[a];
            while(h->next!=NULL)
            {
                cout<<h->c<<" ";
            }
            cout<<endl;
        }
        
    }
	
	
	return 0;
}