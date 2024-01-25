void  insertAtTail(Node * &head, Node* &tail, int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode; 
            tail = newNode; 
        }
        else{
            tail->child = newNode; 
            tail = newNode; 
        }
        
}

void printList(Node* head){
	Node* temp = head; 
	while(temp!=NULL){
		cout<<temp->data<<" "; 
		temp = temp->child; 
	}cout<<endl;
}


Node* merge(Node*  left, Node* right){

    Node* tail = NULL;
    Node* head = NULL; 

    if(left == NULL){
        return right; 
    }

    if(right == NULL){
        return left; 
    }

    while(left!=NULL && right!=NULL){
        if(left->data < right->data){
            insertAtTail(head, tail, left->data);
            left = left->child; 
        }
        else{
            insertAtTail(head, tail, right->data);
            right = right->child; 
        }
    }

    while(left != NULL){
      insertAtTail(head, tail, left->data);
      left = left->child;   
    }

    while(right != NULL){
        insertAtTail(head, tail, right->data);
        right = right->child;   
    }

    return head; 
}



Node* flattenLinkedList(Node* head) 
{

	if(head->next == NULL){
		return head; 
	}


	Node *down = head; 
	Node* right = head->next;
	down->next = NULL; 
	right = flattenLinkedList(right);

	return merge(down, right); 
}
