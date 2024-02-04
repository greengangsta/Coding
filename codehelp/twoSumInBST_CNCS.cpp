void inOrderTraversal(BinaryTreeNode<int>* root, vector<int> &sortedArray) {
    if(root==NULL)
        return; 
    inOrderTraversal(root->left, sortedArray);
    sortedArray.push_back(root->data);
    inOrderTraversal(root->right, sortedArray);
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
    // Write your code here.
    vector<int> sortedArray;
    inOrderTraversal(root, sortedArray);
    int i=0; 
    int j = sortedArray.size()-1;
    while (i < j) {
        int sum = sortedArray[i] + sortedArray[j];
        if(sum == target)
            return true; 
        else if(sum < target)
            i++; 
        else 
            j--; 
    }

    return false; 
}
