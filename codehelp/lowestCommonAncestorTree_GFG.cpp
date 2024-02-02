 
bool getAncestors(Node* root, int n, vector <Node* > &ac){
    if(root==NULL){
        return false; 
    }
    
    else if(root->data == n)
    {
        ac.push_back(root); 
        return true; 
    }
     
    bool left = getAncestors(root->left, n, ac); 
    bool right = getAncestors(root->right, n, ac); 
    
    if(left)
    ac.push_back(root); 
    else if(right)
     ac.push_back(root); 
    
}

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       vector <Node*> ac1; 
       vector <Node*> ac2; 
        
        getAncestors(root, n1, ac1); 
        getAncestors(root, n2, ac2); 
        
        Node * temp = NULL; 
        
        for(int i=0;i<ac1.size();i++){
            int flag = 0; 
            for(int j=0;j<ac2.size();j++){
                if(ac1[i]->data==ac2[j]->data){
                    temp = ac1[i]; 
                    flag = 1; 
                    break; 
                }
                
            }
            if(flag)
            break;
        }
        
        return temp; 
       
    }
};
