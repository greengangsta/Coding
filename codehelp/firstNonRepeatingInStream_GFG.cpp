
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    int alphas[26] = {0};
		    queue <char> q1;
		    string ans = ""; 
		    for(int i=0;i<A.length();i++){
		        alphas[A[i]-'a']++; 
		        q1.push(A[i]); 
		        while(!q1.empty() && alphas[q1.front()-'a'] > 1){
		            q1.pop();
		        }
		        if(q1.empty())
		            ans += '#';
		        else 
		            ans += q1.front();
		    }
		    return ans; 
		}

};

