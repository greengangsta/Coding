struct info {
        int mini; 
        int maxi; 
        int size;
        bool isBST; 
};

struct info largetBstTraversal(TreeNode *root, int &maxSize) {
    struct info info1; 
    if (root == NULL) {
       
        info1.mini = INT_MAX; 
        info1.maxi = INT_MIN; 
        info1.isBST = true; 
        info1.size = 0; 
        return info1; 
    }
  
  struct info leftSubTree = largetBstTraversal(root->left, maxSize); 
  struct info rightSubTree = largetBstTraversal(root->right, maxSize);

  info1.mini = min(root->data, leftSubTree.mini); 
  info1.maxi = max(root->data, rightSubTree.maxi); 
  info1.size = leftSubTree.size + rightSubTree.size + 1;

  if (root->data > leftSubTree.maxi && root->data < rightSubTree.mini && leftSubTree.isBST && rightSubTree.isBST) {
        info1.isBST = true; 
        maxSize = max( maxSize, info1.size); 
  }

  else {
        info1.isBST = false; 
  }


  return info1; 
}
int largestBST(TreeNode * root){
    // Write your code here.
    int maxSize = 0;
    struct info info1 = largetBstTraversal(root, maxSize);
    
    return maxSize; 
}
