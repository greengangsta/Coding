class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        
        string temp = ""; 
        int i = S.length()-1; 
        string ans = ""; 
        while(i>=0){
            if(S[i]=='.'){
                reverse(temp.begin(), temp.end()); 
                ans += temp + '.'; 
                temp = ""; 
            }
            else {
                 temp +=S[i];
            }
           
            i--; 
            
        }
        reverse(temp.begin(), temp.end()); 
        ans += temp; 
        return ans; 
    } 
};
