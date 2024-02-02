void traverseDiagonal(Node* root, map <int, vector<int>> & mp, int distance){
    if(root==NULL){
        return; 
    }
    
    mp[distance].push_back(root->data);
    traverseDiagonal(root->left, mp, distance -1 ); 
    traverseDiagonal(root->right, mp, distance ); 
    
}


vector<int> diagonal(Node *root)
{
    map <int, vector<int>> mp; 
         traverseDiagonal(root, mp, 0 ); 
        vector <int> ans; 
        for(auto it= mp.rbegin(); it != mp.rend() ; it++){
          for(auto j: it->second){
              ans.push_back(j);
          }
        }
        
        
        return ans; 
}
