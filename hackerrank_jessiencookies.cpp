#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b)
{
   int *temp;
   *temp = *a;
   *a = *b;
   *b = *temp; 
}
void heapify(int a[],int i,int n)
{
   int min = i;
   int left = 2*i + 1;
   int right = 2*i + 2;
   if(a[left]<a[min] && left < n)
    min = left;
    if(a[right]<a[min] && right<n)
    min = right;
    if(min!=i)
    swap(a[i],a[min]);
    heapify(a,min,n);
}

void min_heap(int a[],int n)
{
    for(int i=n/2;i>0;i--)
    {
       heapify(a,i,n);
    }
}

int main()
{
  int n,k;
  cin>>n>>k;
  int a[n];
  for(int i=0;i<n;i++)
  {
      cin>>a[i];
  }
  min_heap(a,n);





    return 0;
}