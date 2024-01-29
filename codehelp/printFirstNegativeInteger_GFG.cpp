vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
        deque<int> q1; 
        vector <long long> ans; 
                                                 
        for(int i=0;i<K;i++){
            
            if(A[i] < 0)
            {
                if(q1.empty()){
                    ans.push_back(A[i]);
                }
                q1.push_back(i);
                
            }
            
        }
         if(q1.empty()){
                    ans.push_back(0);
                }
        
        int j = K; 
        while(j<N){
            int frontIndex = -1; 
            if(!q1.empty())
             frontIndex = q1.front(); 
            if(A[j] < 0)
            q1.push_back(j);
            if(j-K == frontIndex){
                q1.pop_front(); 
            }
            if(!q1.empty())
                ans.push_back(A[q1.front()]);
            else 
                ans.push_back(0); 
            
            j++; 
        }
            
        return ans; 
        
                                                 
 }
