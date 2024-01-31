class Solution {
private : 

pair<int,int>  diameterFast(Node* root){
    if(root==NULL){
        pair<int,int> p = make_pair(0,0); 
        return p; 
    }
    
    if(root->left == NULL && root->right==NULL){
        pair<int,int> p = make_pair(1,1); 
        return p; 
    }
     
    pair<int,int> leftDf = diameterFast(root->left); 
    
    pair<int,int> rightDf = diameterFast(root->right); 
    
    int comboD = 1 + leftDf.second + rightDf.second; 
    
    int maxD = max(comboD, max(leftDf.first, rightDf.first)); 
    
    int maxH = 1+  max(leftDf.second,rightDf.second );
    
    return make_pair(maxD, maxH);  
    
    
}
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        
        
      pair<int,int> p = diameterFast(root); 
      return p.first; 
    }
};
