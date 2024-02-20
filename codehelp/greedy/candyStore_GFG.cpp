

class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        vector<int> cd; 
        int n = N; 
        int k = K; 
        for(int i=0;i<n;i++){
            cd.push_back(candies[i]); 
        }
        
        sort(cd.begin(), cd.end()); 
        int mini = 0; 
        int maxi = 0; 
        int i=0; 
        int j = n-1; 

        while(i<=j){
            mini += cd[i]; 
            i++; 
            j = j - k; 
        }
        
        i =0; 
        j = n-1; 
        
         while(i<=j){
            maxi += cd[j]; 
            i = i+k; 
            j--; 
        }
        vector<int> ans; 
        ans.push_back(mini); 
        ans.push_back(maxi); 
        
        return ans; 
        
    }
};
