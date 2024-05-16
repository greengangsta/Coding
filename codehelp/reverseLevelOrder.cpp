//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

vector<int> reverseLevelOrder(Node* root);

int main()
{

    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        vector<int> result = reverseLevelOrder(root);
        for (int i = 0; i < result.size(); ++i)
        {
            cout<<result[i]<<" ";
        }
        cout<<endl;
    }
    return 1;
}
// } Driver Code Ends


/*   
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
vector<int> reverseLevelOrder(Node *root)
{
    // code here
    queue <Node* > q; 
    vector<int> ans; 
    vector<vector<int>> temp1; 
     q.push(root); 
    vector<int> temp2; 
     while(!q.empty()){
         int size = q.size();
         for(int i=0;i<size;i++){
             Node * front = q.front(); 
             q.pop(); 
             temp2.push_back(front->data); 
             if(front->left){
                 q.push(front->left); 
             }
             if(front->right){
                 q.push(front->right); 
             }
             
         }
        //  for(int i=0;i<temp2.size(); i++){
        //      cout<<temp2[i]<<" "; 
        //  }
        //  cout<<endl; 
         temp1.push_back(temp2); 
         temp2.clear(); 
        
         
     }
     
//   
     for(int i=temp1.size()-1; i>=0;i--){
         for(int j=0;j<temp1[i].size(); j++){
             ans.push_back(temp1[i][j]);
         }
     }
    //  reverse(ans.begin(), ans.end()); 
     return ans; 
}a
