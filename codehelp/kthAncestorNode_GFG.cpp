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
int kthAncestor(Node* root, int k, int node)
{
    
    vector <Node*> ac1; 
    getAncestors(root, node, ac1); 
    int size = ac1.size();
    // for(int i=0;i<size;i++){
    //     cout<<ac1[i]->data<<" ";
    // }cout<<endl;
    if(size>k)
    {
            Node* temp = ac1[k]; 
             return temp->data; 
    }

   return -1; 
    // Code here
}
