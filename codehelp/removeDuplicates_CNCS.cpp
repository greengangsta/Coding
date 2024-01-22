Node * removeDuplicates(Node *head)

{
     Node* curr = head; 
     while(curr!=NULL ){

       if (curr->next != NULL && curr->next->data == curr->data) {

             Node* temp = curr->next;
             if(temp->next!=NULL) 
             temp->next->prev= curr; 
             curr->next = temp->next; 
             delete(temp);
        }

         else {
             curr = curr->next; 
         }
     }
     return head;
    // Write your code here
}
