pair<int, int> traverseHeight(Node * root, int height, int sum){
    
    if(root == NULL){
        return make_pair(0,0);
    }
    
    else if(root->left == NULL && root->right == NULL){
        return make_pair(height + 1, sum + root->data); 
    }
    
    pair<int, int> left = traverseHeight(root->left, height + 1, sum + root->data); 
    pair<int, int> right = traverseHeight(root->right, height + 1, sum + root->data); 
    
    if (left.first > right.first){
        return left; 
    }
    
    else if(left.first == right.first){
        if(left.second > right.second)
        return left; 
        else 
        return right; 
    }
    
    return right;
}

class Solution
{
public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        pair<int, int> ans  = traverseHeight(root,0, 0);
        return ans.second; 
    }
};
