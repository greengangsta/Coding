void heapify(vector<int> &arr, int i, int n) {

   int largest = i; 
   int left = 2*i + 1;
   int right = 2*i + 2;

   if ( left < n && arr[left] > arr[largest]) {
     largest = left; 
   }
   
   if ( right < n && arr[right] > arr[largest]) {
     largest = right; 
   }

   if (largest != i) {
       swap(arr[i], arr[largest]); 
       heapify(arr, largest, n); 
   }

}

class Solution{
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector <int> c; 
        for(int i=0;i<n;i++)
            c.push_back(a[i]); 
        for(int i=0;i<m;i++)
            c.push_back(b[i]); 
            
            // cout<<c.size(); 
        int size = n+m; 
            
       for (int i = size/2 ; i >= 0; i--) {
           heapify(c,i, size); 
       }
        return c; 
            
        
    }
};
