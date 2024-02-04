void inOrderTraversal(TreeNode<int> *root, vector<int> &sortedArray) {
    if(root==NULL)
        return; 
    inOrderTraversal(root->left, sortedArray);
    sortedArray.push_back(root->data);
    inOrderTraversal(root->right, sortedArray);
}

TreeNode<int> *buildBST(vector<int> &sortedArray, int start, int end) {

    if(start > end)
        return NULL; 

    int mid = start + (end - start)/2; 

    TreeNode<int> * root = new TreeNode(sortedArray[mid]); 

    root->left = buildBST(sortedArray, start, mid -1); 
    root->right = buildBST(sortedArray, mid+1, end); 

    return root; 

}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Write your code here.
    vector<int> sortedArray;
    inOrderTraversal(root, sortedArray);
    return buildBST(sortedArray, 0, sortedArray.size()-1);
   
}
