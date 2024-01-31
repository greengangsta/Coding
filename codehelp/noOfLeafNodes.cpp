void traverse(BinaryTreeNode<int> *root, int &count){
    if(root==NULL){
        return; 
    }
    
    if(root->left == NULL && root-> right == NULL)
    count ++; 
    
    traverse(root->left, count); 
    traverse(root->right, count); 
    
}

int noOfLeafNodes(BinaryTreeNode<int> *root){
    // Write your code here.
    int count = 0; 
    traverse(root, count); 
    return count; 
    
}
