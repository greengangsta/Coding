class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int> ans; 
    	queue <Node*> q; 
    	if(root==NULL)
    	   return ans; 
    	q.push(root); 
    	bool direction = true;
    	
    	while(!q.empty()){
    	    int size = q.size(); 
    	    vector<int> temp(size);
    	    for(int i=0;i<size;i++){
    	        Node* frontNode = q.front();
    	        q.pop();
    	        if(frontNode->left)
    	            q.push(frontNode->left); 
    	        if(frontNode->right)
    	            q.push(frontNode->right); 
    	        if(direction){
    	            temp[i] = frontNode->data; 
    	        }
    	        else{
    	            temp[size-i-1] = frontNode->data; 
    	        }
    	            
   	        }
           direction = !direction;
           for(auto i:temp){
               ans.push_back(i);
           }
    	}
    	
    	
    	return ans; 
    }
};
