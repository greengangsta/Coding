class Solution{
public:
    int minimumDays(int S, int N, int M){
        // code here
        
        int sundays = S/7; 
        int bdays = S - sundays; 
        
        int totalFood = S*M; 
        int ans = 0; 
        if(totalFood%N==0){
            ans = totalFood/N; 
        }
        else {
            ans = (totalFood/N) + 1; 
        }
        
        if(ans <= bdays){
            return ans; 
        }
        
        return -1; 
    }
};
