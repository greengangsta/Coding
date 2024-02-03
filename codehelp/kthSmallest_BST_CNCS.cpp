int  inOrder(BinaryTreeNode<int> *root, int &i, int k) {

    if (root == NULL) {
        return -1 ; 
    }
    int left = inOrder(root->left, i, k);

    if (left != -1) {
        return left; 
    }

    i++;

    if(i==k){
        return root->data; 
    } 
    return inOrder(root->right, i, k);
}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Write your code here.
    int i=0; 
    return inOrder(root,i,k);
}
