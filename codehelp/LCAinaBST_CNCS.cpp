TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    // Write your code here.
    if (root == NULL) {
        return NULL; 
    }
    
    if((root->data >= P->data && root->data <= Q->data) || (root->data <= P->data && root->data >= Q->data))
        return root; 

    else if(root->data >= P->data && root->data >= Q->data)
        return LCAinaBST(root->left, P, Q);
    else 
        return LCAinaBST(root->right, P, Q);
}
