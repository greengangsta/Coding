#include<bits/stdc++.h>
using namespace std;

int subsum(vector<int> a)
{
  int n = a.size();
  int max_till_here = 0;
  int max_curr = 0;
  for(int i=0;i<n;i++)
  {
      max_curr += a[i];
      if(max_curr > max_till_here)
       max_till_here  = max_curr;
      else if(max_curr <0)#include<bits/stdc++.h>
using namespace std;

int subsum(vector<int> a)
{
  int n = a.size();
  int max_till_here = 0;
  int max_curr = 0;
  int count = 0;
  for(int i=0;i<n;i++)
  {
      max_curr += a[i];
      if(max_curr > max_till_here)
       max_till_here  = max_curr;
      else if(max_curr < 0)
       max_curr = 0 ;
    if(a[i]<0)
     count++;
  }
   if(count==n)
     {
         sort(a.begin(),a.end());
         max_till_here  = a[n-1];
     }

  return max_till_here;
}
int seqsum(vector<int> a)
{
  int n = a.size();
  int sum = 0;
  int count = 0;
  for(int i=0;i<n;i++)
   {
    if(a[i]>0)
    sum += a[i];
    else
    count++;
   }
   if(count==n)
     {
         sort(a.begin(),a.end());
         sum  = a[n-1];
     }
 return sum;
}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       vector<int> a(n);
       for(int i=0;i<n;i++)
        cin>>a[i];
       int sum1,sum2;
       sum1 = subsum(a);
       sum2 = seqsum(a);
       cout<<sum1<<" "<<sum2<<endl;
   }


    return 0;
}
       max_curr = 0;
  }
  return max_till_here;
}
int seqsum(vector<int> a)
{
  int n = a.size();
  int sum = 0;
  for(int i=0;i<n;i++)
   if(a[i]>0)
    sum += a[i];
 
 return sum;

}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       vector<int> a(n);
       for(int i=0;i<n;i++)
        cin>>a[i];
       int sum1,sum2;
       sum1 = subsum(a);
       sum2 = seqsum(a);
       cout<<sum1<<" "<<sum2<<endl;
   }


    return 0;
}