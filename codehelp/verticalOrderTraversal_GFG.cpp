
class Solution
{
    
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        map <int, vector<int>> mp; 
        
        queue<pair<Node*, int> > q; 
        q.push(make_pair(root, 0)); 
        while(!q.empty())
        {
            pair<Node*, int> p = q.front(); 
            q.pop();
            int distance = p.second; 
            mp[distance].push_back(p.first->data);
            if(p.first->left) 
            q.push(make_pair(p.first->left, distance -1)); 
            if(p.first->right) 
            q.push(make_pair(p.first->right, distance + 1)); 
            
            
        }
        
        vector <int> ans; 
        for(auto it: mp){
            // cout<<it.first<<" ";
            for(auto j: it.second){
                ans.push_back(j);
            }
        }
        
        return ans; 
    }
};
