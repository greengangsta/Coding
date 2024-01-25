node*  findMid(node*  head){
    node*  slow = head;
    node*  fast = head->next;

    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next; 
        slow = slow->next; 
    }

    return slow; 
}

void  insertAtTail(node * &head, node* &tail, int val){
        node* newNode = new node(val);
        if(head == NULL){
            head = newNode; 
            tail = newNode; 
        }
        else{
            tail->next = newNode; 
            tail = newNode; 
        }
        
}


void printList(node* head){
    node* temp = head; 
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next; 
    }cout<<endl;
}

node* merge(node*  left, node* right){

    node* tail = NULL;
    node* head = NULL; 


    if(left == NULL){
        return right; 
    }

    if(right == NULL){
        return left; 
    }

    while(left!=NULL && right!=NULL){
        if(left->data < right->data){
            insertAtTail(head, tail, left->data);
            left = left->next; 
        }
        else{
            insertAtTail(head, tail, right->data);
            right = right->next; 
        }
    }

    while(left != NULL){
      insertAtTail(head, tail, left->data);
      left = left->next;   
    }

    while(right != NULL){
        insertAtTail(head, tail, right->data);
        right = right->next;   
    }


    return head; 
}



node* mergeSort(node *head) {
    // Write your code here.

    if(head == NULL || head->next == NULL){
        return head; 
    }

    node* mid = findMid(head); 
    node* rightPart = NULL;
    if(mid!=NULL){
        rightPart = mid->next; 
        mid->next= NULL;
    }

    node* leftPart = head; 


    leftPart = mergeSort(leftPart); 

    rightPart = mergeSort(rightPart);


    return merge(leftPart, rightPart);

}
