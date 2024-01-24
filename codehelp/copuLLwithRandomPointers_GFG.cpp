        Node *copyList(Node *head)
    {
        //Write your code here
        
        //create a clone List; 
        Node* newHead = NULL; 
        Node* tail = NULL; 
        Node* temp = head; 
        while(temp!=NULL){
            insertAtTail(newHead, tail, temp->data); 
            temp = temp->next; 
        }
        
        Node * currentOriginal = head; 
        Node* currentClone = newHead; 
        
        while(currentClone != NULL && currentOriginal !=NULL){
            Node* tempOriginal = currentOriginal->next; 
            Node* tempClone = currentClone->next; 
            
            currentOriginal->next = currentClone; 
            currentOriginal = tempOriginal; 
            
            currentClone->next = tempOriginal; 
            currentClone = tempClone; 
            
        }

        
        currentOriginal = head; 
        while(currentOriginal!= NULL){
            if(currentOriginal->arb!=NULL) 
            currentOriginal->next->arb = currentOriginal->arb->next; 
            currentOriginal = currentOriginal->next->next; 
        }
        
        currentOriginal = head; 
        currentClone = newHead;
        
        while(currentClone != NULL && currentOriginal !=NULL && currentClone->next!=NULL){
            
            Node* tempOriginal = currentClone->next; 
            
            currentOriginal->next = tempOriginal; 
            currentOriginal = tempOriginal; 
            
            currentClone->next = tempOriginal->next; 
            currentClone = tempOriginal->next; 
            
        }
        
        currentOriginal->next = NULL;
        return newHead; 
    }


};
