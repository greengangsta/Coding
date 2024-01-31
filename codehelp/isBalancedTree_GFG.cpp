pair <bool, int> isBalancedHeight(Node* root, int height){
    if(root == NULL ){
        return make_pair(true, 0); 
    }
    
    pair <bool, int> left = isBalancedHeight(root->left, height); 
    pair <bool, int> right = isBalancedHeight(root->right, height); 
    
    int heightLeft = left.second; 
    int heightRight = right.second; 
    
    bool heightCheck = false; 
    if(heightLeft >= heightRight && heightLeft- heightRight <=1 )
        heightCheck = true; 
    else if (heightLeft <= heightRight && heightRight - heightLeft <=1 )
        heightCheck = true;
        
    return make_pair(heightCheck && left.first && right.first, 1 + max(heightLeft, heightRight));
    
    
    
}

class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //  Your Code here
        pair <bool, int> p1 = isBalancedHeight(root, 0); 
        // cout<<"p1.second"<<p1.second;
        return p1.first; 
    }
};
