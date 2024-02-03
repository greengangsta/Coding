int findIn(int in[], int start, int end, int val){
    
    for(int i=start;i<=end;i++){
        if(in[i] == val)
        return i; 
    }
    
    return -1; 
}
Node* buildTreeInPre(int in[], int pre[], int &preIndex, int inStart, int inEnd, int arraySize){
    
    
    if( preIndex >= arraySize || inStart > inEnd){
        return NULL;
    }
    
    
    int rootData = pre[preIndex++]; 
    
    Node * root = new Node(rootData); 

    int pos = findIn(in, inStart,inEnd , rootData);


    root->left= buildTreeInPre(in, pre, preIndex, inStart, pos-1, arraySize); 

    root->right = buildTreeInPre(in, pre, preIndex, pos+1, inEnd, arraySize); 
    
    return root; 
    
    
}

class Solution{
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preIndex = 0; 
        Node * root = buildTreeInPre(in, pre, preIndex, 0, n-1, n);
        return root; 
    }
};
