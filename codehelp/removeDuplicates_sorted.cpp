Node *removeDuplicates(Node *head)
{
    Node * curr = head->next;
    Node * prev = head;
    unordered_set<int> nodeSet;

    if(head->next == NULL || head == NULL){
        return head; 
    }

    nodeSet.insert(prev->data);

    while (curr != NULL) {
        if(nodeSet.find(curr->data) == nodeSet.end()){
            nodeSet.insert(curr->data);
            prev = curr; 
            curr = curr->next; 
        }
        else {
            prev->next = curr->next; 
            Node* delNode = curr; 
            curr = curr->next; 
            delete(delNode);
            
        }
 
    }

    // Write your code here

    return head; 
}
