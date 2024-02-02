vector<int> leftView(Node *root)
{
   // Your code here
    map <int, int> mp; 
        
        queue<Node* > q; 
        q.push(root); 
       
        vector <int> ans; 
         if(root==NULL){
             return ans; 
         }
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
                
                if(i==0){
                     ans.push_back(frontNode->data);
                }
                
           }
        }

        return ans;
}
