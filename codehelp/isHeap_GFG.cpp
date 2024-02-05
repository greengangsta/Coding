void nodeCount(Node* root, int &count){
    
    if(root==NULL){
        return; 
    }
    nodeCount(root->left, count); 
    count++;
    nodeCount(root->right, count); 
}

bool isCBT(Node* root, int index, int count){
    if(root==NULL){
        return true; 
    }
    
    else if(index >= count){
        return false; 
    }
    
    int leftIndex = 2*index + 1; 
    int rightIndex = 2*index + 2; 
    
    return isCBT(root->left, leftIndex , count) && isCBT(root->right, rightIndex, count); 
    
}

bool isMaxHeap(Node* root){
    
    if(root==NULL){
        return true; 
    }
    
   if(root->left==NULL && root->right == NULL){
        return true; 
    }
    
    if(root->left && root->data < root->left->data ){
            return false; 
    }
     
    else if(root->right && root->data < root->right->data ){
            return false; 
    }
    
    return isMaxHeap(root->right) && isMaxHeap(root->left);  

}

class Solution {
  public:
    bool isHeap(struct Node* tree) {
        int count = 0;
        int index = 0; 
        nodeCount(tree, count);
        return isCBT(tree, index, count) && isMaxHeap( tree);
        
    }
};
