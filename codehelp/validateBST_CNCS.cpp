bool checkBST(BinaryTreeNode<int> *root, int min, int max) {

    if (root == NULL) {
            return true;
    }

    if(root->data >= min && root->data <= max){
         bool leftAns = checkBST(root->left, min, root->data);
         bool rightAns = checkBST(root->right, root->data, max);
         return (leftAns && rightAns);

    }

    else {
         return false;
    }
}

bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
   
    return checkBST(root, INT_MIN, INT_MAX); 
}
