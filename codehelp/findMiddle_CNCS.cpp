Node *findMiddle(Node *head) {
    // Write your code here

    Node* slow = head; 
    Node* fast = head;

    while (fast->next != NULL && fast->next->next!= NULL) {
        fast = fast->next;
        fast = fast->next;
        slow = slow->next; 
  
    }

    if (fast->next != NULL) {
        slow = slow->next; 
    }

    return slow; 
}
