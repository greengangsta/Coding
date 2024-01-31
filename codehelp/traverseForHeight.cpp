int traverseForHeight(Node* node, int h){
    if(node==NULL){
        return h; 
    }
    
    else if (node->left == NULL && node->right ==NULL){
        return h; 
    }
    
    int leftHeight = traverseForHeight(node->left, h+1); 
    int rightHeight = traverseForHeight(node->right, h+1); 
    
    return max(leftHeight,rightHeight ); 
}
class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
       return traverseForHeight(node, 1);
        
    }
};
