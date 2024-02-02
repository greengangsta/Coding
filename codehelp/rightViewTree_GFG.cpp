class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
        map <int, int> mp; 
        
        queue<Node* > q; 
        q.push(root); 
        vector <int> ans; 
        while(!q.empty())
        {

            int size = q.size(); 
            for(int i=0;i<size;i++){
                Node* frontNode = q.front(); 
                q.pop();
                if(frontNode->left)
                q.push(frontNode->left);
                if(frontNode->right)
                q.push(frontNode->right);
                
                if(i==size-1){
                     ans.push_back(frontNode->data);
                }
                
           }
        }

        return ans;
    }
};
