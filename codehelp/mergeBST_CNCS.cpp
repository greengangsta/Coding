void convertToDLL(TreeNode *root, TreeNode * &head) {
  if (root == NULL) {
      return ;
  }

   convertToDLL(root->right, head); 

   root->right = head;

   if(head)
   head->left = root; 

   head = root; 


   convertToDLL(root->left, head); 

}

TreeNode *mergeSortedLL(TreeNode *head1, TreeNode *head2) {

   TreeNode *head = NULL; 
   TreeNode *tail = NULL;

  while(head1 && head2)
  {
    if (head1->data < head2->data) {
            if (head == NULL) {

                head = head1; 
                tail = head1; 
                head1 = head1->right; 

            } else {
                tail->right = head1; 
                tail = head1; 
                head1 = head1->right; 
            }
    } else {
            if (head == NULL) {

                head = head2; 
                tail = head2; 
                head2 = head2->right;

            } else {
                tail->right = head2;
                tail = head2;
                head2 = head2->right;
            }
    }
  }

  while (head1) {
       tail->right = head1; 
       tail = head1; 
       head1 = head1->right; 
  }

    while (head2) {
       tail->right = head2; 
       tail = head2; 
       head2 = head2->right; 
  }

  return head; 
}

int countNodes(TreeNode *root) {
    int count = 0; 
    TreeNode *temp = root; 
    while(temp){
        count++; 
        temp = temp->right; 
    }

    return count; 
}

TreeNode *buildBSTfromSorted(TreeNode * &head, int n) {
    
    if(head == NULL || n <=0){
        return NULL; 
    }

    TreeNode *leftSub = buildBSTfromSorted(head, n/2);

    TreeNode * root = head; 

    root->left = leftSub; 

    head = head->right; 

    TreeNode * rightSub = buildBSTfromSorted(head, n - n/2 - 1);

    root->right = rightSub;

    return root; 

}

void inOrder(TreeNode *root, vector<int> &inOrderVector) {
    if(root==NULL)
        return; 

    inOrder(root->left,inOrderVector); 
    inOrderVector.push_back(root->data); 
    inOrder(root->right,inOrderVector); 
}

void printLL(TreeNode *root) {
    TreeNode * temp = root;
    while (temp != NULL) {
        cout<<temp->data<<" "; 
        temp = temp->right; 
    }cout<<endl;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // Write your code here.

    //convert into two sortedDLLs;

    TreeNode *head1 = NULL; 
    convertToDLL(root1, head1); 

    TreeNode *head2 = NULL; 
    convertToDLL(root2, head2); 

    //merge the two sorted DLLs; 

    TreeNode * head = mergeSortedLL(head1, head2); 


    // constrcut BST from a sorted LL; 

    int n = countNodes(head); 


    TreeNode * bst =  buildBSTfromSorted(head, n); 


    vector <int> inOrderVector; 

    inOrder(bst, inOrderVector); 
    
    return inOrderVector;


}
