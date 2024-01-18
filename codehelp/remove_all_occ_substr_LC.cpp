class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length()!= 0 && s.find(part)!= -1){
            int startIndex = s.find(part); 
            int partLength = part.length();
            s.erase(startIndex, partLength);
        }

        return s;
    }
};
