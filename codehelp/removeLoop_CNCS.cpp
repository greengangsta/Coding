Node *removeLoop(Node *head)
{
    // Write your code here.
    Node* slow = head ; 
    Node* fast = head ;
    Node* prev = NULL;


    if (head == NULL) {
        return head; 
    }


    // Detect Loop
    bool cycleDetected = 0; 
    while (fast->next != NULL && fast->next->next != NULL  ) {
        fast = fast->next;
        prev = fast ;
        fast=fast->next;
        slow = slow->next;

        if (fast==slow){
            cycleDetected = 1; 
            break;
        }
    }

   
   // find the starting point 
    Node* start = head ;
    while(start != slow && cycleDetected){
        start=start->next;
        prev = slow; 
        slow = slow->next;
        

    }

    if(cycleDetected)
        prev->next = NULL; 

    return head; 


}
