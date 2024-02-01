void traverseLeaves(Node* root, vector<int> &ans ){
    
    if(root->left== NULL && root->right == NULL){
        ans.push_back(root->data); 
        return; 
    }
    
    if(root->left)
    traverseLeaves(root->left, ans);
    if(root->right)
    traverseLeaves(root->right, ans);
}

void traverseLeft(Node* root, vector<int> &ans ){
    
    if(root== NULL || (root->left== NULL && root->right == NULL)){
        return; 
    }
    
    ans.push_back(root->data); 
    
    if(root->left)
    traverseLeft(root->left, ans);
    else 
    traverseLeft(root->right, ans);
}

void traverseRight(Node* root, vector<int> &ans ){
    
    if(root== NULL || (root->left== NULL && root->right == NULL)){
        return; 
    }
    
    if(root->right)
    traverseRight(root->right, ans);
    else 
    traverseRight(root->left, ans);
    ans.push_back(root->data); 
}
void print(vector<int> ans){
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }cout<<endl;
}

class Solution {
public:
    vector <int> boundary(Node *root)
    {
        //Your code here
        
        vector <int> ans; 
        if(root == NULL)
        {
            return ans; 
        }
        ans.push_back(root->data);
        
        if(root->left== NULL && root->right == NULL)
            return ans; 
        traverseLeft(root->left, ans); 
        traverseLeaves(root, ans); 
        traverseRight(root->right, ans); 
        
        return ans; 
    }
};
