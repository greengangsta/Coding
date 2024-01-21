Node* solve(Node *head, int k) {

    if (head == NULL) {
        return NULL; 
    }

    int checkCount= 0;
    Node *checkCountNode = head;
    while (checkCount<k && checkCountNode != NULL) {
        checkCountNode = checkCountNode->next; 
        checkCount++; 
    }

    if (checkCount < k) {
        return head; 
    }

    int count = 0;
    Node *prev = head; 
    Node *curr = head;

    while (count < k && curr!=NULL) {
        Node* temp = curr->next; 
        curr->next = prev; 
        prev = curr;
        curr = temp; 
        count++;
    }
    
  
    Node* rightPart = solve(curr, k);

   head->next =  rightPart; 

   return prev; 

    
}
Node* kReverse(Node* head, int k) {
    // Write your code here.
    return solve(head, k); 
}
