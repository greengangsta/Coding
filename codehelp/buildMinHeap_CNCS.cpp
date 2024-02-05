#include <bits/stdc++.h>

void heapify(vector<int> &arr, int i, int n) {

   int smallest = i; 
   int left = 2*i + 1;
   int right = 2*i + 2;

   if ( left < n && arr[left] < arr[smallest]) {
     smallest = left; 
   }
   else if ( right < n && arr[right] < arr[smallest]) {
     smallest = right; 
   }

   if (smallest != i) {
       swap(arr[i], arr[smallest]); 
       heapify(arr, smallest, n); 
   }

}
vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
   int n = arr.size();
   for (int i = n/2 ; i >= 0; i--) {
       heapify(arr,i, n); 
   }
   
   return arr; 
}
