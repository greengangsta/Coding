void inOrderTraversal(TreeNode<int>* root, vector<int> &sortedArray) {
    if(root==NULL)
        return; 
    inOrderTraversal(root->left, sortedArray);
    sortedArray.push_back(root->data);
    inOrderTraversal(root->right, sortedArray);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{

        vector<int> sortedArray;
        inOrderTraversal(root, sortedArray);
        int size = sortedArray.size(); 

        TreeNode<int> * newRoot = new TreeNode<int>(sortedArray[0]);
        TreeNode<int>* curr = newRoot; 

        for (int i = 1; i < size; i++) {
            TreeNode<int>* temp = new TreeNode<int>(sortedArray[i]);
            curr -> left = NULL; 
            curr->right = temp;
            curr = temp; 
        }

        curr->left = NULL; 
        curr->right = NULL; 

        return newRoot; 


    // Write your code here
}
