Node<int>* insertAtTail(Node<int>* tail, Node<int>* newNode){

        if(tail == NULL){
            tail = newNode; 
        }
        else{
            tail->next = newNode; 
            tail = newNode; 
        }
        
        return tail; 
}

int getLength(Node<int>* head){
    Node<int>* temp = head; 
    int count = 0; 
    while(temp!=NULL){
        count++; 
        temp = temp->next; 
    }
    return count; 
}


Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.

    Node<int>* tail = NULL;

    Node<int>*  i = first; 
    Node<int>* j = second; 
    Node<int>* head = NULL; 

    int length1 = getLength(first);
    int length2 = getLength(second);

    int count1 = 0; 
    int count2 = 0; 


    while(count1 < length1 && count2< length2){
        if(i->data < j->data){

            tail = insertAtTail(tail, i); 
            i = i->next; 
            count1++; 
        }
        else {
            tail = insertAtTail(tail, j); 
            j = j->next;
            count2++;              
        }
        if(head == NULL){
            head = tail;
        }

    }

    while(count1 < length1){
        tail = insertAtTail(tail, i); 
        i = i->next; 
        count1++;
    }

    while(count2< length2){
        tail = insertAtTail(tail, j); 
        j = j->next;    
        count2++;               
    }

    return head; 
}
