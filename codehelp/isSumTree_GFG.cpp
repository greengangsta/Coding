pair <bool, int> solve(Node* root, int sum){
    if(root==NULL){
        return make_pair(true, 0); 
    }
    
    else if (root->left == NULL && root->right == NULL){
        return make_pair(true, root->data); 
    }
    
    pair <bool, int> left = solve(root->left, sum); 
    pair <bool, int> right = solve(root->right, sum); 
    
    bool checkSum = false; 
    
    if(root->data == left.second + right.second)
        checkSum = true; 
        
    return make_pair(checkSum && left.first && right.first, root->data + left.second + right.second); 
    
    
    
}
class Solution
{
    public:
    bool isSumTree(Node* root)
    {
         // Your code here
         pair <bool, int> p = solve(root, 0); 
         return p.first; 
         
    }
};
