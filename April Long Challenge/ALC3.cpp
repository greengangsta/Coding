#include<bits/stdc++.h>
using namespace std;

struct node{
    int a;
    int b;
};
bool cmp(node x,node y)
{
    if(x.a>y.a)
      return x.a<y.a;
    else if(x.a==y.a)
      return x.b<y.b;
}

int cmp2 (node x, node y)
{
    if(x.a==y.a&&x.b==y.b)
      return 1;
    return 0;
}

int binary_search(node pairs[],node x,int l,int r)
{
    if(l<=r)
    {
    if(cmp2(x,pairs[l])||cmp2(x,pairs[r]))
     return 1;
    int mid =l + (r-l)/2;
    if(cmp2(x,pairs[mid]))
      return 1;
    else if(x.a<pairs[mid].a)
      binary_search(pairs,x,l,mid-1);
    else if(x.a>pairs[mid].a)
      binary_search(pairs,x,mid+1,r);
    else if(x.a==pairs[mid].a)
    {
        if(x.b<pairs[mid].b)
        binary_search(pairs,x,l,mid-1);
        else
        binary_search(pairs,x,mid+1,r);
    }
    }
    else
     return 0;
}

int main()
{
     int t;
     cin>>t;
     while(t--)
      {
        long long int n,m,k,j=0,x=0;
        cin>>n>>m>>k;
        node pairs[k],np[4*k],np1[4*k];
        for(int i=0;i<k;i++)
         cin>>pairs[i].a>>pairs[i].b;
         sort(pairs,pairs+k,cmp);
       //  for(int i=0;i<k;i++)
       //  cout<<pairs[i].a<<","<<pairs[i].b<<" ";
       //  cout<<endl;
        int sum=0;
        for(int i=0;i<k;i++)
        {
            node n1,n2,n3,n4;
            int p,q;
            p = pairs[i].a;
            q = pairs[i].b;
            n1.a = p-1;
            n1.b = q;
            n3.a = p+1;
            n3.b = q;
            n2.a = p;
            n2.b = q+1;
            n4.a = p;
            n4.b = q-1;
            if(binary_search(pairs,n1,0,k-1))
             sum++;
            else if(n1.a<=n&&n1.b<=m&&n1.a>0&&n1.b>0)
             {
                 //cout<<"check 1";
                 np[j]=n1;
                 j++;
             }
            if(binary_search(pairs,n2,0,k-1))
             sum++;
            else if(n2.a<=n&&n2.b<=m&&n2.a>0&&n2.b>0)
             {
                // cout<<"check 2";
                np[j]=n2;
                j++;
             }
            if(binary_search(pairs,n3,0,k-1))
             sum++;
            else if(n3.a<=n&&n3.b<=m&&n3.a>0&&n3.b>0)
             {
                // cout<<"check 3";
              np[j]=n3;   
              j++;
             }
            if(binary_search(pairs,n4,0,k-1))
             sum++;
            else if(n4.a<=n&&n4.b<=m&&n4.a>0&&n4.b>0)
             {
                // cout<<"check 4";
                 np[j]=n4;
                 j++;
             }
        }
        sort(np,np+j,cmp);
        for(int i=0;i<j;i++)
          {
              if(cmp2(np[i],np[i+1]))
              {
                  continue;
              }
              else
              {
                  np1[x++]=np[i];
              }
          }
         int sum2=0;
        for(int i=0;i<x;i++)
        {
            node n1,n2,n3,n4;
            int p,q;
            p = np1[i].a;
            q = np1[i].b;
            n1.a = p-1;
            n1.b = q;
            n2.a = p;
            n2.b = q+1;
            n3.a = p+1;
            n3.b = q;
            n4.a = p;
            n4.b = q-1;
            if(binary_search(np1,n1,0,x-1))
             sum2++;
            if(binary_search(np1,n2,0,x-1))
             sum2++;
            if(binary_search(np1,n3,0,x-1))
             sum2++;
            if(binary_search(np1,n4,0,x-1))
             sum2++;
        }
       // cout<<x<<" "<<sum2<<endl;
        int plants = 4*k-sum;
        int weeds = 4*x - sum2;
       // for(int i=0;i<x;i++)
      //  cout<<np1[i].a<<" "<<np1[i].b<<endl;
        if(m*n-k>x)
         cout<<plants<<endl;
         else
        cout<<min(plants,weeds)<<endl;
      }
       
       /*
         
         
       */
    
    return 0;
}