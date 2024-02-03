pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.
    int s = -1; 
    int p = -1; 

    TreeNode *temp = root;

    while (temp && temp->data != key) {
        
        if (temp->data > key)
        {
            s = temp->data; 
            temp = temp->left;
        } 
        else {
             p = temp->data;
             temp = temp->right; 
        }
            
    }


    TreeNode *leftSub = NULL; 
    TreeNode *rightSub = NULL;

    if (temp) {
        leftSub = temp->left; 
        rightSub = temp->right; 
    }

    while (leftSub != NULL) {
        p = leftSub->data; 
        leftSub = leftSub->right; 
    }

    while (rightSub != NULL) {
        s = rightSub->data; 
        rightSub = rightSub->left; 
    }

    return make_pair(p,s); 
}
