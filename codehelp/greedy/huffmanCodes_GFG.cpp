class Node {

  public: 
    
    int data; 
    Node* left; 
    Node* right; 
    
    Node(int d){
        data = d; 
        left = NULL; 
        right = NULL; 
    }
    
}; 


class cmp{
    public : 
    bool operator ()(Node* a, Node* b){
        return a->data > b->data; 
    }
    
};

class Solution
{
    private : 
        void traverse(Node* root, vector <string> &ans, string temp){
            if(root->left== NULL && root->right==NULL){
                ans.push_back(temp); 
                return; 
            }
            
            traverse(root->left, ans, temp + '0'); 
            traverse(root->right, ans, temp + '1'); 
            
        }
	public:
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Code here
		    priority_queue<Node*,  vector<Node*>, cmp> pq; 
		    string s= S; 
		    int n = N; 
		    for(int i=0;i<n;i++){
		        Node *temp = new Node(f[i]); 
		        pq.push(temp); 
		    }
		    
		    while(pq.size()!= 1){
		        Node * top1 = pq.top(); 
		        pq.pop(); 
		        Node * top2 = pq.top(); 
		        pq.pop(); 
		        
		        Node* temp = new Node(top1->data + top2->data); 
		        temp->left = top1; 
		        temp->right = top2; 
		        pq.push(temp); 
		    }
		    
		    Node* root = pq.top(); 
		    vector <string> ans; 
		    string temp = ""; 
		    traverse(root, ans, temp);
		    
		    return ans; 
		}
};
