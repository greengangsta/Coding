class Solution {
private:
    void solve(string digits, int index, vector<string> &ans, string output) {

        if(index >= digits.size()){
            if(output.length() == digits.size())
            {
                ans.push_back(output); 
            }
           
            return; 
        }

        int mapIndex = digits[index]-'0'; 

        string mapping[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string possible = mapping[mapIndex]; 


        for(int i=0;i<possible.length(); i++) {

              // case include  

              output.push_back(possible[i]); 

              solve(digits, index + 1, ans, output);

            
              // case exclude 
              output.erase(output.length()-1);
              solve(digits, index + 1, ans, output);
                    
            
        }


    }
public:
    vector<string> letterCombinations(string digits) {

            vector<string> ans; 
            if(digits.length() ==0)
            return ans;
            string output; 
            solve(digits, 0, ans, output); 
            return ans; 

    }
};
