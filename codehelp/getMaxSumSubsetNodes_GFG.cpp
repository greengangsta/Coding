pair<int, int> traverseSubset(Node* root ){
    
    if(root== NULL){
        return make_pair(0,0); 
    }
    
    if(root->left ==NULL && root->right ==NULL){
        return make_pair(root->data, 0);
    }
    
    pair<int, int> left = traverseSubset(root->left); 
    pair<int, int> right = traverseSubset(root->right); 
    
    // include current
    int maxWithCurr = root->data + left.second + right.second; 
    
    // do not include currnt
    
    int leftData = max(left.first, left.second); 
    int rightData = max(right.first, right.second); 
    
    int maxWithoutCurr =leftData + rightData; 
    
    return make_pair(maxWithCurr, maxWithoutCurr);
    
}
    

class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        // Add your code here
        
        pair<int, int> p  = traverseSubset(root); 
        return max(p.first, p.second);
    }
};
