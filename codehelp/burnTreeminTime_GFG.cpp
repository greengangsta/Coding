void inOrder(Node* root, map <Node*, Node* > &parentMapping, map <Node*, bool> &visited ){
    if(root==NULL){
        return; 
    }
    
    visited[root] = false; 
    if(root->left){
         parentMapping[root->left] =root; 
         inOrder(root->left, parentMapping, visited); 
         
    }
     if(root->right){
         parentMapping[root->right] =root; 
         inOrder(root->right, parentMapping, visited); 
         
    }
        
}

Node* findTarget(Node* root, int target){
    if(root==NULL)
    return NULL; 
    
    else if(root->data==target)
    return root; 
    
    Node* left =  findTarget(root->left, target); 
    Node* right = findTarget(root->right, target); 
    
    if(left)
    return left; 
    
    return right; 
}

class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map <Node*, bool> visited; 
        queue <Node* > q; 
        map <Node*, Node* > parentMapping; 
        
        parentMapping[root] =NULL; 
        inOrder(root, parentMapping, visited); 
        
        int timeTaken = 0; 
        
        Node* temp = findTarget(root, target); 
        q.push(temp); 
        visited[temp] = true;
        
        while(!q.empty()){
            
           int size = q.size(); 
           bool addition = false;
           for(int i=0;i<size;i++)
           {
              Node* frontNode = q.front(); 
              visited[frontNode] = true; 
               q.pop();
                if(frontNode->left && !visited[frontNode->left] ){
                    visited[frontNode->left] = true; 
                    q.push(frontNode->left); 
                    addition = true; 
                }
                
                if(frontNode->right && !visited[frontNode->right] ){
                    visited[frontNode->right]  = true; 
                    q.push(frontNode->right); 
                    addition = true; 
                }
                
                if(parentMapping[frontNode] && !visited[parentMapping[frontNode]]){
                    visited[parentMapping[frontNode]] = true; 
                    q.push(parentMapping[frontNode]); 
                    addition = true; 
                }
           }
          if(addition){
              timeTaken++; 
          }
           
        }
        
        
        return timeTaken; 
        
        
    }
};
