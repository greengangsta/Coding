BinaryTreeNode<int>* buildBST(vector<int> &preorder, int &index, int min, int max, int size)
{
    if(index >= size){
        return NULL;
    }

    int rootData = preorder[index];
    if (rootData >= min && rootData <= max) {
        BinaryTreeNode<int>* root = new BinaryTreeNode(rootData);
        index++; 
        root->left = buildBST(preorder,index, min, rootData, size); 
        root->right =  buildBST(preorder,index, rootData, max, size); 
       return root;
    } 
    else 
        return NULL; 
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    // Write your code here.
    int index = 0; 
    return buildBST(preorder,index, INT_MIN, INT_MAX, preorder.size()); 
}
