class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
         map <int, int> mp; 
        
        queue<pair<Node*, int> > q; 
        q.push(make_pair(root, 0)); 
        while(!q.empty())
        {
            pair<Node*, int> p = q.front(); 
            q.pop();
            int distance = p.second; 
            mp[distance] = p.first->data;
            if(p.first->left) 
            q.push(make_pair(p.first->left, distance -1)); 
            if(p.first->right) 
            q.push(make_pair(p.first->right, distance + 1)); 
            
            
        }
        
        vector <int> ans; 
        for(auto it: mp){
            // cout<<it.first<<" ";
                ans.push_back(it.second);
        }
        return ans;
    }
};
