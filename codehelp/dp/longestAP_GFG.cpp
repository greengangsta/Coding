class Solution{   
private: 
    int solve(int index, int A[],int d, unordered_map <int, int> mp[]){
        if (index < 0){
            return 0; 
        }
        
        int ans = 0; 
        
        if(mp[index].count(d) > 0){
            return mp[index][d];
        }
        
        for(int j = index-1;j>=0; j--){
            if(A[index] - A[j] == d){
                ans = max(ans, 1 + solve(j, A, d, mp)); 
            }
        }
        
        
        return mp[index][d]= ans; 
    }
public:
    int lengthOfLongestAP(int A[], int  n) {
        // code here
        
        vector <vector<int>> mp(n+1, vector<int>(A[n-1] - A[0] +1, INT_MIN)); 
        
        if(n < 3){
            return n; 
        }
        
        int ans = 0; 
        // for(int i=0;i<n;i++){
        //     for(int j=i+1; j<n;j++){
        //         ans = max(ans, 2+ solve(i, A, A[j]- A[i], mp));
        //     }
        // }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int count = 1; 
                
                int d = A[i] - A[j]; 
                
                if(mp[j][d]!=INT_MIN){
                    count= mp[j][d];
                }
                
                mp[i][d]= 1 + count; 
                ans = max(ans, mp[i][d]); 
            }
        }
        
        return ans; 
    }
};
