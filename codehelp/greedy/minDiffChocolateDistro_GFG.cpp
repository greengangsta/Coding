
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    
    sort(a.begin(), a.end()); 

    long long i=0; 
    long long j = m-1; 
    
    long long mini = a[j] - a[i]; 
    while(j<n-1){
        
        i++; 
        j++; 
        mini = min(mini, a[j] - a[i]);
        
    }
    
    return mini; 
    
    }   
};
=
