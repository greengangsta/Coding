int findIn(int in[], int start, int end, int val){
    
    for(int i=start;i<=end;i++){
        if(in[i] == val)
        return i; 
    }
    
    return -1; 
}
Node* buildTreeInPost(int in[], int post[], int &postIndex, int inStart, int inEnd, int arraySize){
    
    
    if( postIndex < 0 || inStart > inEnd){
        return NULL;
    }
    
    
    int rootData = post[postIndex--]; 
    
    Node * root = new Node(rootData); 

    int pos = findIn(in, inStart,inEnd , rootData);
    
    root->right = buildTreeInPost(in, post, postIndex, pos+1, inEnd, arraySize); 

    root->left= buildTreeInPost(in, post, postIndex, inStart, pos-1, arraySize); 
    
    
    return root; 
    
    
}

//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int postIndex = n-1; 
    
    Node * root = buildTreeInPost(in, post, postIndex, 0,n-1, n); 
    
    return root; 
    
}
