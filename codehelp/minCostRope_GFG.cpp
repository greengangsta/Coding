
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        long long sum = 0; 
        priority_queue <long long, vector<long long>, greater <long long>> pq; 
        
        for(int i=0;i<n;i++){
            pq.push(arr[i]); 
        }
        
        
        while(pq.size()!= 1){
            long long top1 = pq.top(); 
            pq.pop(); 
            long long top2 = pq.top(); 
            pq.pop(); 
            sum += (top1 + top2); 
            pq.push(top1 + top2); 
            
        }
        
        return sum; 
    }
};

