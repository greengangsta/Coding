class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack <int> s1; 
        
        for(int i=0;i<n;i++){
            s1.push(i);
        }
        
        while(s1.size() > 1){
            int a = s1.top();
            s1.pop();             
            int b = s1.top();
            s1.pop(); 
            
            if(M[a][b]== 1 && M[b][a] ==0 ){
                s1.push(b);
            }
            else if(M[b][a]==1 && M[a][b]== 0) {
                s1.push(a);
            }


        }
        
        if(s1.empty())
        return -1; 
        
        int celeb = s1.top();
        int isCeleb = 1; 
        
        // checkRow 
        for(int i=0;i<n;i++){
            if(M[celeb][i] ==1)
            isCeleb = 0; 
        }
        // check column 
        for(int i=0;i<n;i++){
            if(i!= celeb && M[i][celeb] ==0)
             isCeleb = 0; 
        }

        
        if(isCeleb){
            return celeb; 
        }
        
        return -1;
    }
};
