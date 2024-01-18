class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int n = chars.size();
        int lastPos = 0; 
        while(i<n) {
            int j = i+1; 
            while(j<n && chars[j] == chars[i] ) {
                j++; 
            }

            int count = j-i; 
            chars[lastPos] = chars[i]; 
            lastPos++;
            if(count> 1){
                string countstring = to_string(count); 
                for (char ch:countstring ) {
                    chars[lastPos] = ch; 
                    lastPos++; 
                }
            }
           i = j; 
        }
        return lastPos; 
    }
};
